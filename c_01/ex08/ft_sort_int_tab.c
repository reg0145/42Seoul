/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:20:24 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/18 09:19:44 by donghyuk         ###   ########.fr       */
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
	int	left;
	int	right;

	if (start >= end)
		return ;
	pivot = start;
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
			ft_swap(&arr[right], &arr[pivot]);
		else
			ft_swap(&arr[left], &arr[right]);
	}
	ft_qsort(arr, start, right - 1);
	ft_qsort(arr, right + 1, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_qsort(tab, 0, size - 1);
}
