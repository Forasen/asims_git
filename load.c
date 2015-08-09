#include "main.h"
void load()
{
	char name_tmp[NM_LEN];
	char *pwd_tmp;
	printf("enter usr_name:");
	gets(name_tmp);
	printf("enter usr_password:");
	char pwdstr[PWD_LEN] = { 0 };
	int k = 0;
	char c;

	while (((c = getch()) != 13) && k < PWD_LEN - 1)
	{
		pwdstr[k++] = c;
		putchar('*');
	}

	printf("\n\n");

	pwd_tmp = pwdstr; 
	check_acc(name_tmp, pwdstr);
}