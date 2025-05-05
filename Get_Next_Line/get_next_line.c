/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:02:37 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/24 09:07:00 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (text);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*get_a_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(*text));
	if (!str)
		return (NULL);
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_first_line(fd, text);
	if (!text)
		return (NULL);
	output_text = get_a_line(text);
	text = clean_first_line(text);
	return (output_text);
}

int	main(void)
{
	int		fd;
	int	i;
	int	j;
	char	*line;
	
	i = 1;
	j = 0;
	fd = open("Example.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error cannot open it");
		return (1);
	}
	
	while((line = get_next_line(fd)) != NULL)
	{
		printf("This is the %d extracted line",i);
		printf("Result : %s", line);
		i++;
		j++;
		free(line);
	}
	
	close(fd);
	return (0);
}
