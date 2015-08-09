#include "main.h"

void upd_inf(pinf* pphead_inf)
{
	FILE *fp;
	
	pinf phead_inf;
	fetch_inf(&phead_inf);
	printf("Enter the id_index:");
	char id_tmp[NM_LEN] = { NULL };
	scanf("%s", id_tmp);
	pinf pcur = phead_inf;
	while (pcur != NULL && (strcmp(id_tmp, pcur->usr_id) != 0))
	{
		pcur = pcur->inf_next;
	}
	if (pcur != NULL)
	{

		char tmp_name[NM_LEN] = { NULL };
		int tmp_cs_id;
		int tmp_cs_score;
		printf("Enter the name>>>");
		fflush(stdout);
		fflush(stdin);
		scanf("%s", tmp_name);
		strcpy(pcur->usr_nm, tmp_name);

		printf("Enter the course-id>>>");
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &tmp_cs_id);
		pcur->usr_cs_id = NULL;
		pcur->usr_cs_id = tmp_cs_id;

		printf("Enter the course-score>>>");
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &tmp_cs_score);
		pcur->usr_cs_score = NULL;
		pcur->usr_cs_score = tmp_cs_score;

		printf("The updated informaton is:\n");
		pinf pcur;
		pcur = phead_inf;
		while (pcur != NULL)
		{
			fprintf(stdout, "\t\t\t\t%5s%12s%5d%5d\n", pcur->usr_id, pcur->usr_nm, pcur->usr_cs_id, pcur->usr_cs_score);
			pcur = pcur->inf_next;
		}
	}
	pinf pcur1;
	pcur1 = phead_inf;
	fp = fopen("usr_inf.txt", "w");
	while (pcur1!= NULL)
	{
		fprintf(fp, "%-5s%-12s%-5d%-5d\n", pcur1->usr_id, pcur1->usr_nm, pcur1->usr_cs_id, pcur1->usr_cs_score);
		pcur1 = pcur1->inf_next;
	}

	fclose(fp);
}