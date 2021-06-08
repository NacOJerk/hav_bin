#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void pwnme(const char *arg)
{
    int changeMe = 0xDEADBEEF;
    char buffer[20] = {0};
    strcpy(buffer, arg);
    if (changeMe != 0xDEADBEEF)
    {
        FILE* fptr = fopen("flag", "r");
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
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("You need to supply data\n");
    }
    pwnme(argv[1]);
    return 0;
}
