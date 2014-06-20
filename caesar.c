#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<cs50.h>

//declaring that int main will recieve arguments at the command line
int main(int argc, string argv[])

{

//declaring the key
   // int k = atoi(argv[1]);

//verifying the command line argument
    if (argc != 2)
    
//loops for innappropriate #of arguments and invallid keys    
    {
    printf("please enter only a non-negative int for your key at the command line after ./ceaser!\n");
    return 1;
    }
    
    else if (atoi(argv[1]) <= -1)
    {
    printf("please enter only a non-negative int for your key at the command line after ./ceaser!\n");
    return 1;
    }
    
    //declaring the key
    int k = atoi(argv[1]);

//getting the text to be encoded    
    //printf("Please enter your plain text to be encoded:\n");
    string p = GetString();

//main loop that cycles per character in the string
    for (int i = 0, psl = strlen(p); i < psl; i++)
   
    {
    
//declaring int pt (plain text) for use later    
    int pt;
    
//uppercase character loop    
     if (isupper(p[i]))
        {
            pt = (p[i]);
            printf("%c", ((((pt - 65) + k) % 26) + 65));
        }

//lowercase character loop              
     else if (islower(p[i]))
        {
             pt = (p[i]);
             printf("%c", ((((pt - 97) + k) % 26) + 97));
        }
     
//all other characters        
     else
        {
            printf("%c", p[i]);
        }       
        
    }
//to return cursor to new line    
    printf("\n");
    
//to end the program    
    return 0;
} 
