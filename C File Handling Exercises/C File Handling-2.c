#include <stdio.h>
#include <stdlib.h>

 int main()
{
    FILE *fptr;
    char fname[20];
    char sent;

    printf("Input file name to be read:\n\n");
    scanf("%s",fname);
    fptr=fopen(fname,"r");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(0);
    }

    printf("\nThe content of the file %s is:\n\n",fname);
    sent=fgetc(fptr);
    while(sent!=EOF)
    {
        printf("%c",sent);
        sent=fgetc(fptr);
    }
    fclose(fptr);

    printf("\nThis is the content of the file %s.\n",fname);
    return 0;
}
