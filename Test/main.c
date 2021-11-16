#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strncmp(const char* c, const char* s, size_t a);

int main(void)
{
	char buffer[40];

	printf("%d", ft_strncmp("13","12", 2));
}