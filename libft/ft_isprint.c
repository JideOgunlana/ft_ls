/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:52:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/04 15:04:56 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function int isprint(int c) checks whether the passed character is printable. A printable character is a character that is not a control character.
	
	Prototype:				int isprint(int c);

	Parameters				c − This is the character   to be checked.

	Return Value			This function returns a non-zero value(true) if c is a printable character else, zero (false).
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}
