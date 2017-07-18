#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 128
#define RSIZ 10

 int main()
{
    char fname[20];
    char sent1;
    FILE *fptr;
    int word=0;
    int chars=0;

    printf("Input file name to be read: ");
    scanf("%s",&fname);
    fptr=fopen(fname,"r");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    sent1=fgetc(fptr);
    printf("\nThe content of the file %s is:\n\n",fname);
    while(sent1!=EOF)
    {
        printf("%c",sent1);
        if(sent1==' '||sent1=='\n')
        {
            word++;
        }
        else
        {
            chars++;
        }
        sent1=fgetc(fptr);
    }
    fclose(fptr);
    printf("\nThe number of words in the file %s is: %d\n\n",fname,word);
    printf("The number of characters in the file %s is: %d\n",fname,chars);
    return 0;
}
