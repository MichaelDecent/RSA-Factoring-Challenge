#include "factor.h"

int main(int ac, char **av)
{
	FILE *fp;
	char line[1024];
	long int f1, f2;
	long long int num;

	if (ac != 2)
	{
		printf("Usage: factors <file>\n");
		return(1);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("could not open the file %s\n", av[1]);
		return(1);
	}
	while(fgets(line, sizeof(line), fp) != NULL)
	{
		num = strtoll(line, NULL, 10);
		for(f1 = 2; f1 < num; f1++)
		{
			if (num % f1 == 0)
			{
				f2 = num / f1;
				if (num % f2 == 0)
				{
					printf("%lld=%ld*%ld\n", num, f2, f1);
					break;
				}
			}
		}
	}
	fclose(fp);
	return(0);
		

}
