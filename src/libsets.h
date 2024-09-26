/**
 * @file libsets.h
 * @author BusterDaemon (bugsbunnygdi@pm.me)
 * @brief Определения для работы со множествами
 * @details Содержит определения структуры и функций для работы со множествами и
 * их созданием
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Структура представляющая элемент множества
 * @author BusterDaemon
 *
 */
typedef struct Sets {
  int64_t num; /**< Значение элемента множества */
  struct Sets *next; /**< Ссылка на следующий элемент множества */
} Sets;

Sets *New(int64_t num);
Sets *NewEmpty(void);
void Push(Sets **tail, int64_t num);
void Pop(Sets **tail);
void PrintAll(Sets **tail);
int Size(Sets **tail);
int GetElem(Sets **tail, uint position);
int IsExist(Sets **tail, int64_t num);