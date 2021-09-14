/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:26:46 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/15 00:43:42 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_char_is_lowercase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += ('a' - 'A');
	return (c);
}

char	*ft_char_is_uppercase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= ('a' - 'A');
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	is_new_word;
	int	i;

	i = 0;
	is_new_word = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (is_new_word)
			{
				ft_char_is_uppercase(&str[i]);
				printf("%c!", str[i]);
				is_new_word = 0;
			}
			else
				ft_char_is_lowercase(&str[i]);
		}
		else if ((str[i] < '0' || str[i] > '9'))
			is_new_word = 1;
		i++;
	}
	return (str);
}
