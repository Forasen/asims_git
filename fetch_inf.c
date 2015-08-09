#include "main.h"

void fetch_inf(pinf *pphead_inf)
{
	*pphead_inf = NULL;
	FILE *fp;
	fp = fopen("usr_inf.txt", "r");
	pinf pcur_inf;
	pinf pnew_inf;
	pinf pprev_inf;

	while (!feof(fp))
	{
		pnew_inf = (pinf)calloc(1, sizeof(inf));
		if (fscanf(fp, "%s%s%d%d", pnew_inf->usr_id, pnew_inf->usr_nm, &pnew_inf->usr_cs_id, &pnew_inf->usr_cs_score)==4)
		{
			pcur_inf = *pphead_inf;
			pprev_inf = NULL;
			while (pcur_inf != NULL&&strcmp(pnew_inf->usr_id, pcur_inf->usr_id) > 0)
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
		}
	}
}