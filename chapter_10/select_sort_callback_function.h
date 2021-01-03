#ifndef SELECT_SORT_CALLBACK_FUNCTION_H
#define SELECT_SORT_CALLBACK_FUNCTION_H

using validate_function = bool (*)(int, int);
bool ascending(int a, int b);
bool descending(int a, int b);
bool evenfirst(int a, int b);
void printArray(int *array, int size);
void select_sort(int *arr, const int length, validate_function ptr_fun=ascending);

#endif