#ifndef __HASHTABLE_H_DEFINED
#define __HASHTABLE_H_DEFINED 1

#include <arraylist.h>

unsigned long hash(char *);

typedef struct HashTable {
    ArrayList *buckets;
    unsigned int no_buckets;
} HashTable;

void ht_init(HashTable *ht, unsigned int no_buckets);
void ht_putc(HashTable *ht, char *key, char value);
void ht_putcu(HashTable *ht, char *key, unsigned char value);
void ht_puts(HashTable *ht, char *key, short value);
void ht_putsu(HashTable *ht, char *key, unsigned short value);
void ht_puti(HashTable *ht, char *key, int value);
void ht_putiu(HashTable *ht, char *key, unsigned int value);
void ht_putl(HashTable *ht, char *key, long value);
void ht_putlu(HashTable *ht, char *key, unsigned long value);
void ht_putptr(HashTable *ht, char *key, void *value);

#endif