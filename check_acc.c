#include "main.h"

void check_acc(char *name, char* pwd)
{
	pacc phead_acc;
	FILE *fp;
	fp = fopen("usr_acc.txt", "r");
	fetch_acc(&phead_acc);
	pacc pcur_acc;
	pcur_acc = phead_acc;
	while(pcur_acc!=NULL)
	{
		if ((strcmp(name,pcur_acc->usr_nm)==0))
		{
			if (strcmp(pwd, pcur_acc->usr_pwd) == 0)
			{
				show_start(pcur_acc->usr_role);
			}
			else
			{
				printf("The password is wrong! Please enter again!\n");
				int j;
				int tmp_pwd[PWD_LEN];
				for (j = 0; j < 3; j++)
				{
					printf("The %dth password is : ", j+1);
					fflush(stdin);
					scanf("%s", tmp_pwd);
					printf("the pwd is: \s\n", tmp_pwd);
					if (strcmp(tmp_pwd, pcur_acc->usr_pwd) == 0)
					{
						show_start(pcur_acc->usr_role);
					}
				}
				if (j >= 3)
				{
					printf("Sorry! The times you have entered greater than 3!\n");
					exit(0);
				}
			}
		}
		else
		{
			pcur_acc = pcur_acc->acc_next;
		}
	}
	if (pcur_acc == NULL)
	{
		printf("NAME ERROR!\n");
		exit(0);
	}
	fclose(fp);
}