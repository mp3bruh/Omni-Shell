#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(mkdir(*(argv+1),0755) == -1){      // 0755 -> eigentümer alle rechte, rest: lesen/ausführen
        perror("Fehler");
        exit(EXIT_FAILURE);
    }else{
        printf("%s wurde erfolgreich erstellt!\n", *(argv + 1));
    }

}
