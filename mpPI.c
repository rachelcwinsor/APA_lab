#include <omp.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])

{
	omp_set_num_threads(8);
	int n = 10000; //steps
	double PI25DT = 3.141592653589793238462643;
	double h = 1.0 / (double) n;
	double sum = 0.0;
	#pragma omp parallel
	{
		double d, pPi;
		int ID = omp_get_thread_num();
		for(int i=ID+1; i<=n; i+=8){
			d = ((double)(i)-0.5)/(double)n;
			pPi += (4.0 / (1.0 + d*d)); 
		}
		#pragma omp atomic
		sum+=pPi;
	}

	double pi = sum * h;
	printf("The approximate value of PI is %le, with an error of %le",pi,fabs(pi - PI25DT));  
	return 0;
}



