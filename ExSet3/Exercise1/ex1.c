#include <stdio.h>
#include <math.h>


double numerical_integration (double x_min, double x_max, int slices)
{
    double delta_x = (x_max-x_min)/slices;
    double x, sum = 0.0;

    for (int i=0; i<slices; i++) 
    {
        x = x_min + (i+0.5)*delta_x;
        sum = sum + 4.0/(1.0+x*x);
    }
    
    return sum*delta_x;
}


int main()
{
    double x_min = 0.0;
    double x_max = 1.0;

    int n_slices = 1;

    for(int i = 1; i < 6; i++)
    {
        double res = numerical_integration(x_min, x_max, n_slices);

        printf("number of slices: %d\n", n_slices);
        printf("integral value: %.10f\n", res);
        printf("error: %.1e\n", M_PI - res);



        n_slices *= 10;
    }


    return 0;
}