#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    struct dirent **namelist;
    int n = scandir(".", &namelist, NULL, alphasort);

    if(n == -1){
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    while(n--){
        printf("%s\n", namelist[n]->d_name);
        free(namelist[n]);
    }

    printf("\n");
    free(namelist);
    exit(EXIT_SUCCESS);
}