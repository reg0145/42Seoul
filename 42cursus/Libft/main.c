#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
#define SIZE 40

int main(void)
{
  char buf[SIZE] = "a,b,c,d,e,f,g,h,";
  char buf2[SIZE] = "";
  char ** ptr;
  int    ch = 'p';

  /* This illustrates strrchr */
  ptr = ft_split(buf, ',');
  for (int i = 0; ptr[i] != NULL; i++)
  {
	  printf("%s", ptr[i]);
  }
  printf("strnstr : %zu\n", split(buf, ",", 0));
}

