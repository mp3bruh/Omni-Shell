#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int c,i = 0;
    FILE *file = NULL;

    file = fopen(*(argv+1),"r");
    if(file != NULL) {
        while ((c = getc(file))!= EOF){
            i++;
        }
        fclose(file);
        printf("%s -> %d Wörter\n",*(argv+1), i);
    }else{
        perror("Fehler");
        fclose(file);
        exit(EXIT_FAILURE);

    }
}

