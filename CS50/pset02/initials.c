#include <stdio.h>
#include <ctype.h>

int read(char word[]) {
    char x; int i;
    
    for (i = 0;;i++) {
        x = getchar();
        if (x == EOF || x == '\n') break;
        word[i] = x;
    }
    
    return i;
}

void print_initials(char string[], int len) {
    if (isalpha(string[0]))
        printf("%c", toupper(string[0]));

    for (int i = 0; i < len; ++i) {
        if (string[i] == ' ') {
            if (isalpha(string[i+1])) {
                printf("%c", toupper(string[i+1]));
            }
        }
    }

    printf("\n");
}

int main(void) {
    char string[300]; int len;
    
    do {
        len = read(string);
    } while (len < 1);

    print_initials(string, len);
}
