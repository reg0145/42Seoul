#include <unistd.h>

int	ft_check(int i, int box[][4], int xy[2], int visible[][5]);
int	ft_dfs(int box[][4], int c[][4], int r[][4], int vib[][5]);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_box(int box[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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

int	ft_dfs_at(int box[][4], int c[][4], int r[][4], int vib[][5])
{
	int i;
	int xy[2];
	xy[0] = vib[0][4] / 4;
	xy[1] = vib[0][4] % 4;
	if (box[xy[0]][xy[1]] == 0)
	{
		i = -1;
		while (i < 4)
		{
			if (!r[xy[0]][i] && !c[xy[1]][i] && ft_check(i, box, xy, vib))
			{
				r[xy[0]][i] = 1;
				c[xy[1]][i] = 1;
				box[xy[0]][xy[1]] = i + 1;
				vib[0][4]++;
				if (ft_dfs(box, c, r, vib))
					return (1);
				vib[0][4]--;
				box[xy[0]][xy[1]] = 0;
				r[xy[0]][i] = 0;
				c[xy[1]][i] = 0;
			}
		}
	}
	else
	{
		vib[0][4]++;
		ft_dfs(box, c, r, vib);
		vib[0][4]--;
	}
	return (0);
}

int	ft_dfs(int box[][4], int c[][4], int r[][4], int vib[][5])
{
	if (vib[0][4] == 16)
	{
		ft_print_box(box);
		return (1);
	}
	ft_dfs_at(box, c, r, vib);
	return (0);
}
