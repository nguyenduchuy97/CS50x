// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain hash value
    unsigned int index = hash(word);

    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Compare the word with the current node's word (case-insensitive)
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char buffer[LENGTH + 1];

    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    // Initialize the table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Read each word in the file
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(new->word, buffer);
        new->next = NULL;

        // Hash the word to obtain the hash value
        unsigned int index = hash(buffer);

        // Insert node into the hash table
        new->next = table[index];
        table[index] = new;
    }

    // Close the dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *cursor = table[i]; cursor != NULL; cursor = cursor->next)
        {
            size++;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
