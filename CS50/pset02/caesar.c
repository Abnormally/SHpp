#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quit(int reason) {
    switch(reason) {
        case 1:
            printf("Program usage:\n./caesar [n]\nn - non negative value\n");
            exit(reason);
        case 2:
            printf("Somthing going wrong with youre value.\n");
            exit(reason);
        default:
            exit(reason);
    }
}

int read(char line[]) { // Да, я в курсе про scanf("%s", string), где char string[некоторый_размер]
    char x; int i;
    
    for (i = 0;;i++) {
        x = getchar();
        if (x == EOF || x == '\n') break;
        line[i] = x;
    }
    
    line[i] = '\0';
    return i;
}

void parse_int(int * x, char * string) { // Да, я в курсе про atoi
    int i, m;
    
    if (string[0] == '-') {
        m = -1;
        i = 1;
    } else {
        m = 1;
        i = 0;
    }
    
    for (; string[i] != '\0'; i++) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != '\0') quit(2);
        *x = (*x) * 10 + (string[i] - 0x30);
    }
    
    *x = (*x) * m;
}

bool in_big_range(int ch) {
    return !(ch < 'A' || ch > 'Z');
}

bool in_small_range(int ch) {
    return !(ch < 'a' || ch > 'z');
}

int main(int argc, char * args[]) {
    int shift;
    if (argc == 1 || argc > 2) quit(1);
    parse_int(&shift, args[1]);
    if (shift < 0) quit(1);
    shift %= 26;
    
    char line[200]; int l, i, temp;
    printf("plaintext: ");
    l = read(line);
    
    for (i = 0; i < l; i++) {
        if (in_big_range(line[i])) {
            temp = line[i] + shift;
            if (!in_big_range(temp)) temp -= 26;
            line[i] = temp;
        }
        
        if (in_small_range(line[i])) {
            temp = line[i] + shift;
            if (!in_small_range(temp)) temp -= 26;
            line[i] = temp;
        }
    }
    
    printf("ciphertext: %s\n", line);
    return 0;
}
