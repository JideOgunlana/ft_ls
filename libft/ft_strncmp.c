/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:13:50 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:08:11 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
/* 
	Description				The C library function int strncmp(const char *str1, const char *str2, size_t n) compares at most the first n bytes of str1 and str

	Prototype				int strncmp(const char *str1, const char *str2, size_t n)

	Parameters				str1 − This is the first string to be compared.
							str2 − This is the second string to be compared.
							n − The maximum number of characters to be compared
	
	Return Value			This function return values that are as follows:
							if Return value < 0 then it indicates str1 is less than str2.
							if Return value > 0 then it indicates str2 is less than str1.
							if Return value = 0 then it indicates str1 is equal to str2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0) && (*s1 == *s2) && (*s1 != '\0'))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


/* int main()
{
    char a[] = "AFcdef";
    char b[] = "AECDEF";

    printf("%d",ft_strncmp(a,b,2));
    return 0;
} */