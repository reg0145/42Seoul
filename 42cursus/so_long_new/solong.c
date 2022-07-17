/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:21 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/16 18:12:55 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char *args[])
{
	if (argc < 2)
		ft_error("please input : ./solong map_name.ber");
	ft_start_game(args[1]);
	return (OK);
}
