#include "./sets_tests_core.h"
#include "../src/libsets.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void menuPush(SetElem **A, SetElem **B) {
  int varik = 0;
  int64_t data = 0;
  while (1) {
    puts("Введите элемент для вставки");
    fscanf(stdin, "%d", &data);

    puts("В какое множетсво добавить элемент\n"
         "1. A\n"
         "2. B");
    fscanf(stdin, "%d", &varik);

    if (varik == 1) {
      Push(A, data);
      break;
    } else if (varik == 2) {
      Push(B, data);
      break;
    }
  }
}

void menuPop(SetElem **A, SetElem **B) {
  int varik = 0;
  while (1) {
    puts("Из какого множетсва убрать элемент\n"
         "1. A\n"
         "2. B");
    fscanf(stdin, "%d", &varik);

    if (varik == 1) {
      Pop(A);
      break;
    } else if (varik == 2) {
      Pop(B);
      break;
    }
  }
}

void menuPrintSet(SetElem *A, SetElem *B) {
  int varik = 0;
  while (1) {
    puts("Какое множетсво отобразить\n"
         "1. A\n"
         "2. B");
    fscanf(stdin, "%d", &varik);

    if (varik == 1) {
      PrintAll(&A);
      break;
    } else if (varik == 2) {
      PrintAll(&B);
      break;
    }
  }
}

void menuOper(SetElem *A, SetElem *B) {
  int varik = 0;
  SetElem *C = NULL, *Selected = NULL;
  int min = 0, max = 0;
  int sel = 0;

  while (1) {
    puts("Выберите опреацию для проведения\n"
         "1. Объединение\n"
         "2. Разность\n"
         "3. Симметричная разность\n"
         "4. Пересечение\n"
         "5. Дополнение\n"
         "6. Выйти обратно\n");
    fscanf(stdin, "%d", &varik);

    if (varik == 6) {
      break;
    }

    C = (SetElem *)malloc(sizeof(SetElem));

    switch (varik) {
    case 1:
      C = Union(&A, &B);
      break;
    case 2:
      C = Difference(&A, &B);
      break;
    case 3:
      C = SymmetricDifference(&A, &B);
      break;
    case 4:
      C = Intersection(&A, &B);
      break;
    case 5:
      puts("Выберите множество:\n"
           "1. A\n"
           "2. B\n");
      fscanf(stdin, "%d", &sel);
      switch (sel) {
      case 1:
        Selected = A;
        break;
      case 2:
        Selected = B;
        break;
      default:
        Selected = A;
      }

      puts("Введите минимум");
      fscanf(stdin, "%d", &min);
      puts("Введите максимум");
      fscanf(stdin, "%d", &max);

      C = Complement(&Selected, min, max);

      break;
    }

    PrintAll(&C);

    free(C);
  }
}