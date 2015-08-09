#include "main.h"

void add_inf(pinf* pphead_inf)
{

	pinf phead_inf = NULL;
	pinf pcur_inf;
	pinf pprev_inf;
	pinf pnew_inf;

	FILE *fp;
	fp = fopen("usr_inf.txt", "a");

	char line[128];

	memset(line, 0, sizeof(line));

	int cnt = 1;

	printf("\nEnter the %dth stu_infor(id-name-course_id-course_score):\n", cnt);

	fflush(stdin);

	fetch_inf(&phead_inf);
	*pphead_inf = phead_inf;

	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), stdin) != NULL)
	{
		//int tmp = cnt;
		pcur_inf = *pphead_inf;

		pprev_inf = NULL;

		pnew_inf = (pinf)calloc(1, sizeof(inf));

		sscanf(line, "%s%s%d%d", pnew_inf->usr_id, pnew_inf->usr_nm, &pnew_inf->usr_cs_id, &pnew_inf->usr_cs_score);

		//fprintf(fp, "\n%5s%5s%4d%4d", pnew_inf->usr_id, pnew_inf->usr_nm, pnew_inf->usr_cs_id, pnew_inf->usr_cs_score);

		while (strcmp(pnew_inf->usr_id, pcur_inf->usr_id) == 0)
		{
			cnt -= 1;
			printf("Sorry! The account \"%s\" exits in the file! Please input the different USRER_ID!\n", pnew_inf->usr_id);
			sscanf(line, "%s%s%d%d", pnew_inf->usr_id, pnew_inf->usr_nm, &pnew_inf->usr_cs_id, &pnew_inf->usr_cs_score);
			if (strcmp(pnew_inf->usr_id, pcur_inf->usr_id) != 0)
			{
				break;
			}


		}
		while (pcur_inf != NULL && (strcmp(pnew_inf->usr_id, pcur_inf->usr_id) > 0))
		{

			pprev_inf = pcur_inf;
			pcur_inf = pcur_inf->inf_next;
		}
		if (pprev_inf == NULL)
		{
			pnew_inf->inf_next = *pphead_inf;
			*pphead_inf = pnew_inf;
		}
		else
		{
			pnew_inf->inf_next = pcur_inf;
			pprev_inf->inf_next = pnew_inf;
		}

		
		cnt++;
		printf("\nEnter the %dth stu_infor(id-name-course_id-course_score)\n", cnt);
		
	}

	pcur_inf = *pphead_inf;
	while (pcur_inf != NULL)
	{
		printf("\t\t\t\t%8s%8s%5d%5d\n", pcur_inf->usr_id, pcur_inf->usr_nm, pcur_inf->usr_cs_id, pcur_inf->usr_cs_score);
		pcur_inf = pcur_inf->inf_next;
	}
	fclose(fp);

	FILE *fp1;
	pinf pcur1;
	pcur1 = *pphead_inf;
	fp1 = fopen("usr_inf.txt", "w");
	while (pcur1 != NULL){
		fprintf(fp1, "%-5s%-12s%-5d%-5d\n", pcur1->usr_id, pcur1->usr_nm, pcur1->usr_cs_id, pcur1->usr_cs_score);
		pcur1 = pcur1->inf_next;
	}

	fclose(fp1);
}