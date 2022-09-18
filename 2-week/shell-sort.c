/* shell-sort.c - Сортировка Шелла */

#include <stdio.h>
#include <stdlib.h>

static void shell_sort(int a[], int size) {
  int i, j; // видимо какие-то индексы
  int h = 1; // шаг?

  // что это такое? мы не знаем, что это такое
  // видимо заполнение шага, но оно явно неправильное
  do {
    h = h * 3 + 1;
  } while (h <= size);

  do {
    // судя по всему, сортируем последовательностью h / 3, h / 9 и т.д.
    h /= 3;
    for (i = h; i < size; i++) {
      int v = a[i];
      for (j = i; j >= h && a[j - h] > v; j -= h) {
        a[j] = a[j - h];
      }
      if (i != j) {
        a[j] = v;
      }
    }
  } while (h != 1);
}

int main(int argc, char *argv[]) {
  int *a;  // выделение памяти под массив
  int i;

  a = (int *)malloc((argc - 1) * sizeof(int)); // непосредственно сам массив
  for (i = 0; i < argc - 1; i++) {
    a[i] = atoi(argv[i + 1]); // заполнение самого массива
  }
  shell_sort(a, argc - 1); // непосредственно сортировка
  printf("Output: ");
  for (i = 0; i < argc - 1; i++) {
    printf("%d ", a[i]); // вывод всех элементов массива
  }
  printf("N\n"); // что-то выводится??? возможно тут ошибка
  free(a); // освобождение памяти
  return 0;
}
