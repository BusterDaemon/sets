#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Sets {
  int64_t num;
  struct Sets *next;
} Sets;

Sets *New(int64_t num);
void Push(Sets **tail, int64_t num);
void Pop(Sets **tail);
void PrintAll(Sets **tail);