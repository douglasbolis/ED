#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "list.h"

char* lowercase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

int main(int argc, char *argv[]) {
    char word[] = "TO BE CONVERTED";
    printf("%s\n", lowercase(word));
    
    return 0;
}

/*
 * 
 */
/*
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}
*/