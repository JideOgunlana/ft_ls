/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:04:50 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:43:07 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function void *memmove(void *str1, const void *str2, size_t n) copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy().
	
	Prototype:				void *memmove(void *str1, const void *str2, size_t n);

	Parameters				str1 − This is a pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
							str2 − This is a pointer to the source of data to be copied, type-casted to a pointer of type void*.
							n − This is the number of bytes to be copied.

	Return Value			This function returns a pointer to the destination, which is str1
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*s;
	char			*d;
	unsigned int	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (dst);
	if (d > s)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}	
	}
	return (dst);
}
