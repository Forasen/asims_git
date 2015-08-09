#include "main.h"

char* load_path(char* path)
{
	FILE *fp;
	if ((fp = fopen(*path, "r")) != NULL)
	{
		fprintf(stderr, "file open error!\n");
		return 1;
	}
	char line[2][128];
	int cnt = 0;
	while (memset(line[cnt], 0, sizeof(line[cnt])), fgets(line, sizeof(line[cnt]), fp) != EOF)
	{
		line[cnt++][strlen(line[cnt]) - 1] = '\0';

	}
	return line;

	fclose(fp);
}