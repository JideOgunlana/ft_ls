/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:48:07 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:40:09 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function void *memcpy(void *dest, const void *src, size_t n) copies n characters from memory area src to memory area dest.

	Prototype				void *memcpy(void *dest, const void * src, size_t n)

	Parameters				dest − This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
							src − This is pointer to the source of data to be copied, type-casted to a pointer of type void*.
							n − This is the number of bytes to be copied.

	Return Value			This function returns a pointer to destination

 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
