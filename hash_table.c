#include<string.h>
unsigned long hash_function(char new_node->word[LENGTH + 1])
{
    do
    {
        int i = 0;
        unsigned long index += (new_node->word[i] - 65) % 26;
        i ++;
    }
    while (new_node->word[i] != '\n')
    return index;
}
