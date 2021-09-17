/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:20:24 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/17 20:54:10 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_qsort(int *start, int *end)
{
	int	*pivot;
	int	*left;
	int	*right;

	if (start >= end)
		return ;
	pivot = start;
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && *left <= *pivot)
			left++;
		while (right > start && *right >= *pivot)
			right--;
		if (left >= right)
			ft_swap(right, pivot);
		else
			ft_swap(left, right);
	}
	ft_qsort(start, right - 1);
	ft_qsort(right + 1, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_qsort(tab, tab + size);
}
