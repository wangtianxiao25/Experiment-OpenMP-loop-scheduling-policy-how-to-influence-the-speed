#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(int i) {
    int j, start = i * (i + 1) / 2, finish = start + i;
    double return_val = 0.0;
    for (j = start; j <= finish; j++) {
        return_val += sin(j);
    }
    return return_val;
}

// usage: ./dynamic_omp_sin_sum <the number of threads> <the amount of data>
int main(int argc, char* argv[]) {
    int threads_num = strtol(argv[1], NULL, 10);
    int n, i;
    n = strtol(argv[2], NULL, 10);
    double start_time, end_time;

    start_time = omp_get_wtime();

#   pragma omp parallel for num_threads(threads_num)\
        schedule(dynamic)
    for (int i = 0; i < n; i++) {
        f(i);
    }

    end_time = omp_get_wtime();

    printf("dynamic omp program:\ncost time: \t\t%.9fs\nthe amount of data: \t%d\n", end_time-start_time, n);
    return 0;
}