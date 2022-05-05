#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 261102 + 8

int main(int argc, char *argv[])
{
	int	cnt;
	int	shift;
	char	ch;
	int	i;
	char	test[MAX] = "./test2 ";

	memset(test + 8 ,'a', MAX - 8);
	test[MAX - 1] = '\0';
	/*
	if (argc == 2)
	{
		//printf("%s", stringToBinary(argv[1]));
		if ((argv[1][0] & 0xF0) == 0xF0)
			write(1, argv[1], 5);
		else if ((argv[1][0] & 0xE0) == 0xE0)
			write(1, argv[1], 4);
		else if ((argv[1][0] & 0xC0) == 0xC0)
			write(1, argv[1], 3);
		else
			write(1, argv[1], 2);
		//
	}
	*/
	//printf("%s", test);
	system(test);
}
