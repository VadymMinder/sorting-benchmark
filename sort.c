#include "sort.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

clock_t Select2(int ***A, int P, int M, int N){
    int imin;

    int buf;

    clock_t time_start, time_stop;
    time_start = clock();
    for(int k = 0; k < P; k++)
        for(int s = 0; s < N-1; s++){
             imin = s;
             for(int i=s+1; i < N; i++){
                if (A[k][0][i] < A[k][0][imin])
                    imin=i;
             }

                for(int j = 0; j < M; j++){
                    buf = A[k][j][imin];
                    A[k][j][imin] = A[k][j][s];
                    A[k][j][s] = buf;
                }
        }

     time_stop = clock();
     return time_stop - time_start;
}

clock_t Select4Exchange(int ***A, int P, int M, int N){
    int L, R;

    int Min, Max;

    clock_t time_start, time_stop;
    time_start = clock();
    for(int k = 0; k < P; k++){
        L=0; R=N-1;
        while (L<R){
            for(int i=L; i<R+1; i++){
                if (A[k][0][i] < A[k][0][L]){
                    for(int j = 0; j < M; j++){
                        Min = A[k][j][i];
                        A[k][j][i] = A[k][j][L];
                        A[k][j][L] = Min;
                    }
                }
                else if(A[k][0][i] > A[k][0][R]){

                    for(int j = 0; j < M; j++){
                        Max = A[k][j][i];
                        A[k][j][i] = A[k][j][R];
                        A[k][j][R] = Max;
                    }
                }
            }
            L=L+1; R=R-1;
        }
    }

    time_stop = clock();
    return time_stop - time_start;
}

clock_t Shell_1(int ***A, int P, int M, int N)
{
    int t, j, k;
    clock_t time_start, time_stop;
    int *Elem;
    Elem = (int*)malloc(sizeof(int)*M);

    time_start = clock();

    if (N<4) t=1;
    else t=(int)log2f((float)N)-1;

    int Stages[t];
    Stages[t-1]=1;
    for (int i=t-2; i>=0; i--)
    Stages[i]=2*Stages[i+1]+1;

    for(int l = 0; l < P; l++){
        for (int p=0; p<t; p++){
            k=Stages[p];
            for (int i=k; i<N; i++){
                for(int y = 0; y < M; y++){
                    Elem[y] = A[l][y][i];
                }
                j=i;
                while (j>=k && Elem[0]<A[l][0][j-k]) {
                    for(int y = 0; y < M; y++){
                        A[l][y][j]=A[l][y][j-k];
                    }
                    j=j-k;
                }
                for(int y = 0; y < M; y++){
                    A[l][y][j] = Elem[y];
                }
            }
        }
    }
    time_stop = clock();
    free(Elem);
    return time_stop - time_start;
}

clock_t Select2_vector(int *A, int N)
{
    int imin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int s=0; s<N-1; s++){
        imin=s;
        for(int i=s+1; i<N; i++)
            if (A[i]<A[imin]) imin=i;

        tmp=A[imin];
        A[imin]=A[s];
        A[s]=tmp;
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Select4Exchange_vector(int *A, int N)
{
    int Min, Max;
    int L, R;
    clock_t time_start, time_stop;
    time_start = clock();
    L=0; R=N-1;
    while (L<R){
        for(int i=L; i<R+1; i++){
            if (A[i] < A[L]){
                Min=A[i];
                A[i]=A[L];
                A[L]=Min;
            }
            else
            if (A[i] > A[R]){
                Max=A[i];
                A[i]=A[R];
                A[R]=Max;
            }
        }
        L=L+1; R=R-1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t Shell_1_vector(int *A, int N)
{
    int Elem, t, j, k;
    clock_t time_start, time_stop;
    time_start = clock();
    if (N<4) t=1;
    else t=(int)log2f((float)N)-1;

    int Stages[t];
    Stages[t-1]=1;
    for (int i=t-2; i>=0; i--)
    Stages[i]=2*Stages[i+1]+1;
    for (int p=0; p<t; p++){
        k=Stages[p];
        for (int i=k; i<N; i++){
            Elem=A[i];
            j=i;
            while (j>=k && Elem<A[j-k]) {
                A[j]=A[j-k];
                j=j-k;
            }
            A[j]=Elem;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}






