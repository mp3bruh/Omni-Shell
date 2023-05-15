#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int c;
    FILE *file = NULL;
    file = fopen(*(argv+1),"r");

    if(file) {
        while ((c = getc(file))!= EOF){
            printf("%c",c);
        }
        fclose(file);
        printf("\n");
    }
    else{
        perror("Fehler");
        exit(EXIT_FAILURE);
    }
}
