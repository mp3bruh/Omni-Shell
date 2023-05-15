#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE* file;

    if((file = fopen(*(argv+1),"r")) != NULL){
        fclose(file);
        perror("Fehler");
        exit(EXIT_FAILURE);


    }
    file = fopen(*(argv+1),"w");
    fclose(file);
    printf("%s wurde erfolgreich erstell!\n", *(argv+1));

}