#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

 int main()
{
    char fname[MAX];
    char sent1[MAX];
    char sent;
    FILE *fptr;
    int num,i=0;

    printf("Input file name to be edited: ");
    fgets(fname,MAX,stdin);
    fname[strlen(fname)-1]='\0';
    fptr=fopen(fname,"a");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1)
    }

    printf("Input the number of lines to be written: ");
    scanf("%d",&num);

    printf("\nInput %d sentence(s) for the file:\n\n",num);
    for(i=0;i<num+1;i++)
    {
        fgets(sent1,sizeof(sent1),stdin);
        fputs(sent1,fptr);
    }
    fclose(fptr);

    fptr=fopen(fname,"r");
    sent=fgetc(fptr);
    printf("\nThe content of the file %s is:\n\n",fname);
    while(sent!=EOF)
    {
        printf("%c",sent);
        sent=fgetc(fptr);
    }
    fclose(fptr);
    printf("\n");
    return 0;
}

