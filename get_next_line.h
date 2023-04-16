/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:18:43 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/16 15:34:29 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
char	*get_next_line(int fd);
char  *read_line(int fd, char *str);
int find_newline(char *buffer, int size);
// int find_newline(char *buffer);
void	*ft_memcpy(void *dest, void *src, unsigned int n);
size_t	ft_strlen(const char *s);
void copy_data(char **output, char *buffer, int len);
void	*ft_memmove(void *dest, void *src, size_t len);
#endif
