/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:06:46 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:09:08 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OK 0
# define FAIL 1

# include "libft.h"
# include "lis.h"
# include "error.h"

typedef struct s_node
{
	int				v;
	int				pri;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	int		big;
	int		small;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_cost
{
	int	all;
	int	a;
	int	b;
}	t_cost;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

void	ft_init(t_data **data);
void	ft_add_stack(t_stack *s, int data);
void	ft_parse(int ac, char *av[], t_stack *a);
void	ft_greedy_algorithm(t_data *data, t_lis *lis);
t_lis	*ft_lis(int *arr, int len);

#endif
