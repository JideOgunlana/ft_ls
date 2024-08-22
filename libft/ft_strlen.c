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
