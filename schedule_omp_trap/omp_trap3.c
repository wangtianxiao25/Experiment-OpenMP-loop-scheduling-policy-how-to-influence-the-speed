#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double f(double x) {
    return sin(x);
}

double trap_parallel(double a, double b, int n, int thread_nums, int* iterations) {
    double h = (b - a) / n;
    double sum = 0.0;
    int i;
    sum += 0.5 * f(a);
    sum += 0.5 * f(b);
#   pragma omp parallel for num_threads(thread_nums) \
        schedule(runtime) reduction(+:sum)
    for (i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
        iterations[i] = omp_get_thread_num();
    }

    return sum * h;
}


// usage: ./omp_trap3 <the number of threads> <the amount of segment>
int main(int argc, char* argv[]) {
    int thread_nums = strtol(argv[1], NULL, 10);
    double result;
    double a = 0.0, b = M_PI;
    int n = strtol(argv[2], NULL, 10);

    int* iterations = malloc(n * sizeof(int));
    if (iterations == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    double start = omp_get_wtime();
    result = trap_parallel(a, b, n, thread_nums, iterations);
    double end = omp_get_wtime();

    printf("runtime omp program:\ncost time: \t\t%.9fs\nthe amount of segment: \t%d\nresult: \t\t%lf\nThe number of threads: \t%d\n", end-start, n, result, thread_nums);

    printf("\nFirst 20 Iteration -> Thread:\n");
    int print_cnt = (n > 20) ? 20 : (n - 1);
    for (int i = 0; i < print_cnt; i++) {
        printf("Iter %d -> Thread %d\n", i, iterations[i]);
    }
    if (n > 20) printf("...(total %d iterations)\n", n);

    free(iterations);

    return 0;
}
