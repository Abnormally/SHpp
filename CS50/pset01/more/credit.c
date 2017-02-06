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
 
int parser(char a) {
    int b = a - 0x30;
    // printf("Char: %c, int: %d\n", a, b);
    if (b < 0 || b > 9) {
        return -1;
    } else return b;
}
 
int double_sum(int a) {
    int temp = a * 2;
 
    int temp1 = (temp % 10) + (temp / 10);
    // printf("Temp:%d. Else temp:%d.\n", temp, temp1);
 
    if (temp < 10) return temp;
    else return temp1;
    // else return (temp % 10) + (temp / 10);
}
 
int is_ok(int all[], int len) {
    int odd = 0, even = 0;
    for (int i = 0; i < len; i += 2) odd += all[i];
    for (int i = 1; i < len; i += 2) even += double_sum(all[i]);
 
    // printf("Odd: %d. Even: %d. Summ: %d.\n", odd, even, odd + even);
 
    if (all[0] == 3 || (all[0] == 5 && all[1] == 5) || (all[0] == 4 && all[1] == 2)) {
        if ((odd + even) % 10 == 0) return 1;
        else return 0;
    } else if (all[0] == 4) {
        if ((odd + even) % 10 == 7) return 1;
        else return 0;
    } else if (all[0] == 5 && all[1] == 1) {
        if ((odd + even) % 10 == 5) return 1;
        else return 0;
    } else return 0;
}
 
int check(char card[], int len, char init) {
    // printf("%s %d %c\n", card, size, init);
 
    int all[20];
    for (int i = 0; card[i]; i++) all[i] = parser(card[i]);
    // AMEX ------------------------------------
    if (init == '3') {
        if (is_ok(all, len) == 1) return 1;
        else return 0;
    // VISA ------------------------------------
    } else if (init == '4') {
        if (is_ok(all, len) == 1) return 2;
        else return 0;
    // MASTERCARD ------------------------------
    } else if (init == '5') {
        if (is_ok(all, len) == 1) return 3;
        else return 0;
    } else return 0;
}
 
int main() {
    char * result[] = {"INVALID\n", "AMEX\n", "VISA\n", "MASTERCARD\n"};
    char card[30]; int ok = 0, j; char init;
 
    do {
        if (ok == 0) {
            printf("Number: ");
            ok = 1;
        } else printf("Retry: ");
 
        read(card);
 
        for (j = 0; card[j]; j++) if (parser(card[j]) == -1) break;
        else ok = 2;
    } while (ok != 2);
 
    init = card[0];
    if (j > 12 && j < 17 && (init == '3' || init == '4' || init == '5')) printf("%s", result[check(card, j, init)]);
    else printf("%s", result[0]);
 
    return 0;
}
