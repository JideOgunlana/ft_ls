/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:46:05 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:23:11 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description:			The isascii() function tests if a given character, in the current locale, can be represented as a valid 7–bit US-ASCII character.

	Return Value			The isascii() function returns nonzero if c, in the current locale, can be represented as a character in the 7–bit US-ASCII character set. Otherwise, it returns 0.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
