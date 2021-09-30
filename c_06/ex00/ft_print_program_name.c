/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:05:57 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/22 17:31:56 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		ft_putstr(argv[0]);
		write(1, "\n", 1);
	}	
}
