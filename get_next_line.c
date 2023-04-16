/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:18:38 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/15 14:09:37 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE + 1];
    char *output = NULL;
    int newline_pos;
    int read_ret;

    newline_pos = find_newline(buffer, BUFFER_SIZE);
    if (newline_pos >= 0) {
        copy_data(&output, buffer, newline_pos + 1);
        ft_memmove(buffer, buffer + newline_pos + 1, BUFFER_SIZE - newline_pos);
        return output;
    }

    while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[read_ret] = '\0';

        newline_pos = find_newline(buffer, read_ret);
        if (newline_pos >= 0) {
            copy_data(&output, buffer, newline_pos + 1);
            ft_memmove(buffer, buffer + newline_pos + 1, read_ret - newline_pos);
            return output;
        } else {
            copy_data(&output, buffer, read_ret);
        }
    }

    if (read_ret == -1) {
        free(output);
        return NULL;
    }

    return output;
}


// #include<fcntl.h>
// #include<fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd = open("multiple_line_with_nl", O_RDONLY);
//     get_next_line(fd);
//     char *gnl_return = get_next_line(fd);
//     char *expected = "34567890123456789012345678901234567890";
// 	// printf("%s", get_next_line(fd));
//     if(gnl_return == expected)
//         printf("OK");
//     else
//         printf("KO");
//   
// }
