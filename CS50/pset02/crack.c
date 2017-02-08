#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

void decrypt1(char hash[], char salt[]) {
    char * crypted, pass[2], a;
    pass[1] = '\0';
    
    for (a = 'a'; a < 'z' + 1; a++) {
        pass[0] = a;
        crypted = crypt(pass, salt);
        if(strcmp(crypted, hash) == 0) {
            printf("Password: %s\n", pass);
            exit(0);
        }
        
        pass[0] -= 0x20;
        crypted = crypt(pass, salt);
        if(strcmp(crypted, hash) == 0) {
            printf("Password: %s\n", pass);
            exit(0);
        }
    }
}

void decrypt2(char hash[], char salt[]) {
    char * crypted, pass[3], a ,b;
    pass[2] = '\0';
    
    for (a = 'a'; a < 'z' + 1; a++) {
        pass[0] = a;
        for (b = 'a'; b < 'z' + 1; b++) {
            pass[1] = b;
            crypted = crypt(pass, salt);
            if(strcmp(crypted, hash) == 0) {
                printf("Password: %s\n", pass);
                exit(0);
            }
            
            pass[1] -= 0x20;
            crypted = crypt(pass, salt);
            if(strcmp(crypted, hash) == 0) {
                printf("Password: %s\n", pass);
                exit(0);
            }
        }
        
        pass[0] -= 0x20;
        for (b = 'a'; b < 'z' + 1; b++) {
            pass[1] = b;
            crypted = crypt(pass, salt);
            if(strcmp(crypted, hash) == 0) {
                printf("Password: %s\n", pass);
                exit(0);
            }
            
            pass[1] -= 0x20;
            crypted = crypt(pass, salt);
            if(strcmp(crypted, hash) == 0) {
                printf("Password: %s\n", pass);
                exit(0);
            }
        }
    }
}

void decrypt3(char hash[], char salt[]) {
    char * crypted, pass[4], a, b, c;
    pass[3] = '\0';
    
    for (a = 'a'; a < 'z' + 1; a++) {
        pass[0] = a;
        for (b = 'a'; b < 'z' + 1; b++) {
            pass[1] = b;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
                
                pass[2] -= 0x20;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
            }
            
            pass[1] -= 0x20;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
                
                pass[2] -= 0x20;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
            }
        }
        
        pass[0] -= 0x20;
        for (b = 'a'; b < 'z' + 1; b++) {
            pass[1] = b;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
                
                pass[2] -= 0x20;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
            }
            
            pass[1] -= 0x20;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
                
                pass[2] -= 0x20;
                crypted = crypt(pass, salt);
                if(strcmp(crypted, hash) == 0) {
                    printf("Password: %s\n", pass);
                    exit(0);
                }
            }
        }
    }
}

void decrypt4(char hash[], char salt[]) {
    char * crypted, pass[5], a, b, c, d;
    pass[4] = '\0';
    
    for (a = 'a'; a < 'z' + 1; a++) {
        pass[0] = a;
        for (b = 'a'; b < 'z' + 1; b++) {
            pass[1] = b;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
                
                pass[2] -= 0x20;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
            }
            
            pass[1] -= 0x20;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
                
                pass[2] -= 0x20;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
            }
        }
        
        pass[0] -= 0x20;
        for (b = 'a'; b < 'z' + 1; b++) {
            pass[1] = b;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
                
                pass[2] -= 0x20;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
            }
            
            pass[1] -= 0x20;
            for (c = 'a'; c < 'z' + 1; c++) {
                pass[2] = c;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
                
                pass[2] -= 0x20;
                for (d = 'a'; d < 'z' + 1; d++) {
                    pass[3] = d;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                    
                    pass[3] -= 0x20;
                    crypted = crypt(pass, salt);
                    if(strcmp(crypted, hash) == 0) {
                        printf("Password: %s\n", pass);
                        exit(0);
                    }
                }
            }
        }
    }
}

int main(int argc, char * args[]) {
    if (argc != 2) exit(1);
    
    decrypt1(args[1], "50");
    decrypt2(args[1], "50");
    decrypt3(args[1], "50");
    decrypt4(args[1], "50");
    printf("Nothing found, sorry.\n");
    return 0;
}
