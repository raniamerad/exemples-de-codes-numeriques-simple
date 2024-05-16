#include <stdio.h>
#include <stdlib.h>

float compute(float *x, int n) {
  float sum = 0.0;
  float sumsq = 0.0;
  float var;

  for (int i=0; i < n; ++i) {
    sum = sum + x[i];
    sumsq = sumsq + x[i]*x[i];
  }
  var = (sumsq-(sum*sum)/n)/(n-1);
  return var;
}

int main(int argc, char **argv)
{
  int n = 8000;
  int nbytes = n*sizeof(float); 
  float *data = (float *)malloc(nbytes);
  for (int i=0; i < n; ++i)
    data[i] = (float)(rand());
  printf("Calling kernel\n");
  float result = compute(data, n);
  printf("Result: %f\n", result);

  return 0;
}