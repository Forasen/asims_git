#include "main.h"
void fetch_acc(pacc* pphead_acc)
{
	*pphead_acc = NULL;
	FILE *fp;
	fp = fopen("usr_acc.txt", "r");
	pacc pnew_acc;
	pacc pcur_acc;
	pacc pprev_acc;

	//printf("The fetch information for account is:\n\n");
	while(!feof(fp))
	{
		pnew_acc = (pacc)calloc(1, sizeof(acc));
		if (fscanf(fp, "%s%s%d", pnew_acc->usr_nm, pnew_acc->usr_pwd, &pnew_acc->usr_role) == 3)
		{
			pcur_acc = *pphead_acc;
			pprev_acc = NULL;
			while ((pcur_acc != NULL) && (strcmp(pnew_acc->usr_nm, pcur_acc->usr_nm) > 0))
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
		}
		/*if (pnew_acc->usr_role != 0)
		{
			printf("%-15s%-10s%5d\n", pnew_acc->usr_nm, pnew_acc->usr_pwd, pnew_acc->usr_role);
		}*/
	}
	fclose(fp);
}