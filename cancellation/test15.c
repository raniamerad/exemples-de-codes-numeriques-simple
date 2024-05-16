
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float compute(float *x, int n) {
  float res = 0.0;
  for (int i=0; i < n; ++i) {
    //res = res + x[i];

    // Cancellation
    float tmp = x[i] - (x[i]+0.0000000001);
    res += tmp;
  }
  return res;
}

int main(int argc, char **argv)
{
  int n = 8;
  int nbytes = n*sizeof(float); 
  float *data = (float *)malloc(nbytes);
  for (int i=0; i < n; ++i)
    data[i] = (float)(pow(2,-i*2));
  printf("Calling kernel\n");
  float result = compute(data, n);
  printf("Result: %f\n", result);

  return 0;
}