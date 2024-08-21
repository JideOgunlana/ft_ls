

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:06:56 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/24 17:44:59 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name:                          ft_putendl_fd

Prototype:                              void ft_putendl_fd(char *s, int fd);

Parameters                              s: The string to output.
                                        fd: The file descriptor on which to write.

Return value:                           None

External functs.                        write

Description                             Outputs the string ’s’ to the given file descriptor followed by a newline. 

*/

#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
