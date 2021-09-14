/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:26:46 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/14 23:46:00 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_char_is_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + ('a' - 'A');
	return c;
}

char	ft_char_is_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');
	return c;
}

char	*ft_strcapitalize(char *str)
{
	int	is_new_word;
	int	index;
	
	index = 0;
	is_new_word = 1;
	while (str[index] != '\0')
	{
		if (str[index] == ' ')
			is_new_word = 1;
		else if (is_new_word)
			str[index] = ft_char_is_uppercase(str[index]);
		else
			str[index] = ft_char_is_lowercase(str[index]);
	}
}