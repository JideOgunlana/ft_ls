/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:22:40 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:33:44 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function void *memchr(const void *str, int c, size_t n) searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.
	
	Prototype:				void *memchr(const void *str, int c, size_t n)

	Parameters				str − This is the pointer to the block of memory where the search is performed.
							c − This is the value to be passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value.
							n − This is the number of bytes to be analyzed.

	Return Value			This function returns a pointer to the matching byte or NULL if the character does not occur in the given memory area.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*pstr;
	unsigned char	*ret;
	unsigned int	i;

	ch = (unsigned char)c;
	ret = NULL;
	pstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (pstr[i] == ch)
		{
			ret = &pstr[i];
			break ;
		}
		i++;
	}
	return (ret);
}
