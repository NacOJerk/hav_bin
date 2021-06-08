#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pwnme()
{
    int res = rand();
    int guess = 0;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    if (guess == res)
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
    }
    else
    {
        printf("Wrong Guess, better luck next time\n");
    }
}

int main(int argc, char **argv)
{
    pwnme();
    return 0;
}