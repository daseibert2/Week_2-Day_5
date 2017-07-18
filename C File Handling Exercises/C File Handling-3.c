#include <stdio.h>
#include <stdlib.h>

 int main()
{

    char sent[100];
    char sent1;
    int i,num;
    FILE *fptr;
    char fname[20]="writing.txt";

    printf("\n\nCreate a file (%s) and input text: \n",fname);
    printf("---------------------------------------------\n\n");
    fptr=fopen(fname,"w");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    printf("Input the number of lines to be written: ");
    scanf("%d",&num);

    printf("\nInput %d sentence(s) for the file:\n\n",num);
    for(i=0;i<num+1;i++)
    {
        fgets(sent,sizeof(sent),stdin);
        fprintf(fptr,"%s",sent);
    }
    fclose(fptr);
    printf("\nThe content of the file %s is:\n",fname);
    fptr=fopen(fname,"r");
    sent1=fgetc(fptr);
    while(sent1!=EOF)
    {
        printf("%c",sent1);
        sent1=fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}

