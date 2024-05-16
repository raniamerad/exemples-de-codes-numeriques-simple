// code trouver sur fpchecker dossier open mp
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#if defined(_OPENMP)

#endif

double compute(double *x, int n) {
  double res = 0.0;

#if defined(_OPENMP)
  omp_set_num_threads(4);
#endif

#pragma omp parallel
  {

#if defined(_OPENMP)
  int num = omp_get_thread_num();
  printf("Thread num: %d\n", num);
#endif

  for (int i=0; i < n; ++i) {
    res = res + x[i];

    // NaN
    res = res / (res-res);
  }
  }
  return res;
}

int main(int argc, char **argv)
{
  int n = 8;
  int nbytes = n*sizeof(double); 
  double *data = (double *)malloc(nbytes);
  for (int i=0; i < n; ++i)
    data[i] = (double)(i+1);
  printf("Calling kernel\n");
  double result = compute(data, n);
  printf("Result: %f\n", result);

  return 0;
}


// resultat NaN 