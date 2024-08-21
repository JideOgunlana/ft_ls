/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:30:51 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/04 14:24:41 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description:		The C library function int isdigit(int c) checks if the passed character is a decimal digit character. Decimal digits are (numbers) − 0 1 2 3 4 5 6 7 8 9.

	Prototype:			int isdigit(int c);

	Parameters			c − This is the character to be checked.

	Return Value		This function returns non-zero value if c is a digit, else it returns 0.	
 */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
