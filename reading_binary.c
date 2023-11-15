#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef struct transaction {
	double amount;
	time_t time;    
	unsigned int from_id;
	unsigned int to_id;
	char location[32];    
} transaction;

transaction *read_data(char *filename, int *total) {
	FILE *fp;
	fp = fopen(filename, "rb");
	if (fp == NULL)
 		return NULL;
	if (fread(total, sizeof(int), 1, fp) != 1)
		return NULL;
	transaction *data = malloc(sizeof(transaction) * (*total));
	if (fread(data, sizeof(transaction), *total, fp) != *total) {
		free(data);
		return NULL;
	}
	if (fclose(fp) == EOF) {
		free(data);
		return NULL;
	}

	return data;
}

double min(double a, double b ) {
	if (a > b)
		return b;
	else return a;
}

double find_min(double a[], int n) {
	if (n == 1)
		return a[0];
	return min(a[n-1], find_min(a, n-1));
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
	int index_of_min = 0;
	double min_transaction = 0;
	transaction *data = read_data(argv[1], &total);
	if (data == NULL) {
		printf("Error reading data from file.\n");
		return 1;
	}
	double amounts[total];
	for (int i =0; i < total; i++) {
		amounts[i] = data[i].amount;
	}
	/*for (int i = 0; i < total; i++) {
		printf("Amount paid:%f\n", data[i].amount);
		printf("paid from id%u\n", data[i].from_id);
		printf("paid to id%u\n", data[i].to_id);
		printf("time of payment: %s\n", ctime(&(data[i].time)));
		printf("location:%s\n", data[i].location);
		printf("\n\n\n");
	}*/
	min_transaction = find_min(amounts, total);
	index_of_min = search_index_of_min(amounts, min_transaction, total);
	printf("location of minimum transaction is %s\n", data[index_of_min].location);
	printf("time of minimum transaction is %s", ctime(&(data[index_of_min].time)));
	printf("minimum transaction is %f\n", min_transaction);

	free(data);
	return 0;
}
