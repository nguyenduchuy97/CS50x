// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Count
int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor;
    cursor = table[index];

    while(cursor->next != 'NULL')
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char buffer[LENGTH +  1];
    int index;

    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
    {
        return false;
    }

    // Read each word in the file
    while(fscanf(file, "%s", buffer) != 'EOF')
    {
        node *new = malloc(sizeof(node));
        if (new == 'NULL')
        {
            return false;
        }

        strcpy(new->word, buffer);
        new->next = 'NULL';
        index = hash(buffer);
        new->next = table[index];
        table[index] = new;
        count++;
    }

    // Close the dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp;

        while(cursor->next != 'NULL')
        {
            tmp = cursor;
            cursor = tmp->next;
            free(tmp);
        }
    }
    return true;
}
