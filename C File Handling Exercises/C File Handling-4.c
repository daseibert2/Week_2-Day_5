#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 128
#define RSIZ 10

 int main()
{
    char fname[20];
    char line[LSIZ][RSIZ];
    FILE *fptr=NULL;
    int i=0;
    int total=0;

    printf("Input file name to be read:\n\n");
    scanf("%s",&fname);
    fptr=fopen(fname,"r");

    while(fgets(line[i],LSIZ,fptr))
    {
        line[i][strlen(line[i])-1]='\0';
        i++;
    }
    total=i;
    printf("\nThe content of the file %s is:\n",fname);
    for(i=0;i<total;i++)
    {
        printf("%s\n",line[i]);
    }
    fclose(fptr);

    return 0;
}
