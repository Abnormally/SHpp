#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quit(int reason) {
    switch(reason) {
        case 1:
            printf("Program usage:\n./vigenere [code_string]\n");
            exit(reason);
        case 2:
            printf("Code string must contain only alphabetical characters\n");
            exit(1);
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

bool in_big_range(int ch) {
    return !(ch < 'A' || ch > 'Z');
}

bool in_small_range(int ch) {
    return !(ch < 'a' || ch > 'z');
}

int check_key(char * key) {
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        if (!in_big_range(key[i]) && !in_small_range(key[i])) quit(2);
        if (in_big_range(key[i])) key[i] += 0x20;
        key[i] -= 'a';
    }
    
    return i;
}

int main(int argc, char ** args) {
    if (argc == 1 || argc > 2) quit(1);
    int len = check_key(args[1]);
    
    char line[200]; int l, i, j, temp;
    printf("plaintext: ");
    l = read(line);
    
    for (i = 0, j = 0; line[i] != '\0'; i++) {
        if (j == len) j = 0;
        
        if (in_big_range(line[i])) {
            temp = line[i] + args[1][j];
            if (!in_big_range(temp)) temp -= 26;
            line[i] = temp;
            
            j++;
        }
        
        if (in_small_range(line[i])) {
            temp = line[i] + args[1][j];
            if (!in_small_range(temp)) temp -= 26;
            line[i] = temp;
            
            j++;
        }
    }
    
    printf("ciphertext: %s\n", line);
    return 0;
}
