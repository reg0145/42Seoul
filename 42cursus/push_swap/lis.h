/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:07:16 by donghyuk          #+#    #+#             */
/*   Updated: 2022/08/06 19:17:59 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIS_H
# define LIS_H

# include "libft.h"
# include "error.h"

typedef struct s_lis
{
	int	*arr;
	int	size;
}	t_lis;

int	ft_max(int a, int b);
int	ft_max_list(int *lst, int len);

#endif
