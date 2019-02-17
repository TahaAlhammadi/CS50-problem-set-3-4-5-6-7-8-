// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 1000000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N] = {NULL};

// create hash function
unsigned long long hash(const char *word)
{
    unsigned long long hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = tolower(word[i]) - 'a' + 1;

        // comma case
        else
            n = 27;
        unsigned long long x = 3;
        hash = ((hash << x) + n) % N;
    }
    return hash;
}
// create global variable to count size
int dictionary_size = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];


    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        dictionary_size ++;
        node *n = malloc(sizeof(node));
        if (!n)
        {
            unload();
            return false;
        }
        int bucket_number = hash(word);
        strcpy( n -> word, word);
        if (hashtable[bucket_number] == NULL)
        {
            hashtable[bucket_number] = n;
            n -> next = NULL ;
        }
        else
        {
            n -> next = hashtable[bucket_number] -> next;
            hashtable[bucket_number] -> next = n;
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (dictionary_size > 0)
    {
        return dictionary_size;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char temp[LENGTH + 1];  // make sure the word to check in lowercase
    int k = strlen(word);
    for(int i = 0; i < k; i++)
        temp[i] = tolower(word[i]);
    temp[k] = '\0';

    int bucket_number = hash(word);  // find the bucket the word belonged to
    if (hashtable[bucket_number] == NULL)
    {
        return false;
    }

    node *traversal = hashtable[bucket_number];
    while (traversal != NULL)
    {
        if (strcmp(temp, traversal -> word) == 0)
        {
            return true;
        }
        traversal = traversal -> next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i != N; i++)
    {
        node *head = hashtable[i];
        node *cursor = head;
        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor -> next ;
            free(temp);
        }
    }
    // TODO
    return true;

}