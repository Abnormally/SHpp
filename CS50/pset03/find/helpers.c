#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "helpers.h"
 
void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    
    free(x);
}
 
void sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    sort(a, m);
    sort(a + m, n - m);
    merge(a, n, m);
}

bool search (int x, int *a, int n) {
    int i = 0, j = n - 1;
    
    while (i <= j) {
        int k = (i + j) / 2;
        if (a[k] == x) {
            return true;
        } else if (a[k] < x) {
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    
    return false;
}