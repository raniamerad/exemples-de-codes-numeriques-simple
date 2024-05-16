#include <stdio.h>
#include <stdlib.h>

float compute(float *x, int n) {
  float res = 0.0f;
  for (int i=0; i < n; ++i) {
    res = res + x[i];

    // Comparisons
    if (res == 0.0f)
      res += 1.0f;
    if (res < x[i])
      res -= 1.0f;
    if (res <= x[i])
      res -= 1.0f;
    if (res > x[i])
      res -= 1.0f;
    if (res >= x[i])
      res -= 1.0f;
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
  printf("Result: %f\n", result);

  return 0;
}