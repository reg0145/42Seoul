
int	ft_get_col(char *str){
	int	col;

	col = 0;
	while (*str != '\0' && *str++ != '\n')
		col++;
	return (col);
}

int	ft_get_row(char *str){
	int	row;

	row = 0;
	while (*str != '\0') {
		while (*str != '\0' && *str != '\n')
			str++;
		if (*str != '\0')
			str++;
		row++;
	}
	return (row);
}
