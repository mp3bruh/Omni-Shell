#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(remove(*(argv+1)) == -1){
        perror("Fehler");
        exit(EXIT_FAILURE);
    }
    printf("%s wurde erfolgreich gelöscht!\n", *(argv+1));w

}


