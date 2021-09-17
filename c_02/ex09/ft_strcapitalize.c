/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:26:46 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/17 22:01:45 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	ft_charlowercase(char *c)
{
	if (c != 0)
	{
		if ((*c >= 'A' && *c <= 'Z'))
			*c += 'a' - 'A';
	}
}

void	ft_charupcase(char *c)
{
	if (c != 0)
	{
		if ((*c >= 'a' && *c <= 'z'))
			*c -= 'a' - 'A';
	}
}

char	*ft_strcapitalize(char *str)
{
	int	is_new_word;
	int	index;

	index = 0;
	is_new_word = 1;
	while (str[index] != '\0')
	{
		if (ft_char_is_alphanumeric(str[index]))
		{
			if (is_new_word)
				ft_charupcase(&str[index]);
			else
				ft_charlowercase(&str[index]);
			is_new_word = 0;
		}
		else
			is_new_word = 1;
		index++;
	}
	return (str);
}
