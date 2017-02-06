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
 
int get_int() {
    char word[50]; int len, i, result = 0, m;
    len = read(word);
 
    if (len == 0) return retry();
 
    if (word[0] == '-') {
        m = -1;
        i = 1;
    } else {
        m = 1;
        i = 0;
    }
 
    for (; i < len; i++) {
        if (word[i] < '0' || word[i] > '9') return retry();
        result = result * 10 + (word[i] - 0x30);
    }
 
    return result * m;
}
 
int main(void) {
    int height;
 
    do {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);
 
    int counter = height - 1;
 
    for (int i = 0; i < height; i++, counter--) {
        for (int j = 0; j < counter; j++) printf(" ");
        for (int j = 0; j < i + 1; j++) printf("#");
        printf("  ");
        for (int j = 0; j < i + 1; j++) printf("#");
        printf("\n");
    }
 
    return 0;
}
