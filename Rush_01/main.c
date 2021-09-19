#include <stdio.h>
#include <stdlib.h>

int g_MAX = 4; 

int g_box[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int	g_visible[4][4] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
int g_row[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int g_col[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void input();
void print_sudoku();
void DFS(int n, int **box);
int cal_up(int *i, int n);
int cal_down(int *i, int n);
int cal_left(int *i, int n);
int cal_right(int *i, int n);

int *get_arr(int **box, int x, int y, int type)
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

int check(int n, int **box, int x, int y)
{
	int	*arr;
	
	arr = get_arr(box, x, y, 0);
	arr[x] = n + 1;
	if (cal_up(arr, y))
	{
	    printf("up true\n");
		arr = get_arr(box, x, y, 1);
		arr[x] = n + 1;
		if(cal_down(arr, y))
		{
			arr = get_arr(box, x, y, 3);
			arr[y] = n + 1;
			if(cal_left(arr, x))
			{
				arr = get_arr(box, x, y, 4);
				arr[y] = n + 1;
				if(cal_right(arr, x))
					return 1;
			}
		}
	}	
	return 0;
}

void get_info(char *ptr, int **g_visibl)
{
   int i;
   int j;
   int index;
   i = 0;
   index = 0;
   while (i < g_MAX)
   {
	   j = 0;
      while (j < g_MAX)
      {
         g_visible[i][j] = ptr[index] - '0';
//		 ft_putchar(g_visible[i][j]+'0');
		 index += 2;
         j++;
      }
      i++;
   }
}
int cal_up(int *i, int n)
{
    int j;
	int max;
	int cnt;
	j = 0;
	max = i[j];
	cnt = 1;
	printf("[%d] ", g_visible[0][n]);
	for(int m =0; m < 4; m++)
	{
	    printf("%d " , i[m]);
	}
	printf("\n");
	while (j < g_MAX)
	{
		if (!i[j])
			return (1);
		if (max < i[j])
		{
			cnt += 1;
			max = i[j];
		}
		j++;
        if (g_visible[0][n] < cnt)
            return(0);
	}
	if (g_visible[0][n] != cnt)
		return (0);
	else
		return (1);
}
int	cal_down(int *i, int n)
{
	int	j;
	int	max;
	int	cnt;
	j = g_MAX - 1;
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
        if (g_visible[1][n] < cnt)
            return(0);
	}
	if (g_visible[1][n] != cnt)
		return (0);
	else
		return (1);
}
int cal_left(int *i, int n)
{
    int j;
	int max;
    int cnt;
	j = 0;
	max = i[0];
	cnt = 1;
	while (j < g_MAX)
	{
		if (!i[j])
			return (1);
		if (max < i[j])
		{
			cnt += 1;
			max = i[j];
		}
        if (g_visible[2][n] < cnt)
            return(0);
		j++;
	}
	if(g_visible[2][n] != cnt)
		return(0);
	else
		return(1);
}
int cal_right(int *i, int n)
{
    int j;
	int max;
    int cnt;
	j = g_MAX - 1;
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
		if (g_visible[3][n] < cnt)
            return(0);
		j--;
	}
	if(g_visible[3][n] != cnt)
		return(0);
	else
		return(1);
}

void print_box(int **box)
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

void init(int **box)
{
	int i;
	int j;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			box[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*ptr;
	int		**visible;
	int		**box;
	int		i;
	/*
	if (ft_error(argc, argv))
		write(1, "error\n", 6);
	
	ptr = argv[1];
	*/
	visible = (int **)malloc(4 * sizeof(int *));
	box = (int **)malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
	{
		visible[i] = (int *)malloc(4 * sizeof(int));
		box[i] = (int *)malloc(4*sizeof(int));
		i++;
	}
	//git_info(ptr, visible);	
	//init(box);
	//if (check_box(box, visible))
	//	print_box(box);
	DFS(0, box);
	
	return (0);	
}

void DFS(int n, int **box){
    if (n==16) {
        print_box(box);
        exit(0);
    }
    int x = n/g_MAX;
    int y = n%g_MAX;
    if (box[x][y] == 0){
        for (int i=0; i<4; i++){
            if (!g_row[x][i] && !g_col[y][i] && check(i, box, x, y))
            {
                g_row[x][i] = 1;
				g_col[y][i] = 1;
                box[x][y] = i + 1;
                //printf("\n");
                //print_box(box);
                DFS(n+1, box);
                box[x][y] = 0;
                g_row[x][i] = 0;
				g_col[y][i] = 0;
            }
        }
    }
    else DFS(n+1, box);
}