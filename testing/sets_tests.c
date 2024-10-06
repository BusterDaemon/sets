#include "../src/libsets.h"
#include "./sets_tests_core.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  SetElem *A = NewEmpty();
  SetElem *B = NewEmpty();
  int varik = 0;

  while (1) {
    puts("Действия:");
    puts("1. Добавить элемент в множество\n"
         "2. Убрать элемент из множества\n"
         "3. Вывести множество\n"
         "4. Провести операцию над множествами\n"
         "5. Выйти из программы\n");
    fscanf(stdin, "%d", &varik);
    if (varik == 5) {
      break;
    }

    switch (varik) {
    case 1:
      menuPush(&A, &B);
      break;
    case 2:
      menuPop(&A, &B);
      break;
    case 3:
      menuPrintSet(A, B);
      break;
    case 4:
      menuOper(A, B);
      break;
    }

    varik = 0;
  }
  return 0;
}