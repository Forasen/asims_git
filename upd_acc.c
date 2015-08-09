#include "main.h"

void upd_acc(pacc* pphead_acc)
{

	FILE *fp;
	fp = fopen("usr_acc.txt", "r");

	pacc phead_acc;
	fetch_acc(&phead_acc);
	printf("Enter the name_index:");
	char name_tmp[NM_LEN] = { NULL };
	scanf("%s", name_tmp);
	pacc pcur = phead_acc;
	while (pcur != NULL && (strcmp(name_tmp, pcur->usr_nm) != 0))
	{
		pcur = pcur->acc_next;
	}
	if (pcur != NULL)
	{

		char tmp_pwd[PWD_LEN] = { NULL };
		int tmp_role;
		printf("Enter the new password>>>");
		fflush(stdout);
		fflush(stdin);
		scanf("%s", tmp_pwd);
		strcpy(pcur->usr_pwd, tmp_pwd);

		printf("Enter the user role>>>");
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &tmp_role);
		pcur->usr_role = tmp_role;

		
		printf("The updated account is:\n");
		pacc pcur;
		pcur = phead_acc;
		while (pcur != NULL)
		{
			fprintf(stdout, "\t\t\t\t%-15s%-10s%5d\n", pcur->usr_nm, pcur->usr_pwd, pcur->usr_role);
			pcur = pcur->acc_next;
		}
	}
	fclose(fp);

	FILE *fp1;
	pacc pcur1;
	pcur1 = phead_acc;
	fp1 = fopen("usr_acc.txt", "w");
	while (pcur1 != NULL)
	{
		if (pcur1->acc_next != NULL)
		{
			fprintf(fp1, "%-15s%-10s%5d\n", pcur1->usr_nm, pcur1->usr_pwd, pcur1->usr_role);
		}
		else
		{
			fprintf(fp1, "%-15s%-10s%5d", pcur1->usr_nm, pcur1->usr_pwd, pcur1->usr_role);
		}
		pcur1 = pcur1->acc_next;
	}

	fclose(fp1);
}