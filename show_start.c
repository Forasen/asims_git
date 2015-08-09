#include "main.h"
void show_start(int role)
{
	int n;
	char str[100] = "Student      Information      Management      System";
	int len = strlen(str);
	system("cls");
	for (int i = 0; i < N; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 0; i < 24; i++)
	{
		printf("*");
	}
	printf("%s", str);
	for (int i = 0; i < 24; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("*");
	}
	printf("\n\n");
	if (role == 1)
	{
		printf("\t\t\t\t1. search	student information\n");
		printf("\t\t\t\t2. add		student information\n");
		printf("\t\t\t\t3. update	student information\n");
		printf("\t\t\t\t4. delete	student informatino\n");
		printf("\t\t\t\t5. add		user	account\n");
		printf("\t\t\t\t6. update	user	account\n");
		printf("\t\t\t\t7. delete	user	account\n");
		printf("\t\t\t\t8. search	user	account\n");
		printf("\t\t\t\t9. exit\n");
		printf("\nselect a number:");
		scanf("%d", &n);
		input_num(n, role);
	}
	else
	{
		printf("\t\t\t\t1. search	student information\n");
		printf("\t\t\t\t9. exit\n");
		printf("\nselect a number:");
		scanf("%d", &n);
		if (n>=2&&n<=8)
		{
			exit(0);
		}
		else
		{
			input_num(n, role);
		}
	}
}