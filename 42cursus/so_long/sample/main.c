/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:21 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/09 18:50:21 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(char *message) {
	printf("%s", message);
	exit(EXIT_SUCCESS);
}


void	ft_check_map(char *str_map) {
	//.ber 확장자여야 한다.
	int	len;

	len = ft_len(str_map);
}

int	main(int argc, char *args[]) {
	if (argc < 2)
		ft_error("please input : ./solong \"map_name.ber\"");

	ft_check_map(args[0]);
	return (0);
}
