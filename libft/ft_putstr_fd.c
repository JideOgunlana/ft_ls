/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:55:57 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:24:05 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name:                      ft_putstr_fd

Prototype:                          void ft_putstr_fd(char *s, int fd);

Parameters s:                       The string to output.
                                    fd:The file descriptor on which to write.
									
Return:                             value None

External functs:                    write

Description:                        Outputs the string ’s’ to the given file descriptor.

*/

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
