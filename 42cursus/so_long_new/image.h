#ifndef FT_IMAGE_H
# define FT_IMAGE_H

# define XPM_PLAYER "./imgs/player.xpm"
# define XPM_SPACE "./imgs/space.xpm"
# define XPM_WALL "./imgs/wall.xpm"
# define XPM_GROUND "./imgs/ground.xpm"
# define XPM_ESCAPE_OPEN "./imgs/escape_opened.xpm"
# define XPM_ESCAPE_CLOSE "./imgs/escape_closed.xpm"
# define XPM_COLLECT "./imgs/collect.xpm"

# include "game.h"

void	*ft_parse_xpm_to_img(void *mlx, char *xpm_path);

#endif
