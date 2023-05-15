#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>



#define NULL ( (void *) 0)


char *ReadLine(){

    int i = 0, size_buffer = 1024, c;
    char *buffer = ((char*) malloc(sizeof(char) * size_buffer));

    while(1){
        c = getchar();  //if c -1 == endoffile

        if(c == '\n'||c == -1){
            buffer[i] = '\0';
            return buffer;
        }else{
            buffer[i] = c;
        }

        i++;

        if(i >= size_buffer){
            size_buffer += size_buffer;
            buffer = realloc(buffer, size_buffer);

            if(!buffer){                                      //if buffer == 0
                perror("Fehler!");
                exit(EXIT_FAILURE);
            }
        }
    }
}



//Teile line in tokens auf
char **SplitLine(char *line){

    int index = 0, size_buffer = 64;
    char *token;
    char **tokens = ((char**) malloc(sizeof(char) * size_buffer));
    token = strtok(line, " ");

    while(token != NULL){
        tokens[index] = token;
        index++;

        if(index >= size_buffer){
            size_buffer += size_buffer;
            tokens = realloc(tokens, size_buffer);

            if(!tokens){
                perror("The following error occured: ");
                exit(EXIT_FAILURE);
            }

        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[index] = NULL;
    return tokens;
}

int startprocess(char **args){

    pid_t pid;
    char befehl[100];

    //Ordner, worin sich die Befehle befinden.
    strcpy(befehl,"/home/mp3bruh/Vorlagen/CLionProjects/Shell_1.2");
    strcat(befehl,"/");
    strcat(befehl,args[0]);


    if(strcmp(args[0], "exit") == 0){
        return NULL;
    }

    else{
        pid = fork(); // Kind wird erstellt
        if(pid == 0){

            if(strcmp("cd",args[0]) == 0) {

                if(chdir(args[1]) == -1) {
                    perror("Fehler!\n");
                    return EXIT_FAILURE;
                }
            }

            else if(execvp(befehl,args) == -1){
                printf("\n'%s' nicht gefunden!\n",args[0]);
            }
        }

        else if(pid < 0){
            printf("%s konnte nicht ausgeführt werden!\n",args[0]);
            exit(EXIT_FAILURE);
        }
        else{
            waitpid(-1, NULL, 0);
        }
        return 1;
    }
}


int main(int argc, char *argv[]){

    char *line;
    char **arguments;
    int status;

    do{
        printf("λ ");
        line = ReadLine();
        arguments = SplitLine(line);
        status = startprocess(arguments);
        free(line);
        free(arguments);
    } while(status);
}