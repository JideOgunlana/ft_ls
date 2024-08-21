/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:24:30 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:25:17 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
Description				The C library function char *strlcat(char *dest, const char *src, size_t dstsize) appends the string pointed to by src to the end of the string pointed to by dest.
						strlcat() take the full size of the buffer (not just the length) and guarantee to NUL-terminate the result, as long as there's at least one byte free in dst

Prototype				char *strlcat(char *dest, const char *src, size_t dstsize)

Parameters				dest − This is pointer to the destination array, which should contain a C string, and should be large enough to contain the concatenated resulting string.
						src − This is the string to be appended. This should not overlap the destination.
						dstsize - The size of the destination buffer.

Return Value			For strlcat() that means the initial length of dst plus the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple. 

 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	s_len;
	unsigned int	d_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dstsize == 0)
		return (s_len);
	if (dstsize <= d_len)
		return (s_len + dstsize);
	while (src[i] != '\0' && d_len + i < dstsize - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/* int main () {
   char src[50], dest[50];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   strcat(dest, src);

   printf("Final destination string : |%s|", dest);
   
   return(0);
} */