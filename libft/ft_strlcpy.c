/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:39:28 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:01:32 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description:			The strlcpy() and strlcat() functions copy and concatenate strings respectively. They're designed to be safer, more consistent, and less error-prone replacements for strncpy() and strncat(). Unlike those functions, strlcpy() and strlcat() take the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than 0 or, in the case of strlcat(), as long as there's at least one byte free in dst). 

	Parameters:
				dst
    				A pointer to the destination string.
				src
					A pointer to the source string.
				size
					The size of the destination buffer.

	Returns:

		The total length of the string:
    	For strlcpy() that means the length of src.
    	For strlcat() that means the initial length of dst plus the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple.


 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t) ft_strlen(src));
}
