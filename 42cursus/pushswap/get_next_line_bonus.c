#include "get_next_line_bonus.h"

void	ft_free_node(t_lst **head, t_lst *cur_node)
{
	t_lst	*prev;

	prev = *head;
	if (prev != cur_node)
		while (prev->next != cur_node)
			prev = prev->next;
	prev->next = cur_node->next;
	if (cur_node->buf != NULL)
	{
		free(cur_node->buf);
		cur_node->buf = NULL;
	}
	if (prev == *head)
		*head = NULL;
	if (cur_node != NULL)
	{
		free(cur_node);
		cur_node = NULL;
	}
}

char	*ft_process_signal(t_lst *cur_node, int size)
{
	char	*result;
	char	*temp;

	temp = ft_gnl_strchr(cur_node->buf, '\n');
	size = temp - cur_node->buf + 1;
	result = ft_gnl_strnjoin(NULL, cur_node->buf, size);
	if (!result)
		return (NULL);
	temp = ft_gnl_strjoin(NULL, cur_node->buf + size);
	if (!temp)
		return (NULL);
	free(cur_node->buf);
	if (ft_gnl_strlen(temp) == 0)
	{
		free(temp);
		cur_node->buf = NULL;
	}
	else
		cur_node->buf = temp;
	return (result);
}

int	ft_read_node(t_lst *cur_node, char	ch)
{
	char	*buf;
	char	*temp;
	int		size;

	if (ft_gnl_strchr(cur_node->buf, ch) != NULL)
		return (1);
	buf = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	while (1)
	{
		size = read(cur_node->fd, buf, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buf[size] = '\0';
		temp = ft_gnl_strjoin(cur_node->buf, buf);
		if (temp == NULL)
			return (-1);
		free(cur_node->buf);
		cur_node->buf = temp;
		if (ft_gnl_strchr(buf, ch) != NULL)
			break ;
	}
	free(buf);
	return (size);
}

t_lst	*ft_find_or_create_node(t_lst **head, int fd)
{
	t_lst	*cur_node;

	if (*head == NULL)
	{
		*head = (t_lst *)ft_gnl_calloc(1, sizeof(t_lst));
		(*head)->fd = fd;
		if (*head == NULL)
			return (NULL);
		cur_node = *head;
	}
	else
	{
		cur_node = *head;
		while (cur_node != NULL && cur_node->fd != fd)
			cur_node = cur_node->next;
		if (cur_node->fd != fd)
		{
			cur_node->next = (t_lst *)ft_gnl_calloc(1, sizeof(t_lst));
			if (cur_node->next == NULL)
				return (NULL);
			cur_node->next->fd = fd;
		}
	}
	return (cur_node);
}

char	*get_next_line(int fd)
{
	static t_lst	*head;
	t_lst			*cur_node;
	int				size;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cur_node = ft_find_or_create_node(&head, fd);
	if (cur_node == NULL)
		return (NULL);
	size = ft_read_node(cur_node, '\n');
	if (size == -1 || size == 0)
	{
		if (size == 0)
		{
			result = ft_gnl_strjoin(NULL, cur_node->buf);
			if (result != NULL)
				return (result);
		}
		ft_free_node(&head, cur_node);
		return (NULL);
	}
	return (ft_process_signal(cur_node, size));
}
