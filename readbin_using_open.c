#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct transaction {
	double amount;
	time_t time;    
	unsigned int from_id;
	unsigned int to_id;
	char location[32];    
} transaction;

transaction *read_data(char *filename, int *total) {
	int fd = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return NULL;
	if (read(fd, total, 1*sizeof(int)) != sizeof(int))
		return NULL;
	transaction *data = (transaction *)malloc(sizeof(transaction) * (*total));
	if (fd == -1)
		return NULL;
	read(fd, data, sizeof(transaction) * (*total));
	close(fd);
	return data;
}

double min(double a, double b) {
	if (a > b)
		return b;
	else return a;
}


double find_min(int n, double a[]) {
	if (n == 1)
		return a[0];
	return min(a[n-1], find_min(n-1, a));
}


int search_index_of_min(double a[], double min, int total) {
	for (int i = 0; i < total; i++) {
		if (a[i] == min)
			return i;
	}
	return -1;
}


int main(int argc, char *argv[]) {
	int total = 0;
	int index = 0;
	transaction *data = read_data(argv[1], &total);
/*	for (int i = 0; i < total; i++) {
		printf("%f\n", data[i].amount);
	}*/
	double kimmat[total];
	for (int i = 0; i < total; i++) {
		kimmat[i] = data[i].amount;
	}
	double min_transaction = find_min(total, kimmat);
	index = search_index_of_min(kimmat, min_transaction, total);
	printf("Minimum transaction amount is %f\n", data[index].amount);
	printf("TIme of minimum transaction is %s", ctime(&(data[index].time)));
}
