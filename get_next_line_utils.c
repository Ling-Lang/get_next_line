/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:33:10 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/16 15:41:29 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, void *src, unsigned int n)
{
	char			*csrc;
	char			*cdest;
	unsigned int	i;

	csrc = src;
	cdest = dest;
	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

 int find_newline(char *buffer, int size)
 {
   int i;
   if(!buffer)
     return (-1);
   i = 0;
   while(i < size && buffer[i] != '\0' && buffer[i] != '\n')
     i++;
   if (i < size && buffer[i] == '\n')
     return (i);
   else
     return (-1);
 }





void copy_data(char **output, char *buffer, int len)
{
    int output_len;
    char *new_output;

    if (*output == NULL)
    {
        *output = (char *)malloc(len + 2);
        if (*output == NULL)
        {
            return;
        }
        output_len = 0;
    }
    else
    {
        output_len = ft_strlen(*output);
        new_output = (char *)malloc(output_len + len + 2);
        if (new_output == NULL)
        {
            return;
        }
        ft_memcpy(new_output, *output, output_len);
        free(*output);
        *output = new_output;
    }
    ft_memcpy(*output + output_len, buffer, len);
    (*output)[output_len + len] = '\0';
}





void	*ft_memmove(void *dest, void *src, size_t len)
{
	char			*c_src;
	char			*c_dest;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	c_src = (char *)src;
	c_dest = (char *)dest;
	i = 0;
	if ((c_dest > c_src))
	{
		while (len-- > 0)
		{
			c_dest[len] = c_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return ((void *)c_dest);
}
