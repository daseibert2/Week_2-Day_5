#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

 int main()
{
    char fname[MAX];
    char sent;
    char newfile[MAX];
    FILE *fptr,*fptr1;

    printf("Input file name to be copied: ");
    scanf("%s",&fname);

    printf("Input new file name: ");
    scanf("%s",&newfile);

    fptr=fopen(fname,"r");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }

    fptr1=fopen(newfile,"w");

    if(fptr1==NULL)
    {
        printf("Error in opening new file!");
        exit(0);
    }

    while(1)
    {
        sent=fgetc(fptr);
        if(sent==EOF)
        {
            break;
        }
        else
        {
            fputc(sent, fptr1);
        }
    }
    fclose(fptr);
    fclose(fptr1);
    fptr=fopen(newfile,"r");
    sent=fgetc(fptr);
    printf("\nThe content of the file %s is:\n\n",newfile);
    while(sent!=EOF)
    {
        printf("%c",sent);
        sent=fgetc(fptr);
    }
    fclose(fptr);

    return 0;
}
