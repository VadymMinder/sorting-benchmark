#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED


#include <time.h>

clock_t Select2(int ***A, int P, int M, int N);
clock_t Select4Exchange(int ***A, int P, int M, int N);
clock_t Shell_1(int ***A, int P, int M, int N);

clock_t Select2_vector(int *A, int N);
clock_t Select4Exchange_vector(int *A, int N);
clock_t Shell_1_vector(int *A, int N);
#endif // SORT_H_INCLUDED
