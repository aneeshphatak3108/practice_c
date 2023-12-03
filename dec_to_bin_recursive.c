#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* decimal_to_binary(int n) {
    if (n == 0 || n == 1) {
        char* bin = (char*)malloc(2);
        bin[0] = n + '0';
        bin[1] = '\0';
        return bin;
    }

    char* partial_result = decimal_to_binary(n / 2);
    int len = strlen(partial_result);

    char* bin = (char*)realloc(partial_result, len + 1);

    bin[len] = (n % 2) + '0';
    //bin[len + 1] = '\0';

    return bin;
}

int main() {
    int a;
    scanf("%d", &a);
    char* binary_result = decimal_to_binary(a);

    if (binary_result != NULL) {
        printf("%s\n", binary_result);
        free(binary_result);
    } else {
        printf("Memory allocation failure.\n");
    }

    return 0;
}