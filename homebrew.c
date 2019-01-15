/* CS 153 PROGRAM ASSIGNMENT #8

Homebrew functions for exp(), double mylog(),
math pow(), and a test main method for each function.

Mark Schuberth 
 
11/10/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* only used for testing */

/* function that computes e^x */
double myexp(double x)
{
 /* j is used as a loop variable */
 int j;
 /* sum and term start at 1.0 */
 double sum = 1.0;
 double term = 1.0;
  
 /* main loop that calculates e^x */
 /* as long as j is greater than 0 */
 for(j = 25; j > 0; j--) 
 {
  /* sum variable calculates x^1/1! up to */
  /* entered x value */
  sum = term + (x * sum / j); 
 }
 
 return sum;
}

/* function calculates ln(y) */
double mylog(double y)
{
 double x = (y - 1)/(y + 1);
 double sum = x, term = x;
 /* used for power */
 double j = 3;
 
 /* sums terms up to x^1200/1200 */
 while(j < 1200)
 {
  /* adds 2 to the power */
  j += 2;
  
  /* starts at term^3 */
  term = (term * x * x);
  
  /* calcs term + term^3 to start */
  sum = sum + (term / j);
 }
 
 /* finishes calc sum by multiplying by 2 */
 sum = sum * 2;
 
 /* if y is <= 0.0 return 0 */
 if(y <= 0.0)
 {
  sum = 0;
 }
 
 return sum;
}

/* calculates power using previous terms */
double mypow(double x, double p)
{
 double result, k, answer;
    
 k = mylog(x);
 result = p * k;
 answer = myexp(result);
    
 return answer;
}

int main()
{
 double x, p;
   
 /* prompts user for x value */
 printf("enter the power of e: ");
 scanf("%lf", &x);
 
 /* prompts user for p value */
 printf("enter a value for p: ");
 scanf("%lf", &p);
 
 /* prints result of myexp() and real answer */
 printf("Actual e^x: %0.3lf\n", exp(x));
 printf("My e^x: %0.3lf\n", myexp(x));

 /* prints result of mylog() and real answer */
 printf("Actual log(x): %0.3lf\n", log(x));
 printf("My log(x): %0.3lf\n", mylog(x));

 /* prints result of mypow() and real answer */
 printf("Actual pow(x,p): %0.3lf\n", pow(x,p));
 printf("My pow(x,p): %0.3lf\n", mypow(x,p));
 
 return 0;
}