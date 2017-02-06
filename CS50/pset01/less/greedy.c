#include <stdio.h>
#include <math.h>
 
int read(char word[]) {
    char x; int i;
 
    for (i = 0;;i++) {
        x = getchar();
        if (x == EOF || x == ' ' || x == '\n') break;
        word[i] = x;
    }
 
    return i;
}
 
float get_float();
 
float retry() {
    printf("Retry: ");
    return get_float();
}
 
float get_float() {
    char word[50]; int i, len, m, crounter = 10;
    float result = 0; int flag = 1;
 
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
        if (word[i] == '.' && flag) {
            flag = 0;
            continue;
        } else if (word[i] == '.' && !flag) return retry();
 
        if (word[i] < '0' || word[i] > '9') return retry();
        if (flag) result = result * 10 + (word[i] - 0x30);
        else {
            result = result + ((float) (word[i] - 0x30)) / crounter;
            crounter *= 10;
        }
    }
 
    return result * m;
}
 
int money, coins;
 
void recoin(int coin) {
    coins += money / coin;
    money %= coin;
}
 
int main(void) {
    float income;
 
    printf("O hai! ");
 
    do {
        printf("How much change is owed?\n");
        income = get_float();
    } while (income < 0);
 
    money = (int) round(income * 100);
 
    recoin(25);
    recoin(10);
    recoin(5);
    recoin(1);
 
    printf("%d\n", coins);
}
