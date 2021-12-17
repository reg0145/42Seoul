#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
	int	 i, len;
	char *type[8] = {"c\n", "s\n", "p\n", "d\n", "i\n", "x\n", "X\n", "%%\n"};
	char	*temp;

/********************************/
 /*TEST*/
	char *flag_test = "%%-10";
/*********************************/

	i = 0;
	temp = (char *)calloc(30 , sizeof(char));
	while (i < 8)
	{
		temp = strcat(strcat(temp, flag_test), type[i]);
		printf(temp, 'a',100);
		i++;
	}
}
