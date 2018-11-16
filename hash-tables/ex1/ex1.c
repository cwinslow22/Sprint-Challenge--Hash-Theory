#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));

  // YOUR CODE HERE
  for (int i = 0; i < length; i++) {
    hash_table_insert(ht, weights[i], i)
  }

  for (int i = 0; i < length; i++) {
    if (hash_table_retrieve(limit - weights[i]) != -1) {
      if (weights[i] > (limit - weights[i])) {
        
      }
    }
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}