#include "main.h"

void add_acc(pacc* pphead_acc, char* argv[])
{
	pacc phead_acc = NULL;
	pacc pcur_acc;
	pacc pprev_acc;
	pacc pnew_acc;
	char path_acc[128];
	//*path_acc = load_path(argv[1]);
	FILE *fp;
	fp = fopen("usr_acc.txt", "r");

	char line[128];

	memset(line, 0, sizeof(line));

	int cnt = 1;

	printf("Enter the %dth stu_acc(name-password-role):\n", cnt);

	fflush(stdin);

	fetch_acc(&phead_acc);
	*pphead_acc = phead_acc;

	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), stdin) != NULL)
	{

		pcur_acc = *pphead_acc;

		pprev_acc = NULL;

		pnew_acc = (pacc)calloc(1, sizeof(acc));

		sscanf(line, "%s%s%d", pnew_acc->usr_nm, pnew_acc->usr_pwd, &pnew_acc->usr_role);

		//fprintf(fp, "\n%-15s%-10s%5d", pnew_acc->usr_nm, pnew_acc->usr_pwd, pnew_acc->usr_role);
		while (strcmp(pnew_acc->usr_nm, pcur_acc->usr_nm) == 0)
		{
			cnt -= 1;
			printf("Sorry! The user_name \"%s\" exits in the file! Please input the different USRER_NAME!\n", pnew_acc->usr_nm);

			while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), stdin) != NULL)
			{
				sscanf(line, "%s%s%d", pnew_acc->usr_nm, pnew_acc->usr_pwd, &pnew_acc->usr_role);
				if (strcmp(pnew_acc->usr_nm, pcur_acc->usr_nm) != 0)
				{
					break;
				}
			}

			


		}

		while (pcur_acc != NULL && (strcmp(pnew_acc->usr_nm, pcur_acc->usr_nm) > 0))
		{
			pprev_acc = pcur_acc;
			pcur_acc = pcur_acc->acc_next;
		}
		if (pprev_acc == NULL)
		{
			pnew_acc->acc_next = *pphead_acc;
			*pphead_acc = pnew_acc;
		}
		else
		{
			pnew_acc->acc_next = pcur_acc;
			pprev_acc->acc_next = pnew_acc;
		}

		cnt++;

		printf("Enter the %dth stu_accor(nm-name-course_nm-course_score)\n", cnt);
	}

	pcur_acc = *pphead_acc;
	while (pcur_acc != NULL)
	{
		printf("\t\t\t\t%-15s%-10s%5d\n", pcur_acc->usr_nm, pcur_acc->usr_pwd, pcur_acc->usr_role);
		pcur_acc = pcur_acc->acc_next;
	}
	fclose(fp);

	FILE *fp1;
	pacc pcur1;
	pcur1 = *pphead_acc;
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