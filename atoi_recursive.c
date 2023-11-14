/*write the atoi function recursive*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int atoi(char *str) {
	int len = strlen(str);
	if (*(str + 1) == '\0')
		return (*(str) - '0');
	return ((str[0] - '0') * pow(10, len-1) + atoi(str + 1));
}


int main () {
	char a[5] = "1234";
	char c[5] = "1234";
	int b = atoi(a);
	int d = atoi(c);
	printf("%d\n", b+d);
}
