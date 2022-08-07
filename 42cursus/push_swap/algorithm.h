/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:57 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/05 10:07:57 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "push_swap.h"

void	ft_min_pa_cost(t_cost *min_cost, t_data *data);
void	ft_sort_stack(t_data *data);
void	ft_short_greedy_algorithm(t_data *data);

#endif
