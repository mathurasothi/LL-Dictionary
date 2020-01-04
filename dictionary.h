#include <stdbool.h>


struct dictionary;

// dictionary_create() returns a new empty dictionary
struct dictionary *dictionary_create(void);


// dictionary_destroy(d) frees all dynamically allocated memory 
void dictionary_destroy(struct dictionary *d);


// dictionary_size(d) returns the number of elements (key-value pairs) in d
int dictionary_size(const struct dictionary *d);


// dictionary_add(d, key, value) adds (key, value) to the dictionary d, if it does not already contain key, otherwise the currect value of this key is relplaced by value
void dictionary_add(struct dictionary *d, int key, int value);


// dictionary_remove(d, key) removes (key, *) from d.  if key is not in d, d isn't changed
void dictionary_remove(struct dictionary *d, int key);


// dictionary_lookup(d, key) returns the value associated with key in d.
int dictionary_lookup(struct dictionary *d, int key);


// dictionary_print(d) prints key value pairs in d
void dictionary_print(struct dictionary *d);
