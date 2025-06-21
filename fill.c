#include "fill.h"

#include <stdlib.h>

void fill_Arr3D_ordered(int ***Arr3D, int P, int M, int N)
{
    int number=0;
    for (int k=0; k<P; k++)
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                Arr3D[k][i][j] = number++;
}

void fill_Arr3D_random(int ***Arr3D, int P, int M, int N)
{
    for (int k=0; k<P; k++)
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                Arr3D[k][i][j] = rand()%(P*M*N);
}

void fill_Arr3D_backordered(int ***Arr3D, int P, int M, int N)
{
    int number = P*M*N;
    for (int k=0; k<P; k++)
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                Arr3D[k][i][j] = number--;
}

void fill_vector_ordered(int *vector, int N){
    for(int i = 0; i < N; i++){
        vector[i] = i;
    }
}

void fill_vector_random(int *vector, int N){
    for(int i = 0; i < N; i++){
        vector[i] = rand() % N;
    }
}

void fill_vector_backordered(int *vector, int N){
    for(int i = 0; i < N; i++){
        vector[i] = N - i;
    }
}

void fill_Arr3D(int ***Arr3D, int P, int M, int N, int fill)
{
    switch(fill)
    {
    case 1:
        fill_Arr3D_ordered(Arr3D, P, M, N);
        break;
    case 2:
        fill_Arr3D_random(Arr3D, P, M, N);
        break;
    case 3:
        fill_Arr3D_backordered(Arr3D, P, M, N);
        break;
    }
}

void fill_vector(int *vector, int N, int fill)
{
    switch(fill)
    {
    case 1:
        fill_vector_ordered(vector, N);
        break;
    case 2:
        fill_vector_random(vector, N);
        break;
    case 3:
        fill_vector_backordered(vector, N);
        break;
    }
}
