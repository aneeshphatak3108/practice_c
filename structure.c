#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXDATA 1024
#define LINESIZE 1024

typedef struct Subject{
	char subject_name[24];
	int sem;
	int credits;
	float marks;
	int grade;
}Subject;

Subject subject1, subject2, subject3, subject4, subject5, subject6, subject7, subject8, subject9, subject10;

typedef struct student{
	long long mis;
	char name[128];
	int admission_year;
	Subject subject1;
	Subject subject2;
	Subject subject3;
	Subject subject4;
	Subject subject5;
	Subject subject6;
	Subject subject7;
	Subject subject8;
	Subject subject9;
	Subject subject10;
	float cgpa;
}student;



//TO BE USED WHILE SEARCHING ON KEY NAME
void readinput(char name[]) {
	int i = 0;
	char temp = '\0';
	while ((temp = getchar())) {
		if (temp == '\n') {
			name[i] = '\0';
			break;
		}
		name[i] = temp;
		i++;
	}
}



/* returns length of line */
int readline(int fd, char line[]) {
	int i = 0;
	char ch;
	while(i < LINESIZE && read(fd, &ch, 1) && ch != '\n') {
		line[i] = ch;
		i++;
	}
	line[i] = '\0';
	return i;
}
student students[1024];
/* returns the #records actually read, -1 otherwise */
int readcsv(char *filename, student students[]) {
	char line[LINESIZE];
	int fd;
	int count = 0;
	char *p;
	fd = open(filename, O_RDWR);
	if(fd == -1) {
		perror("open failed:");
		return -1;
	}
	readline(fd, line);
	while(readline(fd, line)) {
	//	printf("%s", line);
		p = strtok(line, ",");
		students[count].mis = atoll(p);
	
		p = strtok(NULL, ",");
		strcpy(students[count].name, p);
	
		p = strtok(NULL, ",");
		students[count].admission_year = atoi(p);
	
	
	
	
	
	
		p = strtok(NULL, ",");
		strcpy(students[count].subject1.subject_name, p);
		
		p = strtok(NULL, ",");
		students[count].subject1.credits = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject1.marks = atof(p);
		
		p = strtok(NULL, ",");
		students[count].subject1.grade = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject1.sem = atoi(p);
		
		
		
		
		
		
		p = strtok(NULL, ",");
		strcpy(students[count].subject2.subject_name, p);
		
		p = strtok(NULL, ",");
		students[count].subject2.credits = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject2.marks = atof(p);
		
		p = strtok(NULL, ",");
		students[count].subject2.grade = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject2.sem = atoi(p);
		
		
		
		
		
		
		
		
		p = strtok(NULL, ",");
		strcpy(students[count].subject3.subject_name, p);		
		
		p = strtok(NULL, ",");
		students[count].subject3.credits = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject3.marks = atof(p);
		
		p = strtok(NULL, ",");
		students[count].subject3.grade = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject3.sem = atoi(p);
		
		
		
		
		
		
		
		p = strtok(NULL, ",");
		strcpy(students[count].subject4.subject_name, p);		
		
		p = strtok(NULL, ",");
		students[count].subject4.credits = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject4.marks = atof(p);
		
		p = strtok(NULL, ",");
		students[count].subject4.grade = atoi(p);
		
		p = strtok(NULL, ",");
		students[count].subject4.sem = atoi(p);

	
		count++;
	}
	close(fd);
	return count;
}


float average_function(student students[], int len, char subject[]);


float standard_deviation(student students[], int len, char subject[]) {
	float sum = 0;
	float sd = 0;
	float average = 0;
	if (strcmp(students[1].subject1.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject1.marks) - average), 2);
		}
	}

	if (strcmp(students[1].subject2.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject2.marks) - average), 2);
		}
	}
	
	if (strcmp(students[1].subject3.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject3.marks) - average), 2);
		}
	}
	
	if (strcmp(students[1].subject4.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject4.marks) - average), 2);
		}
	}
	
	if (strcmp(students[1].subject5.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject5.marks) - average), 2);
		}
	}
	
	if (strcmp(students[1].subject6.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject6.marks) - average), 2);
		}
	}
	
	if (strcmp(students[1].subject7.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject7.marks) - average), 2);
		}
	}
	
	if (strcmp(students[1].subject8.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject8.marks) - average), 2);
		}
	}
	
	
	if (strcmp(students[1].subject9.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject9.marks) - average), 2);
		}
	}
	
	
	if (strcmp(students[1].subject10.subject_name, subject) == 0) {
		average = average_function(students, len, subject);
		for (int i = 0; i < len; i++) {
		sum = sum + pow(((students[i].subject10.marks) - average), 2);
		}
	}
	sd = pow((sum/len), 0.5);
	return sd;
}












float average_function(student students[], int len, char subject[]) {
	float sum = 0;
	float average = 0;
	int i = 0;
	if (strcmp(students[1].subject1.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject1.marks;
			i++;
		}
	}
	
	if (strcmp(students[1].subject2.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject2.marks;
			i++;
		}
	}
	
	if (strcmp(students[1].subject3.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject3.marks;
			i++;
		}
	}
	
	if (strcmp(students[1].subject4.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject4.marks;
			i++;
		}
	}
	
	
	if (strcmp(students[1].subject5.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject5.marks;
			i++;
		}
	}
	
	
	if (strcmp(students[1].subject6.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject6.marks;
			i++;
		}
	}
	
	if (strcmp(students[1].subject7.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject7.marks;
			i++;
		}
	}
	
	if (strcmp(students[1].subject8.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject8.marks;
			i++;
		}
	}
	
	
	if (strcmp(students[1].subject9.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject9.marks;
			i++;
		}
	}
	
	
	if (strcmp(students[1].subject10.subject_name, subject) == 0) {
		while (i < len) {
			sum = sum + students[i].subject10.marks;
			i++;
		}
	}
	
	average = sum/len;
	return average;
	
	

	
	
}

int search_topper(student students[], int len, char subject[]) {
	int highest_index = 0;
	int i = 0;
	if (strcmp(students[1].subject1.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject1.marks > students[highest_index].subject1.marks)
				highest_index = i;
			i++;
		}
	}
	
	
	
	if (strcmp(students[1].subject2.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject2.marks > students[highest_index].subject2.marks)
				highest_index = i;
			i++;
		}
	}
	
	
	
	
	if (strcmp(students[1].subject2.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject2.marks > students[highest_index].subject2.marks)
				highest_index = i;
			i++;
		}
	}



	if (strcmp(students[1].subject3.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject3.marks > students[highest_index].subject3.marks)
				highest_index = i;
			i++;
		}
	}




	if (strcmp(students[1].subject4.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject4.marks > students[highest_index].subject4.marks)
				highest_index = i;
			i++;
		}
	}




	if (strcmp(students[1].subject5.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject5.marks > students[highest_index].subject5.marks)
				highest_index = i;
			i++;
		}
	}



	if (strcmp(students[1].subject6.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject6.marks > students[highest_index].subject6.marks)
				highest_index = i;
			i++;
		}
	}



	if (strcmp(students[1].subject7.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject7.marks > students[highest_index].subject7.marks)
				highest_index = i;
			i++;
		}
	}






	if (strcmp(students[1].subject8.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject8.marks > students[highest_index].subject8.marks)
				highest_index = i;
			i++;
		}
	}




	if (strcmp(students[1].subject9.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject9.marks > students[highest_index].subject9.marks)
				highest_index = i;
			i++;
		}
	}




	if (strcmp(students[1].subject10.subject_name, subject) == 0) {
		while (i < len) {
			if (students[i].subject10.marks > students[highest_index].subject10.marks)
				highest_index = i;
			i++;
		}
	}
	return highest_index;
	
}




float search_name(student students[], int len, char name[], char subject[]) {
	int index = -1;
	for (int i = 0; i < len; i++) {
		if (strcmp(students[i].name, name) == 0)
			index = i;
	}
	if (strcmp(students[index].subject1.subject_name, subject) == 0)
		return (students[index].subject1.marks);
		
	else if (strcmp(students[index].subject2.subject_name, subject) == 0)
		return (students[index].subject2.marks);
		
	else if (strcmp(students[index].subject3.subject_name, subject) == 0)
		return (students[index].subject3.marks);
		
	else if (strcmp(students[index].subject4.subject_name, subject) == 0)
		return (students[index].subject4.marks);
		
	else if (strcmp(students[index].subject5.subject_name, subject) == 0)
		return (students[index].subject5.marks);
		
	else if (strcmp(students[index].subject6.subject_name, subject) == 0)
		return (students[index].subject6.marks);
		
	else if (strcmp(students[index].subject7.subject_name, subject) == 0)
		return (students[index].subject7.marks);
		
	else if (strcmp(students[index].subject8.subject_name, subject) == 0)
		return (students[index].subject8.marks);

	else if (strcmp(students[index].subject9.subject_name, subject) == 0)
		return (students[index].subject9.marks);
		
	else if (strcmp(students[index].subject10.subject_name, subject) == 0)
		return (students[index].subject10.marks);
//	printf("marks of %s :%f\n", students[index].subject2.subject_name, students[index].subject2.marks);
	printf("Looking for %s\n", subject);
	//printf("marks of %s %f\n", students[index].subject1.subject_name, students[index].subject1.marks);
	return -2;
}



int find_min_cgpa(student students[], int l, int len) {
	int minpos = 0;
	for (int i = l+1; i < len; i++) {
		if (students[i].cgpa < students[minpos].cgpa)
			minpos = i;
	}
	return minpos;
}


void swap(student students[], int i, int minpos) {
	float temp = students[i].cgpa;
	students[i].cgpa = students[minpos].cgpa;
	students[minpos].cgpa = temp;
}


void selection_sort_cgpa(student students[], int len) {
	int i, minpos;
	i = 0;
	while(i < len - 1) {
		minpos = find_min_cgpa(students, i, len);
		swap(students, i, minpos);
		i++;
	}
}

int main(int argc, char *argv[]) {
	student students[MAXDATA];
	int choice = 0;
	int count;
	int topper;
	float sd = 0;
//	float sum = 0;
	int n = 0;
	//float standard_deviation = 0;
	float average;
	char student_name[128];
	char subject_name[128];
	count = readcsv(argv[1], students);
	printf("Press 1 to display entire csv file\nPress 2 to search a student and find his/her marks in a subject\nPress 3 to display name and mis of students with highest marks in a subject\nPress 4 to find average marks in a subject\nPress 5 to get list of top n students by cgpa\nPress 6 to find standard deviation");
	scanf("%d", &choice);
	// Clear the input buffer
	while ((getchar()) != '\n');//When you enter a number for the scanf and press Enter, the newline character ('\n') is left in the input buffer.

							//When you subsequently try to read a string using getchar() for student_name, it immediately reads the newline character left in the 									//buffer without waiting for additional input. To resolve this, you need to clear the input buffer before reading the string.
	char line[1024];
	int fd = open(argv[1], O_RDWR);
	switch (choice) {
	case 1:
		if(fd == -1) {
			perror("open failed:");
			return -1;
		}
		readline(fd, line);
		while(readline(fd, line)) 
			printf("%s", line);
		break;
		
	case 2:
		printf("Enter the student name\n");
		for (int i = 0;i < 128; i++)
			student_name[i] = '\0';
		for (int i = 0;i < 128; i++) {
			student_name[i] = getchar();
			if (student_name[i] == '\n') {
				student_name[i] = '\0';
				break;
			}
		}
		printf("Enter the subject name\n");
		for (int i = 0;i < 128; i++)
			subject_name[i] = '\0';
		for (int i = 0;i < 128; i++) {
			subject_name[i] = getchar();
			if (subject_name[i] == '\n') {
				subject_name[i] = '\0';
				break;
			}
		}
		float marks = search_name(students, count, student_name,subject_name);
		printf("%f\n",marks);
		break;
	
		
	case 3:
		printf("Enter the subject name\n");
		for (int i = 0;i < 128; i++)
			subject_name[i] = '\0';
		for (int i = 0;i < 128; i++) {
			subject_name[i] = getchar();
			if (subject_name[i] == '\n') {
				subject_name[i] = '\0';
				break;
			}
		}
		topper = search_topper(students, count,subject_name);
		printf("Topper name is %s, and mis is %lld\n", students[topper].name, students[topper].mis);
		break;
		
		
		
	case 4:
		printf("Enter the subject name\n");
		for (int i = 0;i < 128; i++)
			subject_name[i] = '\0';
		for (int i = 0;i < 128; i++) {
			subject_name[i] = getchar();
			if (subject_name[i] == '\n') {
				subject_name[i] = '\0';
				break;
			}
		}
		average = average_function(students, count, subject_name);
		printf("Average is %f\n", average);
		break;
	
	case 5:
		printf("Enter the value of n\n");
		scanf("%d", &n);
		for (int i = 0; i < count; i ++) {
			students[i].cgpa = ((students[i].subject1.credits * students[i].subject1.grade) + (students[i].subject2.credits * students[i].subject2.grade) +(students[i].subject3.credits * students[i].subject3.grade) +(students[i].subject4.credits * students[i].subject4.grade) +(students[i].subject5.credits * students[i].subject5.grade) +(students[i].subject6.credits * students[i].subject6.grade) +(students[i].subject7.credits * students[i].subject7.grade) +(students[i].subject8.credits * students[i].subject8.grade) +(students[i].subject9.credits * students[i].subject9.grade) +(students[i].subject10.credits * students[i].subject10.grade))/(students[i].subject1.credits +students[i].subject2.credits +students[i].subject3.credits +students[i].subject4.credits +students[i].subject5.credits +students[i].subject6.credits +students[i].subject7.credits +students[i].subject8.credits +students[i].subject9.credits +students[i].subject10.credits);
		}
		selection_sort_cgpa(students, count);
		for (int i = 0;i < n; i++) {
			printf("%s\n", students[i].name);
		}
		break;
		
		
	case 6:
		printf("Enter the subject name\n");
		for (int i = 0;i < 128; i++)
			subject_name[i] = '\0';
		for (int i = 0;i < 128; i++) {
			subject_name[i] = getchar();
			if (subject_name[i] == '\n') {
				subject_name[i] = '\0';
				break;
			}
		}
		sd = standard_deviation(students, count,subject_name);
		printf("Standard deviation of marks in the given subject is %f\n", sd);
	}
}
