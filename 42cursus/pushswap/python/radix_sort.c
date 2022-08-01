int	*
// m_radix : 최대 기수
// size : 배열 사이즈
void	radix_sort(int *arr, int m_radix, int size)
{
	int	i;
	int j;
	int	n;
	int	z;
	int	cnt;
	int	idx;
	int	*buket[10];
	int	*buket_cnt[10];

	// init
	i = -1;
	while (i < 10)
	{
		buket[i] = malloc(sizeof(int) * size + 1);
		if (!buket[i])
			ft_error("error");
		buket[i][0] = 1;
	}
	// radix_sort
	// n : 자리수
	i = -1;
	while (++i < m_radix)
	{
		j = -1;
		n = 10;
		while (++j < size)
		{
			idx = buket[arr[i] % n];
			cnt = buket[idx][0]++;
			buket[idx][cnt] = arr[i];
		}
		j = -1;
		while (++j < size)
			buket[j][0] = 0;
		n *= n;
	}
}
