#include "main.h"

void sea_inf(pinf *pphead_inf, int role)
{
	int n;

	pinf *pcurrent;
	system("cls");
	if (role == 1)
	{
		printf("\n\t\t\t\t0. search all\n");
	}

	if (role == 1 || role == 2)
	{
		printf("\t\t\t\t1. search by name\n");
		printf("\t\t\t\t2. search by id\n");
		printf("\t\t\t\t3. return\n\n");
	}

	printf("Enter a number:");
	fflush(stdout);
	fflush(stdin);

	scanf("%d", &n);

	sea_by(*pphead_inf, n);

}

void sea_by(pinf *pphead_inf, int n)
{

	pinf phead_inf = NULL;
	pinf pcur_inf;
	
	fetch_inf(&phead_inf);
	pcur_inf = phead_inf;


	if (n == 0)
	{
		system("cls");
		printf("\nThe whole result is:\n\n");
		fetch_inf(&phead_inf);
		pcur_inf = phead_inf;
		
		int cnt = 1;
		printf("\t\t\tORDER  \tST_ID\t       NAME\t    CS_ID    CS_SCORE\n\n");
		while (pcur_inf != NULL)
		{
			printf("\t\t\tNO.%d:\t%-15s%-15s%-10d%-10d\n", cnt, pcur_inf->usr_id, pcur_inf->usr_nm, pcur_inf->usr_cs_id, pcur_inf->usr_cs_score);
			pcur_inf = pcur_inf->inf_next;
			cnt++;
		}
		printf("\n\n");
	}
	else if(n == 3)
	{
		return;
	}
	else
	{
		char tmp_input[10];

		memset(tmp_input, 0, sizeof(tmp_input));
		system("cls");
		printf("\nPlease enter the index:");

		fflush(stdout);
		fflush(stdin);

		scanf("%s", tmp_input);

		if (isalpha(tmp_input[0]))
		{
			while (pcur_inf != NULL && (strcmp(tmp_input, pcur_inf->usr_nm) != 0))
			{
				pcur_inf = pcur_inf->inf_next;
			}
		}
		else
		{
			while (pcur_inf != NULL && (strcmp(tmp_input, pcur_inf->usr_id) != 0))
			{
				pcur_inf = pcur_inf->inf_next;
			}
		}
		if (pcur_inf != NULL)
		{
			
			printf("\nThe infomation for serching is:\n\n");
			printf("\t\t\tORDER  \tST_ID\t       NAME\t    CS_ID    CS_SCORE\n\n");
			//printf("\t\t\tNO.%d:\t%-15s%-15s%-10d%-10d\n",
			printf("\t\t\t%8s\t %10s\t  %5d\t     %5d\n\n", pcur_inf->usr_id, pcur_inf->usr_nm, pcur_inf->usr_cs_id, pcur_inf->usr_cs_score);
		}
		else
		{
			printf("\t\t\t\tSORRY! The information is not in!\n");
		}
	}
	char ret[2] = { NULL };
	//system("cls");
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
		system("cls");
		/*pinf *pphead_inf;
		int role;
		sea_inf(&pphead_inf, &role);*/
		return;
	}

}