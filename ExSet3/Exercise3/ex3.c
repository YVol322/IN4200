#include <stdio.h>
#include <time.h>
#include <math.h>


double power(double x, int y)
{
    double result = 1.0;

    for(int i = 0; i < y; i++)
    {
        result *= x;
    }

    return result;
}


int main()
{
    double x = 0.999;
    int y = 100;

    clock_t start_time = clock();

    double impl_res = power(x, y);

    clock_t end_time = clock();

    double elapsed_time_impl = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Implementation result: %.20f\n", impl_res);
    printf("Implementation elapsed time: %.1e seconds\n", elapsed_time_impl);
    printf("\n");

    clock_t start_time_pow = clock();

    double pow_res = pow(x,y);

    clock_t end_time_pow = clock();

    double elapsed_time_pow = ((double)(end_time_pow - start_time_pow)) / CLOCKS_PER_SEC;

    printf("Pow result: %.20f\n", pow_res);
    printf("Pow elapsed time: %.1e seconds\n", elapsed_time_pow);
    printf("\n");

    printf("Error: %.1e\n", pow_res - impl_res);
    printf("Time diff: %.1e\n", elapsed_time_pow - elapsed_time_impl);



    return 0;
}