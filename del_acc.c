#include "main.h"

void del_acc(pacc* pphead_acc)
{

	FILE *fp;
	fp = fopen("usr_acc.txt", "r");
	pacc phead_acc;
	pacc pprev_acc;
	fetch_acc(&phead_acc);
	printf("Enter the name_index : ");
	char name_tmp[NM_LEN] = { NULL };
	scanf("%s", name_tmp);
	pacc pcur = phead_acc;
	pprev_acc = NULL;
	while (pcur != NULL && (strcmp(name_tmp, pcur->usr_nm) != 0))
	{
		pprev_acc = pcur;
		pcur = pcur->acc_next;
	}
	if (pprev_acc == NULL)
	{
		phead_acc = pcur->acc_next;
	}
	else
	{
		pprev_acc->acc_next = pcur->acc_next;
	}
	free(pcur);
	pcur = NULL;

	printf("\nThe account after deleted is:\n");

	pcur = phead_acc;
	while (pcur != NULL)
	{
		fprintf(stdout, "\t\t\t\t%-15s%-10s%5d\n", pcur->usr_nm, pcur->usr_pwd, pcur->usr_role);
		pcur = pcur->acc_next;
	}
	fclose(fp);


	FILE *fp1;
	pacc pcur1;
	pcur1 = phead_acc;
	fp1 = fopen("usr_acc.txt", "w");
	while (pcur1 != NULL)
	{
		if (pcur1->acc_next != NULL){
			fprintf(fp1, "%-15s%-10s%5d\n", pcur1->usr_nm, pcur1->usr_pwd, pcur1->usr_role);
		}
		else{
			fprintf(fp1, "%-15s%-10s%5d", pcur1->usr_nm, pcur1->usr_pwd, pcur1->usr_role);
		}
		pcur1 = pcur1->acc_next;
	}
	fclose(fp1);
}