#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

 int main()
{
    char fname[MAX];
    char sent;
    char sent1[MAX],temp[]="temp.txt";
    FILE *fptr,*fptr1;
    int linenum,ctr=0;

    printf("Input file name to be edited: ");
    scanf("%s",&fname);

    fptr=fopen(fname,"r");
    if(fptr==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    fptr1=fopen(temp,"w");
    if(fptr1==NULL)
    {
        printf("Error in opening temporary file!");
        exit(0);
    }
    printf("Input line number you want to remove: ");
    scanf("%d",&linenum);
    //linenum++;
    while (!feof(fptr))
    {
        strcpy(sent1, "\0");
        fgets(sent1, MAX, fptr);
        if (!feof(fptr))
        {
            ctr++; /* skip the line at given line number */
            if (ctr!=linenum)
            {
                fprintf(fptr1, "%s", sent1);
            }
        }
    }
    fclose(fptr);
    fclose(fptr1);
    remove(fname); // remove the original file
    rename(temp, fname); // rename the temporary file to original name
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
