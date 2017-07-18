#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

 int main()
{
    char fname[MAX];
    char sent;
    FILE *fptr,*fptr1;

    printf("Input file name to be encrypted: ");
    scanf("%s",&fname);

    fptr=fopen(fname,"r");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    fptr1=fopen("temp.txt","w");
    if(fptr1==NULL)
    {
        printf("Error in temporary file!");
        exit(2);
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
            sent=sent+100;
            fputc(sent,fptr1);
        }
    }
    fclose(fptr);
    fclose(fptr1);

    fptr=fopen(fname,"w");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    fptr1=fopen("temp.txt","r");
    if(fptr1==NULL)
    {
        printf("Error in temporary file!");
        exit(2);
    }
    while(1)
    {
        sent=fgetc(fptr1);
        if(sent==EOF)
        {
            break;
        }
        else
        {

            fputc(sent,fptr);
        }
    }
    fclose(fptr);
    fclose(fptr1);

    fptr=fopen(fname,"r");
    sent=fgetc(fptr);
    printf("\nThe content of the file %s is:\n\n",fname);
    while(sent!=EOF)
    {
        printf("%c",sent);
        sent=fgetc(fptr);
    }
    fclose(fptr);

    return 0;
}
