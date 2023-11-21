#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/************************************************************************/

typedef struct studat{
	char name[32];
	unsigned int misid;
	short yearofadm;
	float cgpa;
	struct sub{
		char subname[12];
		short int credit;
		float marks;
		unsigned short grade;
		unsigned short sem;
	} sub[10];
} studat;


/************************************************************************/

char c[1];

/************************************************************************/

void skp_header(int fd) {
	read(fd, c, 1);
	while(c[0] != '\n') {
		read(fd, c, 1);
	}
}

/************************************************************************/

int entry_count(int fd) {
	int count = 0, sz; 
	skp_header(fd);
	while((sz = read(fd, c, 1)) != 0) {
		if(c[0] == '\n') {
			count++;
		}
	}
	printf("\n");
	lseek(fd, 0, SEEK_SET);
	return count;
}

/************************************************************************/

int read_int(int fd) {
	int no;
	char str[12];
	int i = 0;
	do {
		read(fd, c, 1);
		str[i] = c[0];
		i++;
		if(c[0] == '\n')
			break;
	}
	while(c[0] != ',');
	str[--i] = 0;
	no = atoi(str);
	return no;
}

/************************************************************************/

void read_str(int fd, char name[]) {
	int i = 0;
	do {
		read(fd, c, 1);
		name[i] = c[0];
		i++;
		if(c[0] == '\n')
			break;
	}
	while(c[0] != ',');
	name[--i] = 0;	
}

/************************************************************************/

float read_float(int fd) {
	int a, i = 0;
	float no, b;
	char str1[4], str2[4];
	do {
		read(fd, c, 1);
		str1[i++] = c[0];
		if(c[0] == ',') {
			str1[--i] = 0;
			no = atoi(str1);
			return no;
		}
	}
	while(c[0] != '.');   
	str1[--i] = 0;
	no = (float)atoi(str1); i = 0;
	
	do {
		read(fd, c, 1);
		str2[i++] = c[0];
	}
	while(c[0] != ',');
	str2[--i] = 0;
	a = atoi(str2);
	b = ((float)a) / 100;
	no += b;	
	return no;
}

/************************************************************************/

void read_file(int fd, studat student[], int count) {
	int i, j;
	skp_header(fd);
	for(i = 0; i < count; i++) {
		student[i].misid = read_int(fd);
		read_str(fd, student[i].name);
		student[i].yearofadm = read_int(fd);
		for(j = 0; j < 10; j++) {
			read_str(fd, student[i].sub[j].subname);
			student[i].sub[j].credit = read_int(fd);
			student[i].sub[j].marks = read_float(fd);
			student[i].sub[j].grade = read_int(fd);
			student[i].sub[j].sem = read_int(fd);
		}
		
	}

}

/************************************************************************/

void disp_file(studat student[], int count) {
	int i, j;
	for(i = 0; i < count; i++) {
		printf("%d,", student[i].misid);
		printf("%s,", student[i].name);
		printf("%d,", student[i].yearofadm);
		for(j = 0; j < 10; j++) {
			printf("%s,", student[i].sub[j].subname);
			printf("%d,", student[i].sub[j].credit);
			printf("%.2f,", student[i].sub[j].marks);
			printf("%d,", student[i].sub[j].grade);	 
		if(j == 9)
			printf("%d\n", student[i].sub[j].sem);
		else 
			printf("%d,", student[i].sub[j].sem);
		}
	}
	printf("\n");
}

/************************************************************************/

int chk_usr_in(char *usr_in) {
	int i, a;
	char *commands[11];
	commands[0] = "print"; commands[1] = "marks";	
	commands[2] = "highest"; commands[3] = "avg";	
	commands[4] = "sgpa"; commands[5] = "add";	
	commands[6] = "count"; commands[7] = "update";
	commands[8] = "stdev"; commands[9] = "topn";
	commands[10] = "end";
	for(i = 0; i < 11; i++) {
		if((a = strcmp(commands[i], usr_in)) == 0)
			return i;
	}
	return 11;	
}

/************************************************************************/

int sub_srch(studat student[]) {
	int i, a;
	char subname[12];
	scanf("%s", subname);
	for(i = 0; i < 10; i++) {
		if((a = strcmp(student[1].sub[i].subname, subname)) == 0) {
			return i;
		}
	}
	return -1;
}

/************************************************************************/

double avg(studat student[], int count, int subno) {
	int i;
	double total = 0;
	if(subno == -1) { 
		printf("no such subject found\n");
		return -1;
	}
	for(i = 0; i < count; i++) {
		total += student[i].sub[subno].marks;
	}
	return (total / count);
}

/************************************************************************/

int misid_srch(studat student[], int id, int count) {
	int i = 0;
	while(i < count) {
		if(student[i++].misid == id) 
			return (i-1);
	}
	return -1;
}

/************************************************************************/

void disp_sgpa(studat student[], int count) {
	float total = 0, total_cred = 0, sgpa;
	int id, i, sem;
	scanf("%d", &id);
	id = misid_srch(student, id, count);
	if(id == -1) {
		printf("no such misid found\n\n");
		return;
	}
	scanf("%d", &sem);
	for(i = 0; i < 10; i++) {
		if(student[id].sub[i].sem == sem) {
			total += (float)(student[id].sub[i].credit * student[id].sub[i].grade);
			total_cred += (float)student[id].sub[i].credit;
		}
	}
	if(total == 0) {
		printf("no such sem exists\n"); return;
	}
	sgpa = total / total_cred;
	printf("%.2f\n", sgpa);
}	

/************************************************************************/

void disp_highest(studat student[], int count) {
	int i;
	int subno = sub_srch(student);
	float max = 0;
	if(subno == -1) {
		printf("no such subject found\n\n");
		return;
	}
	for(i = 0; i < count; i++) {
		if(student[i].sub[subno].marks > max)
			max = student[i].sub[subno].marks;
	}
	printf("%.2f\n", max);
	for(i = 0; i < count; i++) {
		if(student[i].sub[subno].marks == max)
			printf("%s %d\n", student[i].name, student[i].misid);
	}
	printf("\n");
}

/************************************************************************/

void disp_count(studat student[], int count) {
	int subno, i;
	int g_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	subno = sub_srch(student);
	if(subno == -1) {
		printf("no such subject found\n"); return;
	}
	for(i = 0; i < count; i++) {
		g_count[student[i].sub[subno].grade] += 1;
	}
	for(i = 0; i < 10; i++) 
		printf("%d %d\n", i, g_count[i]);
	printf("\n");
}

/************************************************************************/

void disp_stdev(studat student[], int count) {
	int subno, i;
	double avgrg, stdev, total = 0;
	subno = sub_srch(student);
	avgrg = avg(student, count, subno);
	for(i = 0; i < count; i++) {
		total += pow((student[i].sub[subno].marks - avgrg), 2);	
	}
	stdev = pow((total / count), 0.5);
	printf("%lf\n", stdev);
}

/************************************************************************

void calc_cgpa(studat student[], int i) {
}

************************************************************************

void disp_topn(studat student[], int count) {
	unsigned short int n, yoa;
	int i;
	scanf("%d%d", &n, &yoa);
	for(i = 0; i < count; i++) {
		if(student[i].yearofadm == yoa)
			calc_cgpa(student, i);
	}
}

************************************************************************/

void add_entry(int fd) {
	char c;
	lseek(fd, 0, SEEK_END);
	c = getchar();
	c = getchar();
	while(1) {
		write(fd, &c, 1);
		if(c == '\n') 
			break;
		if(c == ',') {
			if((c = getchar()) == ' ') 
				c = getchar();
		}
		else 
			c = getchar();
	}
	close(fd);
}

/************************************************************************/

int main(int argc, char *argv[]) {
	int fd, count, subnoo;
	float avgrg;
	char *usr_in;
	studat student[512];
	
	fd = open(argv[1], O_RDWR);
	if(fd < 0) {
		perror("error");
		return 0;
	}
	count = entry_count(fd);
	read_file(fd, student, count);
	close(fd);

	while(1) {
		printf("user can use any of the following commands with correct syntax as displayed before colon on each of the following line-\n\nprint : print the array of structures.\nmarks <name> <subject>: display the <sub> marks of student whose name is given in <name>.\nhighest <subject> : show name, MISID of all students with highest marks in the given subject.\navg <subject> : show average marks in a given subject.\nsgpa <misid> <sem> : show sgpa of student given by <misid> in the semester given by <sem>, both being numbers\nadd mis,name,year-of-admission,subject1,credit1,marks1,grade1,...,subject10,credit10,marks10,grade10 : add entries where data is specified as a comma separated list.\ncount <subject> : print the count of number of students with each grade in a given course.\nupdate <misid> <field> <new-value> : update the entry of student with MISID in <misid>, for column specified by <field> with the new value given in <new-value>.\nstdev <course> : find standard deviation of marks in a given subject.\ntopn <n> <year-of-admission> : list top <n> students in class given by <year-of-admission> based on CGPA.\nend : to end the program\n\n");
		usr_in = (char *)malloc(sizeof(char) * 8);
		scanf("%s", usr_in);
		switch(chk_usr_in(usr_in)) {
		case 0: 
			disp_file(student, count); 
			break;
		case 1: 
			printf("could have made <marks> function, but i procrastinated\n");
			break;
		case 2: 
			disp_highest(student, count);
			break;
		case 3: 
			subnoo = sub_srch(student);
			avgrg = avg(student, count, subnoo);
			printf("%.2lf\n\n", avgrg);	
			break;
		case 4:
			disp_sgpa(student, count);
			break;
		case 5:
			add_entry(open(argv[1], O_RDWR));
			fd = open(argv[1], O_RDWR);
			count = entry_count(fd);
			read_file(fd, student, count);
			close(fd);
			break;
		case 6:
			disp_count(student, count);
			break;
		case 7:
			printf("could have made <update> function, but i procrastinated\n");
			break;
		case 8:
			disp_stdev(student, count);
			break;
		case 9:
			printf("could have made <topn> function, but i procrastinated\n");
			break;
		case 10:
			return 0;
		default:
			printf("no valid input given by the user\n");
			break;
		}
		free(usr_in);

	}
}

/************************************************************************/
