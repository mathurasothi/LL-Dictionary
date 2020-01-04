#include "dictionary.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

struct llnode {
  int key;
  int value;
  struct llnode *next;
};

struct dictionary {
  struct llnode *first_entry;
  int size;
};

struct dictionary *dictionary_create(void) {
  struct dictionary *dict = malloc(sizeof(struct dictionary));
  dict->first_entry = NULL;
  dict->size = 0;
  return dict;
}


void free_nodes(struct llnode *node) {
  if (node) {
    free_nodes(node->next);
    free(node);
  }
}


void dictionary_destroy(struct dictionary *d) {
  assert(d);
  free_nodes(d->first_entry);
  free(d);
}


int dictionary_size(const struct dictionary *d) {
  assert(d);
  return d->size;
/*  int len = 0;
  struct llnode *node = d->first_entry;
  while (node) {
    ++len;
    node = node->next;
  }
  return len;*/
}


void dictionary_add(struct dictionary *d, int key, int value) {
  assert(d);
  assert(value != INT_MIN);
  if (d->first_entry == NULL || key < d->first_entry->key) {
    struct llnode *newnode = malloc(sizeof(struct llnode));
    newnode->key = key;
    newnode->value = value;
    newnode->next = d->first_entry;
    d->first_entry = newnode;
    ++d->size;
    return;
  }

  struct llnode *prevnode = d->first_entry;
  while (prevnode->next && key > prevnode->next->key) {
    prevnode = prevnode->next;
  }
  
  if (key == prevnode->key) {
    prevnode->value = value;
    return;
  }
  
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->key = key;
  newnode->value = value;
  newnode->next = prevnode->next;
  prevnode->next = newnode;  
  ++d->size;
}


void dictionary_remove(struct dictionary *d, int key) {
  assert(d);
  if (d->first_entry == NULL) return;
  if (d->first_entry->key == key) {
    struct llnode *node = d->first_entry;
    d->first_entry = d->first_entry->next;
    free(node);
    --d->size;
    return;
  }
  struct llnode *prevnode = d->first_entry;
  while (prevnode->next && key != prevnode->next->key) {
    prevnode = prevnode->next;
  }
  if (prevnode->next == NULL) return;
  struct llnode *backup = prevnode->next;
  prevnode->next = prevnode->next->next;
  free(backup);
  --d->size;
}


int dictionary_lookup(struct dictionary *d, int key) {
  assert(d);
  struct llnode *prevnode = d->first_entry;
  while (prevnode) {
    if (prevnode->key == key) {
      return prevnode->value;
    }
    prevnode = prevnode->next;
  }
  return INT_MIN;
}


void dictionary_print(struct dictionary *d) {
  assert(d);
  struct llnode *prevnode = d->first_entry;
  while (prevnode) {
    printf("(%d, %d)\n", prevnode->key, prevnode->value);
    prevnode = prevnode->next;
  }
}








