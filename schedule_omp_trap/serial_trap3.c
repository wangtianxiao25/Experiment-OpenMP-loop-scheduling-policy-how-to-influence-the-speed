#include <math.h>
#include <stdio.h>

double f(double x) {
    return sin(x);
}


double trap_serial(double a, double b, int n) {
    // a: begin point
    // b: end point
    // n: the num of segment
    double h = (b - a) / n; // little segment
    double sum = 0.0;       // sum initial

    sum += 0.5 * f(a);
    sum += 0.5 * f(b);

    for (int i = 1; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
    }

    return sum * h;
}

int main() {
    double a = 0.0, b = M_PI;
    int n = 16;
    double result = trap_serial(a, b, n);
    printf("Serial trap result = %.9f\n", result);
    return 0;
}