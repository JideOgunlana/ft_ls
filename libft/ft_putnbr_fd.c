/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:17:40 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 11:52:27 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name                           ft_putnbr_fd

Prototype                               void ft_putnbr_fd(int n, int fd);

Parameters                              n:The integer to output.
                                        fd: The file descriptor on which to write.

Return value                            None

External functs.                        write

Description                             Outputs the integer ’n’ to the given file descriptor
*/

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		n = (n % 10) + '0';
		write(fd, &n, 1);
	}
}
