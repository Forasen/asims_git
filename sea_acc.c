#include "main.h"

void sea_acc(pacc *pphead_acc)
{

	pacc phead_acc = NULL;
 	pacc pcur_acc;
	FILE *fp;
	fp = fopen("usr_acc.txt", "r");
 	fetch_acc(&phead_acc);
	pcur_acc = phead_acc;
	char tmp_name[NM_LEN];

	printf("Enter a name index:");
	
	scanf("%s", tmp_name);
	printf("\n\n");
	while (pcur_acc != NULL && (strcmp(tmp_name, pcur_acc->usr_nm) != 0))
	{
		pcur_acc = pcur_acc->acc_next;
	}

	if (pcur_acc != NULL)
	{

		printf("\nThe account for serching is:\n\n");
		printf("\t\t\t\t%-15s%-10s%5d\n\n", pcur_acc->usr_nm, pcur_acc->usr_pwd, pcur_acc->usr_role);
	}
	else
	{
		printf("SORRY! The accont is not in!\n");
	}

	fclose(fp);
	char ret[2] = { NULL };

	printf("RETURN? (Y/N):");
	scanf("%s", ret);
	while (ret[0] != 'Y')
	{
		system("cls");
		printf("RETURN? (Y/N):");
		scanf("%c", ret);
	}
	if (ret[0] == 'Y')
	{
		return;
	}
}