#include "main.h"
void del_inf(pinf* pphead_inf)
{
	FILE *fp;

	pinf phead_inf;
	pinf pprev_inf;
	fetch_inf(&phead_inf);
	printf("Enter the id_index:");
	char id_tmp[NM_LEN] = { NULL };
	scanf("%s", id_tmp);
	pinf pcur = phead_inf;
	pprev_inf = NULL;
	while (pcur != NULL && (strcmp(id_tmp, pcur->usr_id) != 0))
	{
		pprev_inf = pcur;
		pcur = pcur->inf_next;
	}
	if (pprev_inf == NULL)
	{
		phead_inf = pcur->inf_next;
	}
	else
	{
		pprev_inf->inf_next = pcur->inf_next;
	}
	free(pcur);
	pcur = NULL;

	printf("The informaton after deleted is:\n");
	
	pcur = phead_inf;
	while (pcur != NULL)
	{
		fprintf(stdout, "\t\t\t\t%5s%12s%5d%5d\n", pcur->usr_id, pcur->usr_nm, pcur->usr_cs_id, pcur->usr_cs_score);
		pcur = pcur->inf_next;
	}
	pinf pcur1;
	pcur1 = phead_inf;
	fp = fopen("usr_inf.txt", "w");
	while (pcur1 != NULL)
	{
		fprintf(fp, "%-5s%-12s%-5d%-5d\n", pcur1->usr_id, pcur1->usr_nm, pcur1->usr_cs_id, pcur1->usr_cs_score);
		pcur1 = pcur1->inf_next;
	}

	fclose(fp);
}