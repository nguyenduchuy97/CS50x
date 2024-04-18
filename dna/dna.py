import csv
import sys
import os


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3 or not all(sys.argv[1:]):
        print(f"Usage: {sys.argv[0]} csv_file_name text_file_name")
        return

    csv_file = sys.argv[1]
    text_file = sys.argv[2]

    """{} Check if files exist
    if os.path.isfile(csv_file) or os.path.isfile(text_file):
        print("One of both files do not exist.")
        return"""

    # TODO: Read database file into a variable
    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as dna:
        dna_sequence = dna.read()

    # TODO: Find longest match of each STR in DNA sequence
    longest_matches = {}
    for row in rows:
        for key, value in row.items():
            if key != "name":
                print(f"Here is the value {key}")
                longest_matches[key] = longest_match(dna_sequence, key)

    # TODO: Check database for matching profiles
    n = 0
    for i in range(len(rows)):
        for j in range(len(rows)):
            if num[j] != rows[i][lst[j]]:
                n += 1
        if n == len(rows):
            print(rows[i]["name"])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
