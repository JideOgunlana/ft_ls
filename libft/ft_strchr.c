/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:04:05 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:06:00 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// The C library function char *strchr(const char *str, int c) searches for the first occurrence of the character c (an unsigned char) in the string pointed to by the argument str.
/* 
Parameters
	str − This is the C string to be scanned.
	c − This is the character to be searched in str.

Return Value
	This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found 

*/

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	const char		*p;

	i = 0;
	p = NULL;
	while (1)
	{
		if (s[i] == (char) c)
		{
			p = &s[i];
			break ;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return ((char *)(p));
}
