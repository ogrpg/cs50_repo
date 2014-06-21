#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
//declaring outside the loop

    double cash = 0.00;
    
//verifying the input
    
    do    
      {
        printf("please give me a dollar value to convert to change.: $");
        cash = GetDouble();
      }
     while (cash <= 0); 

//declaring variables for coins, remaining cash, remainder, quarters, dimes, nickels, pennies, and coin-counter 
     
      int coins = floor (cash * 100.0);
      
      int rcash = coins;
      
      int r = 1;
      
      int q = 0;
      
      int d = 0;
      
      int n = 0;
      
      int p = 0;
      
      int c = 0;
//breaking the amount down in decending orders of magnitude by change      
     do
     {
//quarters loop     
         while (rcash >= 25)
         {
         q++;
         rcash = (rcash - 25);
         r = coins % (q * 25);
         c++;         
         }
//dimes loop         
         while (rcash >= 10)
         {
          d++;
         rcash = (rcash - 10);
         r = coins % ((q * 25) + (d * 10));        
         c++;
         }
//nickels loop         
         while (rcash >= 5)
         {
         n++;
         rcash = (rcash - 5);
         r = coins % ((q * 25) + (d * 10) + (n * 5));         
         c++;
         }
//pennies loop         
         while (rcash >= 1)
         {
         p++;
         rcash = (rcash - 1);
         r = coins % ((q * 25) + (d * 10) + (n * 5) + p);         
         c++;
         }
     }
//checks for remainder     
     while (r > 0);
     
//gives the user the amount of coins     
     printf("%d\n", c);
  
}
