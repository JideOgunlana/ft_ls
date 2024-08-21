/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:59:43 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:36:24 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description				The C library function int memcmp(const void *str1, const void *str2, size_t n)) compares the first n bytes of memory area str1 and memory area str2.

	Prototype:				int memcmp(const void *str1, const void *str2, size_t n)

	Parameters				str1 − This is the pointer to a block of memory.
							str2 − This is the pointer to a block of memory.
							n − This is the number of bytes to be compared.

	Return Value			if Return value < 0 then it indicates str1 is less than str2.
							if Return value > 0 then it indicates str2 is less than str1.
							if Return value = 0 then it indicates str1 is equal to str2.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	unsigned int	i;
	unsigned int	val;

	val = 0;
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (val);
	while ((i < n - 1) && (ps1[i] == ps2[i]))
		i++;
	val += ps1[i] - ps2[i];
	return (val);
}

/* int main()
{
    char s1[] = "hello";
    char s2[] = "";
    int ret = ft_memcmp(s1, s2, 2);
    printf("%d", ret);
    return 0;
} */