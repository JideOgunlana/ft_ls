/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:44:57 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/04 13:42:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* 
	Description:			The bzero() function fills the first n bytes of the object pointed to by dst with zero (NUL) bytes.

	Prototype:				void bzero( void *dst, size_t n )

	Parameters:				dst:     an existing object that you want to fill with zeroes.
							n:       The number of bytes to fill.

	No return value
 */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)					// checks if an existing size of byte to zero out exists
	{
		while (i < n)
		{
			*((char *) s + i) = 0;		// casts the object pointed to to a character (because it uses the least memory) data type and zeros it out (makes it empty)
			++i;
		}
	}
	return ;
}
