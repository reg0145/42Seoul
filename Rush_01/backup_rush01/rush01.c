#include <unistd.h>

int	ft_dfs(int n, int box[][4], int col[][4], int row[][4], int visible[][4]);
void	print_box(int box[][4]);

void	get_info(char *ptr, int visible[][4])
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			visible[i][j] = ptr[index] - '0';
			index += 2;
			j++;
		}
		i++;
	}
}

void	set_array(int box[][4], int visible[][4], int col[][4], int row[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			box[i][j] = 0;
			visible[i][j] = 0;
			col[i][j] = 0;
			row[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*ptr;
	int		visible[4][4];
	int		box[4][4];
	int		col[4][4];
	int		row[4][4];

//	if (ft_error(argc, argv))
//		write(1, "error\n", 6);	
	if (argc == 2)
	{
		ptr = argv[1];
		set_array(box, visible, col, row);
		get_info(ptr, visible);
		if (ft_dfs(0, box, col, row, visible))
			return (1);
	}
	return (0);
}
