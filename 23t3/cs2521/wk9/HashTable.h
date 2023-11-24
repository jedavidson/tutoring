/**
 * A hash table module that uses linear probing hashing for its collision
 * resolution strategy. It assumes integer keys and values.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/** A hash table. */
typedef struct hashtable *HashTable;

/** Creates an empty table. */
HashTable hashtable_new(void);

/** Frees all memory associated with the table. */
void hashtable_free(HashTable table);

/**
 * Inserts a key-value pair into the table. If it already exists, the existing
 * value is overwritten.
 */
void hashtable_insert(HashTable table, int key, int value);

/** deletes a key-value pair from the table, if it exists. */
void hashtable_delete(HashTable table, int key);

/** Returns true if a key exists in the table, and false otherwise. */
bool hashtable_contains(HashTable table, int key);

/**
 * Gets the value for a certain key in the table. This function fails if the key
 * does not exist, so this should be checked first using `hashtable_contains`.
 */
int hashtable_get(HashTable table, int key);

/**
 * Gets the value for a certain key in the table. If the key does not exist,
 * then the supplied default value is returned instead.
 */
int hashtable_get_or_default(HashTable table, int key, int default_value);

/** Returns the number of key-value pairs in the table. */
int hashtable_size(HashTable table);

#endif  // HASHTABLE_H
