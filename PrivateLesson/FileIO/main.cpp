#include <stdio.h>

int main()
{
	FILE *fp;
	int x = 0;
	int y = 0;
	char buffer[30];

	fopen_s(&fp, "map.txt", "rt");

	if (fp == 0)
	{
		printf("Can't open File \n");
	}

	fscanf_s(fp, "%d %d", &x, &y, sizeof(x) + sizeof(y));
	printf("x: %d y: %d \n", x, y);

	for (int i = 0; i < y; i++)
	{
		fscanf_s(fp, "%s \n", buffer, sizeof(buffer));
		printf("buffer: %s \n", buffer);
	}

	fclose(fp);

	return 0;
}