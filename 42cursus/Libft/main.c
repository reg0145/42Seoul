#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#define SIZE 40

int main(void)
{
  char buf[SIZE] = "";
  char buf2[SIZE] = "";
  char * ptr;
  int    ch = 'p';

  /* This illustrates strrchr */
  printf("strnstr : %zu\n", strlcpy(buf, "pusdfg", 0));
  printf("strnstr : %s\n", buf);

  printf("strnstr : %zu\n", ft_strlcpy(buf2, "pusdfg", 0));
  printf("strnstr : %s\n", buf2);

}

