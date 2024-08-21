/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:15 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:47:43 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 

Description				The C library function void *memset(void *str, int c, size_t n) copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.

Prototype				void *memset(void *str, int c, size_t n)

Parameters				str − This is a pointer to the block of memory to fill.
						c − This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
						n − This is the number of bytes to be set to the value.

Return Value			This function returns a pointer to the memory area str.

*/

void	*ft_memset(void *b, int c, size_t len )
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		*((char *) b + i) = c;
		++i;
	}
	return (b);
}

/* int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_memset(str,'$',7);
   puts(str);
   
   return(0);
} */