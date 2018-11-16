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
    hash_table_insert(ht, weights[i], i);
  }

  for (int i = 0; i < length; i++) {
    if (hash_table_retrieve(ht, limit - weights[i]) != -1) {
      if (weights[i] < (limit - weights[i])) {
        answer->index_1 = hash_table_retrieve(ht, weights[i]);
        answer->index_2 = hash_table_retrieve(ht, limit - weights[i]);
      } else {
        answer->index_2 = hash_table_retrieve(ht, weights[i]);
        answer->index_1 = hash_table_retrieve(ht, limit - weights[i]);
      }
      return answer;
    }
  }
  printf("%d %d\n", answer->index_1, answer->index_2);
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

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  printf("%d %d\n", answer_4->index_1, answer_4->index_2);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}\n");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}\n");

  return 0;
}
#endif