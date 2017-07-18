#include <stdio.h>
#include <stdlib.h>

 int main()
{
    char sent[1000];
    FILE *fptr;
    char fname[20]="test.txt";

    printf("\n\nCreate a file (test.txt) and input text: \n");
    printf("---------------------------------------------\n");
    fptr=fopen(fname,"w");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    printf("Input a sentence for the file: ");
    fgets(sent,sizeof(sent),stdin);
    fprintf(fptr,"%s",sent);
    fclose(fptr);
    printf("\nThe file %s created successfully...!!\n\n",fname);
    return 0;
}
