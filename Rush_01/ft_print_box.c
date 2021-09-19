#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_box(int box[][4])
{
   int i;
   int j;
   i = 0;
   while (i < 4)
   {
	   j = 0;
      while(j < 4)
      {
         ft_putchar(box[i][j] + '0');
         if (j != 3)
			ft_putchar(' ');
		j++;
      }
      ft_putchar('\n');
	  i++;
   }
}