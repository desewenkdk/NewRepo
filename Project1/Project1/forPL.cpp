#include <stdio.h>
#include <stdlib.h>

typedef enum _level{
	rookie,junior,senior,expert,master
}Level;
typedef struct _employee{
	int age;
	Level lv;
	char *name;
}Employee;

Employee emp[10];
Level lv[5] = { rookie,junior,senior,expert,master };
void print_empInfo(Employee emp);
int main(){
	for (int i = 0; i < 10;i++) {
		emp[i].age = i;
		emp[i].lv = lv[i%5];
		emp[i].name = (char*)malloc(sizeof(char)*i);
	}

	print_empInfo(emp[4]);
	return 0;
}
void print_empInfo(Employee emp) {
	printf("Info--------------\n");
	printf("\tlv: ");
	switch (emp.lv) {
	case rookie:
		printf("rookie");
		break;
	case junior:
		printf("junior");
		break;
	case senior:
		printf("senior");
		break;
	case expert:
		printf("expert");
		break;
	case master:
		printf("master");
		break;
	}
	printf("\n");

	printf("\tage: %d\n", emp.age);
	
}