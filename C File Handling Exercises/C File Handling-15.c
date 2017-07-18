#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fname[20];
    FILE *fptr;
    int deleted;

    printf("Input name of file to delete: ");
    scanf("%s",&fname);
    deleted=remove(fname);
    if(deleted==0)
    {
        printf("\n%s was successfully deleted!",fname);
    }
    else
    {
        printf("\nUnable to delete %s",fname);
    }

    return 0;
}
