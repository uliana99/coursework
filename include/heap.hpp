//  "Copyright [2017] <MGTU IU8-33>"
//  HEAP.HPP

/*!
    \file
    \brief heap_sort
    \details В данном заголовочном файле реализован шаблонный рекурсивный алгоритм неустойчивой сортировки HEAP.
    \author Кошкина Ульяна
    \date 21/12/2017
*/

#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <iostream>
#include <chrono>
#include "message.hpp"

/*!
Функция heapEngine.
Реализует рекурсивный алгоритм неустойчивой сортировки HEAP.

\param[in] arr[] - Массив, который необходимо отсортировать.
\param[in] size - Размер передаваемого массива.
\param[in] root - Корень разветвления.
\snippet heap.cpp heap_sort_example
*/

template <typename T>
void heapEngine(T arr[], int size, int root) {
    int largest = root;  // Корень
    int left = 2*root + 1;  // Левая ветка
    int right = 2*root + 2;  // Правая ветка

    // Если левое значение больше корня, переопределяем корень.
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // Если правое значение больше корня, переопределяем корень.
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // Если корень изменился.
    if (largest != root) {
        std::swap(arr[root], arr[largest]);

        // Рекурсивный вызов heapEngine для прохода в глубину дерева.
        heapEngine(arr, size, largest);
    }
}

/*!
Функция heap_sort.
Сортирует массив рекурсиным алгоритмом неустойчивой сортировки HEAP.

\param[in] arr[] - Массив, который необходимо отсортировать.
\param[in] size - Размер передаваемого массива.
*/

template <typename T>
void heap_sort(T arr[], int size) {

    // Первый проход по массиву
    // для ввывода в вершину максимального значения.
    for (int i = size / 2 - 1; i >= 0; i--)
        heapEngine(arr, size, i);

    // Сортируем массив один за одним исключая max.
    for (int i = size - 1; i >= 0; i--) {
        // Переносим максимум в конец сортируемого массива.
        std::swap(arr[0], arr[i]);

        // Вызываем алгоритм сортировки с уменьшением размера массива на 1.
        // [ 2, 6, 3, 1 ] (7) <- max
        heapEngine(arr, i, 0);
    }
}

#endif  // _HEAP_HPP_
