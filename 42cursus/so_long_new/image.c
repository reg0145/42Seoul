#include "image.h"

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
