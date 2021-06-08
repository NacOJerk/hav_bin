#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell()
{
    FILE *fptr = fopen("flag", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    char c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n");
    exit(0);
}

void pwnme()
{
    char buffer[20] = {0};
    gets(buffer);
    printf("Hello %s\n", buffer);
}

int main(int argc, char **argv)
{
    pwnme();
    return 0;
}