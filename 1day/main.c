#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* returns the expected fuel for mass */
long calc(long mass)
{
  return (mass/3) - 2;
}

/* Calculates the mass recursively, negative 'demands' should be zero */
long calc_mass(long mass)
{
  long curr = calc(mass);
  if(mass <= 0)
  {
    return 0;
  }
  return curr + calc_mass(curr);
}


int main()
{
  char buffer [100];
  FILE *fp = fopen("./input.txt", "r");
  long mass = 0;
  long sum = 0;
  /* read line by line */
  while(fgets(buffer,100,fp) != NULL)
  {
    /* convert to long format */
    mass = atol(buffer);

    sum += calc_mass(mass);
  } 
  printf("result: %ld\n", sum);
  return 0;
}
