/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:49:04 by donghyuk          #+#    #+#             */
/*   Updated: 2021/09/21 22:41:20 by donghyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	s;
	int	len;

	if (*to_find == '\0')
		return (str);
	len = ft_strlen(to_find);
	s = 0;
	while (str[s] != '\0')
	{
		if (str[s] == *to_find)
		{
			if (ft_strncmp(&str[s], to_find, len) == 0)
				return (&str[s]);
		}
		s++;
	}
	return (0);
}
