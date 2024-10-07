/**
 * @file libsets.h
 * @author BusterDaemon (bugsbunnygdi@pm.me)
 * @brief Определения для работы со множествами
 * @details Содержит определения структуры и функций для работы со множествами и
 * их созданием
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright GNU Public License
 *
 */

#include <stdint.h>
#include <sys/types.h>

#define _EMPTY_SET_MESSAGE "Set is empty"
#define _ALLOCATE_SET_ERR "Cannot allocate memory"

/**
 * @brief Структура представляющая элемент множества
 * @author BusterDaemon
 *
 */
typedef struct Sets {
  int64_t num; /**< Значение элемента множества */
  struct Sets *next; /**< Ссылка на следующий элемент множества */
} Sets;

<<<<<<< docs
Sets *New(int64_t num);
Sets *NewEmpty(void);
Sets *Union(Sets **setA, Sets **setB);
Sets *Difference(Sets **setA, Sets **setB);
Sets *SymmetricDifference(Sets **setA, Sets **setB);
Sets *Intersection(Sets **setA, Sets **setB);
Sets *Complement(Sets **setA, int64_t min, int64_t max);
void Push(Sets **tail, int64_t num);
void Pop(Sets **tail);
void PrintAll(Sets **tail);
int Size(Sets **tail);
int GetElem(Sets **tail, int position);
int IsExist(Sets **tail, int64_t num);
=======
SetElem *New(int64_t num);
SetElem *NewEmpty(void);
SetElem *Union(SetElem **setA, SetElem **setB);
SetElem *Difference(SetElem **setA, SetElem **setB);
SetElem *SymmetricDifference(SetElem **setA, SetElem **setB);
SetElem *Intersection(SetElem **setA, SetElem **setB);
SetElem *Complement(SetElem **setA, int64_t min, int64_t max);
void Push(SetElem **tail, int64_t num);
void Pop(SetElem **tail);
void PrintAll(SetElem **tail);
int Size(SetElem **tail);
int GetElem(SetElem **tail, int position);
int IsExist(SetElem **tail, int64_t num);
int64_t PowerSetSize(SetElem **tail);
>>>>>>> local
