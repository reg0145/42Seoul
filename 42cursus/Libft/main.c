#include <stdio.h>
#include <string.h>
#include "libft.h"
//#define TEST(X,Y,Z) printf("%d\n", strncmp(X,Y,Z))
//#define TEST(X,Y) printf("[%p] : %s\n", strchr(X,Y), strchr(X,Y))
//#define TEST(X,Y) printf("[%p] : %s\n", strchr(X,Y), strrchr(X,Y))
//#define TEST(X) printf("[%p] : %s , %ld\n", strdup(X), strdup(X), strlen(strdup(X)))
//char	*ft_strchr(const char *s, int c);
//#define TEST(X,Y) printf("[%p] : %s , %ld\n", strjoin(X,Y), strjoin(X,Y), strlen(strjoin(X,Y)))
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//#define TEST(X,Y) printf("[%p] : %s , %ld\n", strtrim(X,Y), strtrim(X,Y), strlen(strtrim(X,Y)))
char	*ft_strtrim(char const *s1, char const *set);

int main(void)
{
	//TEST(NULL, NULL, 0);
	//TEST(NULL, NULL, 10);
	//TEST("", NULL, 10);
	//TEST(NULL, "", 10);
	//ft_substr(NULL, 0, 0);
	printf("%s", ft_strtrim("         "," "));
	//TEST(NULL,0,0);
}
