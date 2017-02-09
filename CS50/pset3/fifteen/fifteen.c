#include <stdio.h>
#import <stdbool.h>
#include "cs50.h"

int **board;
int size;
FILE* file;
int zero_x, zero_y;

void init_log(void) {
    file = fopen("log.txt", "w");
    
    if (file == NULL) {
        exit(3);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init(void) {
    board = (int**) malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) board[i] = (int*) malloc(size*sizeof(int));
    
    int number = (size * size - 1);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = number;
            number--;
        }
    }
    
    if (size % 2 == 0) {
        swap(&board[size-1][size-2], &board[size-1][size-3]);
    }
    
    zero_x = size - 1;
    zero_y = size - 1;
}

void file_draw(void) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%i", board[i][j]);
            
            if (j < size - 1) {
                fprintf(file, "|");
            }
        } fprintf(file, "\n");
    } fflush(file);
}

void draw(void) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 0) printf("%4d", board[i][j]);
            else printf("%4s", "");
        }
        
        printf("\n\n");
    }
}

bool move(int tile) {
    if (tile < 1 || tile > size * size - 1) return false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == tile) {
                if ((zero_x - 1 == i && zero_y == j) || (zero_x == i && zero_y + 1 == j) || (zero_x + 1 == i && zero_y == j) || (zero_x == i && zero_y - 1 == j)) {
                    swap(&board[i][j], &board[zero_x][zero_y]);
                    zero_x = i;
                    zero_y = j;
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool won(void) {
    bool ok = true;
    int counter = 1;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != size - 1 || j != size - 1) {
                if (board[i][j] != counter) {
                    ok = false;
                    break;
                }
            
                counter++;
            }
        }
    }
    
    return ok;
}

void all_free(void) {
    fclose(file);
    for (int i = 0; i < size; i++) free(board[i]);
    free(board);
}

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: fifteen d\n");
        exit(1);
    }
    
    size = atoi(argv[1]);
    
    if (size < 3 || size > 27) {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n", 3, 3, 27, 27);
        exit(2);
    }
    
    init_log();
    
    printf("WELCOME TO GAME OF FIFTEEN\n");
    
    init();
    
    while(1) {
        printf("\n\n\n");
        
        draw();
        file_draw();
        
        if (won()) {
            printf("ftw!\n");
            break;
        }
        
        printf("Tile to move: ");
        int tile = GetInt();
        
        if (tile == 0) break;
        
        fprintf(file, "%i\n", tile);
        fflush(file);
        
        if (!move(tile)) printf("\nIllegal move.\n");
    }
    
    all_free();
}