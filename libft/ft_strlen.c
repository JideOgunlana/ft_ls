/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:13:28 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:05:16 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
    Description             The C library function size_t strlen(const char *str) computes the length of the string str up to, but not including the terminating null character.
    
    Prototype               size_t strlen(const char *str)

    Parameters              str − This is the string whose length is to be found.

    Return Value            This function returns the length of string.
 */

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

/* int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','\0'};

    int len  = ft_strlen(a);
    int len2 = ft_strlen(b);

    // using the %zu format specifier to print size_t
    printf("Length of string a = %d \n",len);
    printf("Length of string b = %d \n",len2);

    return 0;
} */