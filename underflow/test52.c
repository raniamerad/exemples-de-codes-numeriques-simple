#include <stdio.h>
#include <stdlib.h>

float compute(float *x, int n) {
  float res = 0.0f;
  for (int i=0; i < n; ++i) {
    res = res + x[i];

    res = res * (1e-38f * 1e-5f); 
  }
  return res;
}

int main(int argc, char **argv)
{
  int n = 8;
  int nbytes = n*sizeof(float); 
  float *data = (float *)malloc(nbytes);
  for (int i=0; i < n; ++i)
    data[i] = (float)(i+1);
  printf("Calling kernel\n");
  float result = compute(data, n);
  printf("Result: %.12g\n", result);

  return 0;
}