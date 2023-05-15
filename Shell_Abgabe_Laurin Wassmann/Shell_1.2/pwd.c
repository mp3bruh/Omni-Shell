#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char pwd[256];

    printf("%s\n",getcwd(pwd,sizeof(pwd)));
}