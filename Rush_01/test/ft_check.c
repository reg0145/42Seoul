#include <stdlib.h>

int	ft_cal_up(int *i, int n, int vib[][4]);
int	ft_cal_down(int *i, int n, int vib[][4]);
int	ft_cal_left(int *i, int n, int vib[][4]);
int	ft_cal_right(int *i, int n, int vib[][4]);

int	*get_arr(int box[][4], int x, int y, int type)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		if (type == 0)
			arr[i] = box[i][y];
		else if (type == 1)
			arr[i] = box[i][y];
		else if (type == 2)
			arr[i] = box[x][i];
		else if (type == 3)
			arr[i] = box[x][i];
		i++;
	}
	return (arr);
}

int	ft_check(int n, int box[][4], int xy[2], int vib[][4])
{
	int	*arr;

	arr = get_arr(box, xy[0], xy[1], 0);
	arr[xy[0]] = n + 1;
	if (ft_cal_up(arr, xy[1], vib))
	{
		arr = get_arr(box, xy[0], xy[1], 1);
		arr[xy[0]] = n + 1;
		if (ft_cal_down(arr, xy[1], vib))
		{
			arr = get_arr(box, xy[0], xy[1], 2);
			arr[xy[1]] = n + 1;
			if (ft_cal_left(arr, xy[0], vib))
			{
				arr = get_arr(box, xy[0], xy[1], 3);
				arr[xy[1]] = n + 1;
				if (ft_cal_right(arr, xy[0], vib))
					return (1);
			}
		}
	}	
	free(arr);
	return (0);
}

int	ft_cal_up(int *i, int n, int visible[][4])
{
	int	j;
	int	max;
	int	cnt;

	j = 0;
	max = i[j];
	cnt = 1;
	while (j < 4)
	{
		if (!i[j])
			return (1);
		if (max < i[j])
		{
			cnt += 1;
			max = i[j];
		}
		j++;
		if (visible[0][n] < cnt)
			return (0);
	}
	if (visible[0][n] != cnt)
		return (0);
	else
		return (1);
}

int	ft_cal_down(int *i, int n, int visible[][4])
{
	int	j;
	int	max;
	int	cnt;

	j = 3;
	max = i[j];
	cnt = 1;
	while (j >= 0)
	{
		if (!i[j])
			return (1);
		if (max < i[j])
		{
			cnt += 1;
			max = i[j];
		}
		j--;
		if (visible[1][n] < cnt)
			return (0);
	}
	if (visible[1][n] != cnt)
		return (0);
	else
		return (1);
}

int	ft_cal_left(int *i, int n, int visible[][4])
{
	int	j;
	int	max;
	int	cnt;

	j = 0;
	max = i[0];
	cnt = 1;
	while (j < 4)
	{
		if (!i[j])
			return (1);
		if (max < i[j])
		{
			cnt += 1;
			max = i[j];
		}
		if (visible[2][n] < cnt)
			return (0);
		j++;
	}
	if (visible[2][n] != cnt)
		return (0);
	else
		return (1);
}

int	ft_cal_right(int *i, int n, int visible[][4])
{
	int	j;
	int	max;
	int	cnt;

	j = 3;
	max = i[j];
	cnt = 1;
	while (j >= 0)
	{
		if (!i[j])
			return (1);
		if (max < i[j])
		{
			cnt += 1;
			max = i[j];
		}
		if (visible[3][n] < cnt)
			return (0);
		j--;
	}
	if (visible[3][n] != cnt)
		return (0);
	else
		return (1);
}
