#include <stdio.h>
#include <stdlib.h>

char* getStringInput() 
{
    char *input = malloc(1); ///Allocation of the space for the '\0' charactere
    char c = ' ';
    int length = 1;
    while((c = fgetc(stdin)) != '\n') ///while user don't press enter which is the end of an input
    {
        length++;
        char *tmpInput = realloc(input, length);
        if(tmpInput == NULL) 
        {
            free(input);
            return NULL;
        }
        input = tmpInput;
        input[length-2] = c;
        input[length-1] = '\0';
    }
    return input;
}

int main(int argc, char const *argv[])
{
    char *input = NULL;
    if((input = getStringInput()) == NULL)
        goto error;

    printf("%s", input);

error:
    free(input);
    return 0;
}
