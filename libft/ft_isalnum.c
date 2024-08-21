/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:36:22 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:20:20 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function int isalnum(int c) checks if the passed character is alphanumeric.
	
	Prototype:				int isalnum(int c);

	Parameters				c − This is the character to be checked.

	Return Value			This function returns non-zero value if c is a digit or a letter, else it returns 0.
 */

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) || (ft_isdigit(c)))
		return (1);
	else
		return (0);
}

// int main()
// {
//     char c = '3';
//     printf("%d",ft_isalnum(c));
//     return (0);
// }