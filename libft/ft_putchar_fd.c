
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:40:48 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/23 23:41:23 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name:              ft_putchar_fd

Prototype:                  void ft_putchar_fd(char c, int fd);

Parameters                  c: The character to output.
                            fd: The file descriptor on which to write.

Return value                None

External functs.:           write
Description:                Outputs the character ’c’ to the given file descriptor.
*/

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
