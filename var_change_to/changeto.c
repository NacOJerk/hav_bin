#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pwnme()
{
    int changeMe = 0xDEADBEEF;
    char buffer[20] = {0};
    gets(buffer);
    if (changeMe == 0xCAFEBABE)
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
    printf("Better luck next time\n");
    printf("changeMe = 0x%08X\n", changeMe);
}

int main(int argc, char **argv)
{
    pwnme();
    return 0;
}