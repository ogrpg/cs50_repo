#include<cs50.h>
#include<stdio.h>

int main(void)
{
    //recieving the hiegth of the tower
    
    printf("How tall would you like your Mario tower?\n");
    
    int h;
    
    
       //determining the validity of the request
       
            {
                do
                    {
                    printf("please enter a hieght between 0 and 23!\n");
                    h = GetInt();
                    }
                while (h < 0 || h > 23);
            } 
      
       //building the tower
       //level loop
       
       {
       
       for (int l = 0; l < h; l++)
       
       {
           //spaces loop
           for(int s = h; s > (l + 1); s--)
           
           {
               printf(" ");
           }
            
           //hashes loop
           for(int hash = 0; hash < (l + 2); hash++)
           
           {
               printf("#");
           }
           
       //starts next level and ends program when appropriate
       printf("\n");
       }   
   }
   }
