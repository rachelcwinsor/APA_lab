#include <math.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])

{
  clock_t start = clock();
    int n = 10000; //steps
    double PI25DT = 3.141592653589793238462643;
    double h = 1.0 / (double) n;
    double sum = 0.0;


    for (int i = 1; i <= n; i++) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x*x));
    }

    double pi = sum * h;
    printf("The approximate value of PI is %le, with an error of %le\n",pi,fabs(pi - PI25DT));  
    clock_t end = clock();
    double ts = (double)(end-start)/CLOCKS_PER_SEC;
    printf("time = %le\n",ts);
    return 0;
}



