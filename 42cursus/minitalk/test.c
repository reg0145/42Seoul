#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
int main()
{
	char	*str = "실행중\n";
	static int	data[100];
	int		cnt = 100;

	data[0] = 1;
	while(cnt-- > 0)
	{
		*data >>= 1;
	}
}*/

char* stringToBinary(char* s) {
    if(s == NULL) return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len*8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}
#define MAX 1046354 + 8

int main(int argc, char *argv[])
{
	int	cnt;
	int	shift;
	char	ch;
	int	i;
	char	test[MAX] = "./test2 ";

	memset(test + 8 ,'a', MAX - 9);
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
