#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	write(1, "test", 4);
	write(1, argv[1], 1);
	if (!printf("%ld", strlen(argv[1])))
		printf("fail");
	printf("end");
}
