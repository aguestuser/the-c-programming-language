# include <stdio.h>

/**
 * print Farenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 **/


int main()
{
  float fahr, celsius;
  int lower, upper, step;

  /* define bounds and step of table */
  lower = 0;
  upper = 300;
  step = 20;

  /* print header */
  printf("\nFahrenheit to Celsius:\n");
  printf("%4s | %6s\n", "fahr", "cels");
  printf("-------------\n");

  /* print rows */
  fahr = lower;
  while (fahr <= upper) {
    /* celsius = 5 * (fahr - 32) / 9; */
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%4.0f | %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
