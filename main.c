#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "sort.h"
#include "fill.h"
#include "measurement.h"


#define P 3
#define M 8
#define N 8

void OutTable(float ordered, float random, float backordered, int alg)
{
    switch(alg){
        case 1:
            printf("%-20s", "Select 2");
        break;
        case 2:
            printf("%-20s","Select 4 Exchange");
        break;
        case 3:
            printf("%-20s", "Shell 1");
        break;
    }
    printf("%-10.2f%-10.2f%-10.2f \n",ordered, random, backordered);
}

void MeasurmentsArr3D(int alg)
{

    int ***Arr3D;
    Arr3D = (int***) malloc(P*sizeof(int**));
    for (int k=0; k<P; k++)
    {
        Arr3D[k] = (int**) malloc(M*sizeof(int*));
        for (int i=0; i<M; i++)
            Arr3D[k][i] = (int*) malloc(N*sizeof(int));
    }


    Arr3D_measurement(Arr3D, P, M, N, alg, 1);
    float ordered = MeasurementProcessing();

    Arr3D_measurement(Arr3D, P, M, N, alg, 2);
    float random = MeasurementProcessing();

    Arr3D_measurement(Arr3D, P, M, N, alg, 3);
    float backordered = MeasurementProcessing();
    OutTable(ordered, random, backordered, alg);


    for (int k=0; k<P; k++)
    {
        for (int i=0; i<M; i++)
            free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);
}

void MeasurmentsVector(int alg)
{
    int *vector;
    vector = (int*)malloc(sizeof(int)*N);


    vector_measurement(vector, N, alg, 1);
    float ordered = MeasurementProcessing();

    vector_measurement(vector, N, alg, 2);
    float random = MeasurementProcessing();

    vector_measurement(vector, N, alg, 3);
    float backordered = MeasurementProcessing();
    OutTable(ordered, random, backordered, alg);

    free(vector);

}


void Out_Arr3D(int ***Arr3D, int p, int m, int n){
    for(int k = 0; k < p; k++){
        printf("P = %d\n", k);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                printf("%4d", Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void tests(){
    int p = 3, m = 8, n = 8;
    int ***Arr3D;
    Arr3D = (int***) malloc(p*sizeof(int**));
    for (int k=0; k<p; k++)
    {
        Arr3D[k] = (int**) malloc(M*sizeof(int*));
        for (int i=0; i<m; i++)
            Arr3D[k][i] = (int*) malloc(m*sizeof(int));
    }

    printf("Select algorithm:\n");
    printf("1. Select 2\n");
    printf("2. Select 4 Exchange\n");
    printf("3. Shell 1\n");
    int a;
    scanf("%d", &a);
    system("cls");

    switch(a){
        case 1:
            printf("Select 2\n");
            for(int i = 1; i <= 3; i++){
                switch(i){
                    case 1:
                        printf("Ordered\n");
                    break;
                    case 2:
                        printf("Random\n");
                    break;
                    case 3:
                        printf("Backordered\n");
                    break;
                }
                fill_Arr3D(Arr3D, p, m, n, i);
                printf("Before sorting:\n");
                Out_Arr3D(Arr3D, p, m, n);
                Select2(Arr3D, p, m, n);
                printf("After sorting:\n");
                Out_Arr3D(Arr3D, p, m, n);

            }
        break;
        case 2:
            printf("Select 4 Exchange\n");
            for(int i = 1; i <= 3; i++){
                switch(i){
                    case 1:
                        printf("Ordered\n");
                    break;
                    case 2:
                        printf("Random\n");
                    break;
                    case 3:
                        printf("Backordered\n");
                    break;
                }
                fill_Arr3D(Arr3D, p, m, n, i);
                printf("Before sorting:\n");
                Out_Arr3D(Arr3D, p, m, n);
                Select4Exchange(Arr3D, p, m, n);
                printf("After sorting:\n");
                Out_Arr3D(Arr3D, p, m, n);
            }
        break;
        case 3:
            printf("Shell 1\n");
            for(int i = 1; i <= 3; i++){
                switch(i){
                    case 1:
                        printf("Ordered\n");
                    break;
                    case 2:
                        printf("Random\n");
                    break;
                    case 3:
                        printf("Backordered\n");
                    break;
                }
                fill_Arr3D(Arr3D, p, m, n, i);
                printf("Before sorting:\n");
                Out_Arr3D(Arr3D, p, m, n);
                Shell_1(Arr3D, p, m, n);
                printf("After sorting:\n");
                Out_Arr3D(Arr3D, p, m, n);
            }
        break;
    }

    for (int k=0; k<p; k++)
    {
        for (int i=0; i<m; i++)
            free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);


}

int main()
{
    srand(time(NULL));
    int f = 0;


    while(f != 1){
        system("cls");
        printf("1.Measurement table Arr3D\n");
        printf("2.Measurement table Vector\n");
        printf("3.Measurement algorithm Arr3D\n");
        printf("4.Tests\n");
        printf("5.Exit\n");
        int num;
        scanf("%d", &num);
        system("cls");

        switch(num){
            case 1:
                printf("P = %d\nM = %d\nN = %d\n", P ,M ,N);
                printf("%20s%-10s%-10s%10s \n","", "ordered", "random", "backordered");
                for(int i = 1; i <= 3; i++){
                    MeasurmentsArr3D(i);
                }
                getch();
            break;
            case 2:
                printf("N = %d\n", N);
                printf("%20s%-10s%-10s%10s \n","", "ordered", "random", "backordered");
                for(int i = 1; i <= 3; i++){
                    MeasurmentsVector(i);
                }
                getch();
            break;
            case 3:
                printf("Select algorithm:\n");
                printf("1. Select 2\n");
                printf("2. Select 4 Exchange\n");
                printf("3. Shell 1\n");
                int num;
                scanf("%d", &num);
                system("cls");
                printf("P = %d\nM = %d\nN = %d\n", P ,M ,N);
                printf("%20s%-10s%-10s%10s \n","", "ordered", "random", "backordered");
                MeasurmentsArr3D(num);
                getch();
            break;
            case 4:
                tests();
                getch();
            break;
            case 5:
                f = 1;
            break;
            default:

            break;

        }
    }
    return 0;

}
