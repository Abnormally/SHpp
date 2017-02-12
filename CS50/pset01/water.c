#include <stdio.h>
 
int read(char word[]) {
    char x; int i;
 
    for (i = 0;;i++) {
        x = getchar();
        if (x == EOF || x == ' ' || x == '\n') break;
        word[i] = x;
    }
 
    return i;
}
 
int get_int();
 
int retry() {
    printf("Retry: ");
    return get_int();
}
 
int get_int() { // Вместо get_int из cs50.h
    char word[50]; int len, i, result = 0;
    len = read(word);
 
    if (len == 0) return retry();
 
    for (i = 0; i < len; i++) {
        if (word[i] < '0' || word[i] > '9') return retry();
        result = result * 10 + (word[i] - 0x30);
    }
 
    return result;
}
 
int main(void) {
    printf("minutes: ");
    printf("bottles: %i\n", (get_int() * 12));
}
