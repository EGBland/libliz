#include <hashtable.h>
#include <arraylist.h>

// helper functions
void ht_put(HashTable *ht, char *key, ListValue *value);

void ht_put(HashTable *ht, char *key, ListValue *value) {
    
}

// header implementations
unsigned long hash(char *str) {
    //djb2 http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;

    while(c = *str++)
        hash = ((hash << 5) + hash) ^ c;
    
    return hash;
}

void ht_init(HashTable *ht, unsigned int no_buckets) {
    ht->no_buckets = no_buckets;
    ArrayList *buckets = (ArrayList *)malloc(no_buckets * sizeof(ArrayList));
    for(unsigned int i = 0; i < no_buckets; i++)
        al_init(buckets+i);
    ht->buckets = buckets;
}

void ht_putc(HashTable *ht, char *key, char value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addc(ht->buckets+bucketIndex, value);
}

void ht_putcu(HashTable *ht, char *key, unsigned char value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addcu(ht->buckets+bucketIndex, value);
}

void ht_puts(HashTable *ht, char *key, short value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_adds(ht->buckets+bucketIndex, value);
}

void ht_putsu(HashTable *ht, char *key, unsigned short value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addsu(ht->buckets+bucketIndex, value);
}

void ht_puti(HashTable *ht, char *key, int value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addi(ht->buckets+bucketIndex, value);
}

void ht_putiu(HashTable *ht, char *key, unsigned int value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addiu(ht->buckets+bucketIndex, value);
}

void ht_putl(HashTable *ht, char *key, long value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addl(ht->buckets+bucketIndex, value);
}

void ht_putlu(HashTable *ht, char *key, unsigned long value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addlu(ht->buckets+bucketIndex, value);
}

void ht_putptr(HashTable *ht, char *key, void *value) {
    unsigned long keyHash = hash(key);
    unsigned int bucketIndex = keyHash % ht->no_buckets;
    al_addptr(ht->buckets+bucketIndex, value);
}