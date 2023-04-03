#include "factor.h"

int main(int ac, char **av)
{
	FILE *fp;
	char line[1024];
	ull num;
	ull f_prime1, f_prime2;
	int i;

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
		f_prime1 = find_factor1(num);
		f_prime2 = find_factor2(num, f_prime1);
		printf("%llu=%llu*%llu\n", num, f_prime2, f_prime1);
	}
	fclose(fp);
	return(0);
		
}

ull find_factor1(ull num)
{
	ull f1;

	for(f1 = 2; f1 < num; f1++)
	{
		if (num % f1 == 0 && check_prime(f1) == 1)
			return( f1);
	}
	return (0);
}
ull find_factor2(ull num, ull f1)
{
	ull f2;

	f2 = num / f1;

	if (num % f2 == 0 && check_prime(f2) == 1)
		return(f2);

	return (0);
}

int check_prime(ull n)
{
	if (n < 2) 
        	return (0);
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
            		return (0);
        }
	return (1);
}
