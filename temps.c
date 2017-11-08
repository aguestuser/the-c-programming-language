# include <stdio.h>

/**
 * print Farenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 **/

int main()
{
  int fahr, celsius, lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}