/*
** EPITECH PROJECT, 2018
** GNL
** File description:
** main
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*remalloc(int len, char *tab)
{
	char	*save;
	int	index = 0;

	save = malloc(sizeof(char) * (len * READ_SIZE) + 1);
	while (index < ((len - 1) * READ_SIZE))
	{
		save[index] = tab[index];
		index++;
	}
	free(tab);
	save[(len * READ_SIZE)] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	static char	buff[READ_SIZE + 1];
	static int	i_buff = 0;
	static int	rd = 0;
	static int	already = 0;
	char	*tab = NULL;
	int	i = 0;
	int	nbm = 1;
	int	len = 1;

	tab = malloc(sizeof(char) * READ_SIZE + 1);
	if (tab == NULL) {
		return (NULL);
	}
	if (already == 0) {
		rd = read(fd, buff, READ_SIZE);
		buff[rd] = '\0';
		already = 1;
	}
	while(buff[i_buff] != '\n' && rd != 0 ) {
		if (buff[i_buff] == '\0') {
			rd = read(fd, buff, READ_SIZE);
			len++;
			tab = remalloc(len, tab);
			buff[rd] = '\0';
			i_buff = 0;
		} else {
			tab[i] = buff[i_buff];
			i_buff++;
			i++;
		}
	}
	tab[i] = '\0';
	if (rd == 0 && tab[0] == '\0')
		return (NULL);
	i_buff++;
	return (tab);
}

/*int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*s = get_next_line(fd);

	while (s) {
		printf("%s\n", s);
		free(s);
		s = get_next_line(fd);
	}
	return (0);
	}*/
