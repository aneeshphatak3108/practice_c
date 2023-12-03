/*void print_binary(int n);
print all binary numbers of a given length;
 e.g. if n = 3, then program prints
 000
 001
 010
 011
 ...
 ...upto
 111
*/
#include <stdio.h>
#include <stdlib.h>

void print_binary_recursive(char *p, int n) {
    if (n == 0) {
        printf("%s\n", p);
        return;
    }
    p[n-1] = '0';
    print_binary_recursive(p, n-1);
    p[n-1] = '1';
    print_binary_recursive(p, n-1);
}

void print_binary(int n) {
    char *p = (char*)malloc(n+1);
    p[n] = '\0';
    for (int i = 0; i < n; i++)
        p[i] = '0';
    print_binary_recursive(p, n);
    free(p);
}

int main() {
    int n;
    scanf("%d", &n);
    print_binary(n);
    return 0;
}