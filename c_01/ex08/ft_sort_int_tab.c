/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:20:24 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/15 00:27:18 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_qsort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
		{
			i++;
		}
		while (j > start && arr[j] >= arr[pivot])
		{
			j--;
		}
		if (i >= j)
			break;
		ft_swap(&arr[i], &arr[j]);
	}
	ft_swap(&arr[pivot], &arr[j]);
	ft_qsort(arr, start, j - 1);
	ft_qsort(arr, j + 1, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_qsort(tab, 0, size - 1);
}
