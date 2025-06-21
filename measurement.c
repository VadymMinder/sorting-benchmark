#include "measurement.h"

#include "fill.h"
#include "sort.h"

#include <time.h>
#include <stdio.h>
clock_t Res[measurements_number];

float MeasurementProcessing()
{
    long int Sum;
    float AverageValue;

    clock_t buf;
	int L = rejected_number, R = measurements_number - 1;
	int k = rejected_number;
	for (int j=0; j < min_max_number; j++) {
		for (int i = L; i < R; i++)	{
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
		R = k;
		for (int i = R - 1; i >= L; i--) {
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
		L = k + 1;
	}

    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
       Sum = Sum + Res[i];

    AverageValue = (float)Sum/(float)(measurements_number - 2*min_max_number - rejected_number);
    return AverageValue;
}

void Arr3D_measurement(int ***Arr3D, int P, int M, int N, int alg, int fill)
{
    switch(alg)
    {
    case 1:
        {
            for (int i = 0; i < measurements_number; i++)
            {
                fill_Arr3D(Arr3D, P, M, N, fill);
                Res[i] = Select2(Arr3D, P, M, N);
            }
        }
        break;
    case 2:
        {
            for (int i = 0; i < measurements_number; i++)
            {
                fill_Arr3D(Arr3D, P, M, N, fill);
                Res[i] = Select4Exchange(Arr3D, P, M, N);

            }
        }
        break;
    case 3:
        {
            for (int i = 0; i < measurements_number; i++)
            {
                fill_Arr3D(Arr3D, P, M, N, fill);
                Res[i] = Shell_1(Arr3D, P, M, N);

            }
        }
        break;
    }
}

void vector_measurement(int *vector, int N, int alg ,int fill)
{
    switch(alg)
    {
    case 1:
        {
            for (int i = 0; i < measurements_number; i++)
            {
                fill_vector(vector, N, fill);
                Res[i] = Select2_vector(vector, N);
            }
        }
        break;
    case 2:
        {
            for (int i = 0; i < measurements_number; i++)
            {
                fill_vector(vector, N, fill);
                Res[i] = Select4Exchange_vector(vector, N);

            }
        }
        break;
    case 3:
        {
            for (int i = 0; i < measurements_number; i++)
            {
                fill_vector(vector, N, fill);
                Res[i] = Shell_1_vector(vector, N);

            }
        }
        break;
    }
}

