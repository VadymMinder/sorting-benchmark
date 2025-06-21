#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED

#define measurements_number 28

#define rejected_number 2

#define min_max_number 3

#include <time.h>

extern clock_t Res[measurements_number];

float MeasurementProcessing();

void Arr3D_measurement(int ***Arr3D, int P, int M, int N, int alg, int fill);
void vector_measurement(int *vector, int N, int alg ,int fill);

#endif // MEASUREMENT_H_INCLUDED
