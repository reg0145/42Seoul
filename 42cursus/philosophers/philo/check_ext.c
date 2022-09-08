/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:07 by donghyuk          #+#    #+#             */
/*   Updated: 2022/09/08 14:52:43 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

int	check_count(t_rule	*rule)
{
	if (rule == NULL)
		return (0);
	if (rule->size == 0)
		return (0);
	if (rule->max_eat_flag && rule->max_eat_count <= 0)
		return (0);
	return (1);
}
