#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

/** A slot in the table. */
typedef struct slot {
    int key;
    int value;
    bool empty;
} Slot;

/** An inner representation of a hash table. */
struct hashtable {
    Slot *slots;
    int size;
    int capacity;
};

/** The initial capacity of the table. */
#define INITIAL_CAPACITY 16

/**
 * The maximum load factor (i.e. the ratio size/capacity) of the table to allow
 * before resizing. This is just a number that works well empirically.
 */
#define MAX_LOAD_FACTOR 0.5

/** The "index" of a key that isn't in the table. */
#define MISSING_INDEX -1

/** Hashes an integer key. The hash is always non-negative. */
static inline unsigned int hash(int key);

/**
 * Returns a key's index in the table, or `MISSING_INDEX` if it doesn't exist.
 */
static int hashtable_find_index(HashTable table, int key);

/** Resizes the table to accommodate more items. */
static void hashtable_resize(HashTable table);

/////////////////////////////////////////////////////
// ^^^ DO NOT CHANGE ANYTHING ABOVE THIS LINE! ^^^ //
/////////////////////////////////////////////////////

void hashtable_insert(HashTable table, int key, int value) {
    if (table->size > table->capacity * MAX_LOAD_FACTOR) {
        hashtable_resize(table);
    }

    int index = hash(key) % table->capacity;
    while (!table->slots[index].empty && table->slots[index].key != key) {
        index = (index + 1) % table->capacity;
    }

    table->slots[index].key = key;
    table->slots[index].value = value;
    if (table->slots[index].empty) {
        table->slots[index].empty = false;
        table->size++;
    }
}

void hashtable_delete(HashTable table, int key) {
    int index = hashtable_find_index(table, key);
    if (index == MISSING_INDEX) {
        return;
    }

    table->slots[index].empty = true;
    table->size--;

    index = (index + 1) % table->capacity;
    while (!table->slots[index].empty) {
        table->slots[index].empty = true;
        table->size--;
        hashtable_insert(table, table->slots[index].key,
                         table->slots[index].value);
        index = (index + 1) % table->capacity;
    }
}

/////////////////////////////////////////////////////
// vvv DO NOT CHANGE ANYTHING BELOW THIS LINE! vvv //
/////////////////////////////////////////////////////

HashTable hashtable_new(void) {
    HashTable table = malloc(sizeof(*table));
    table->size = 0;
    table->capacity = INITIAL_CAPACITY;
    table->slots = malloc(table->capacity * sizeof(Slot));
    for (int i = 0; i < table->capacity; i++) {
        table->slots[i].empty = true;
    }
    return table;
}

void hashtable_free(HashTable table) {
    free(table->slots);
    free(table);
}

bool hashtable_contains(HashTable table, int key) {
    return hashtable_find_index(table, key) != MISSING_INDEX;
}

int hashtable_get(HashTable table, int key) {
    return table->slots[hashtable_find_index(table, key)].value;
}

int hashtable_get_or_default(HashTable table, int key, int default_value) {
    int index = hashtable_find_index(table, key);
    return (index != MISSING_INDEX) ? table->slots[index].value : default_value;
}

int hashtable_size(HashTable table) {
    return table->size;
}

static inline unsigned int hash(int key) {
    // This is what a hash function looks like in the real world: a complicated
    // sequence of operations that, magically, distributes keys well.
    const unsigned int magic = 0x45d9f3b;
    unsigned int h = 1U + INT_MAX;
    h += key;
    h = ((h >> 16) ^ h) * magic;
    h = ((h >> 16) ^ h) * magic;
    h = (h >> 16) ^ h;
    return h;
}

static int hashtable_find_index(HashTable table, int key) {
    int index = hash(key) % table->capacity;
    while (!table->slots[index].empty) {
        if (table->slots[index].key == key) {
            return index;
        }
        index = (index + 1) % table->capacity;
    }

    return MISSING_INDEX;
}

static void hashtable_resize(HashTable table) {
    // Save the old slots array ...
    int old_capacity = table->capacity;
    Slot *old_slots = malloc(old_capacity * sizeof(Slot));
    memcpy(old_slots, table->slots, old_capacity * sizeof(Slot));

    // ... double the capacity of the current slots array ...
    table->size = 0;
    table->capacity *= 2;
    table->slots = realloc(table->slots, table->capacity * sizeof(Slot));
    for (int i = 0; i < table->capacity; i++) {
        table->slots[i].empty = true;
    }

    // ... and now reinsert all key-value pairs.
    for (int i = 0; i < old_capacity; i++) {
        if (!old_slots[i].empty) {
            hashtable_insert(table, old_slots[i].key, old_slots[i].value);
        }
    }
    free(old_slots);
}
