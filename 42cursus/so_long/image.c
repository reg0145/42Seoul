/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:53:41 by donghyuk          #+#    #+#             */
/*   Updated: 2022/07/18 02:53:42 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_parse_xpm_to_img(void *mlx, char *xpm_path)
{
	void	*img;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(mlx, xpm_path, &x, &y);
	if (!img)
		return (NULL);
	return (img);
}
