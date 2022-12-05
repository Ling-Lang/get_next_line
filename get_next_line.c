/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:18:38 by jkulka            #+#    #+#             */
/*   Updated: 2022/12/05 15:21:20 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buf[2000];
	size_t nbytes;
	ssize_t bytes_read;
	int i = 0;
	
	nbytes = sizeof(buf);
	bytes_read = read(fd, buf, nbytes);
	while(buf != '\n')
	{
		i++;
	}
	return (buf);
}

#include<fcntl.h>
#include<fcntl.h>
#include <stdio.h>
int main()
{

	const char *test;
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}