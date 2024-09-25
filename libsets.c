#ifndef _LIBSETS_H
#define _LIBSETS_H
#include "libsets.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif

Sets *New(int64_t num) {
  Sets *set;
  if ((set = (Sets *)malloc(sizeof(Sets))) == NULL) {
    perror("Cannot allocate memory");
    return NULL;
  }
  set->num = num;
  set->next = NULL;

  return set;
}

void Push(Sets **tail, int64_t num) {
  if (*tail == NULL) {
    *tail = New(num);
    return;
  }

  Sets *new = New(num);

  new->next = *tail;
  *tail = new;
}

void Pop(Sets **tail) {
  if (*tail == NULL) {
    perror("Set is empty");
    return;
  }

  Sets *current = *tail;
  Sets *prev = NULL;
  do {
    prev = current;
    current = current->next;
  } while (current->next != NULL);

  free(current);
  prev->next = NULL;
}

void PrintAll(Sets **tail) {
  if (*tail == NULL) {
    perror("Set is empty");
    return;
  }

  Sets *current = *tail;
  do {
    printf("%ld", current->num);
    current = current->next;
    if (current != NULL)
      printf(", ");
  } while (current != NULL);
  putc('\n', stdout);
}