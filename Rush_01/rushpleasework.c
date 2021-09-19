#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	cal_up(int *i, int n, int visible[][4]); 
int	cal_down(int *i, int n, int visible[][4]);
int	cal_left(int *i, int n, int visible[][4]); 
int	cal_right(int *i, int n, int visible[][4]); 
void print_box(int box[][4]);
int *get_arr(int box[][4], int x, int y, int type)
{
	int	*arr;
	int	i;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * 4);
	while(i < 4)
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
	return arr;
}

int check(int n, int box[][4], int x, int y, int visible[][4])
{
	int	*arr;

	arr = get_arr(box, x, y, 0);
	arr[x] = n + 1;
	if (cal_up(arr, y, visible))
	{
		arr = get_arr(box, x, y, 1);
		arr[x] = n + 1;
		if(cal_down(arr, y, visible))
		{
			arr = get_arr(box, x, y, 2);
			arr[y] = n + 1;
			if(cal_left(arr, x, visible))
			{
				arr = get_arr(box, x, y, 3);
				arr[y] = n + 1;
				if(cal_right(arr, x, visible))
					return 1;
			}
		}
	}	
	
	return 0;
	//free(arr)
}

void get_info(char *ptr, int visible[][4])
{
   int i;
   int j;
   int index;

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

int cal_up(int *i, int n, int visible[][4])
{
    int j;
	int max;
	int cnt;
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

int	cal_down(int *i, int n, int visible[][4])
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

int cal_left(int *i, int n, int visible[][4])
{
    int j;
	int max;
    int cnt;

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
	if(visible[2][n] != cnt)
		return(0);
	else
		return(1);
}

int cal_right(int *i, int n, int visible[][4])
{
    int j;
	int max;
    int cnt;

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
	if(visible[3][n] != cnt)
		return(0);
	else
		return(1);
}

void print_box(int box[][4])
{
   int i;
   int j;
   i = 0;
   while (i < 4)
   {
	   j = 0;
      while(j < 4)
      {
         printf("%d", box[i][j]);
         if (j != 3)
			printf(" ");
		j++;
      }
      printf("\n");
	  i++;
   }
}

void DFS(int n, int box[][4], int col[][4], int row[][4], int visible[][4]){
    if (n==16) {
        print_box(box);
        exit(0);
    }
    int x = n / 4;
    int y = n % 4;
    if (box[x][y] == 0){
        for (int i=0; i<4; i++){
            if (!row[x][i] && !col[y][i] && check(i, box, x, y, visible))
            {
                row[x][i] = 1;
				col[y][i] = 1;
                box[x][y] = i + 1;
                DFS(n+1, box, col, row, visible);
                box[x][y] = 0;
                row[x][i] = 0;
				col[y][i] = 0;
            }
        }
    }
    else DFS(n+1, box, col, row, visible);
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
	ptr = argv[1];
	set_array(box, visible, col, row);
	get_info(ptr, visible);	
	DFS(0, box, col, row, visible);
	
	return (0);	
}
