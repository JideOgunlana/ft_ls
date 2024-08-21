/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:04:45 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:09:57 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:            The C library function int isalpha(int c) checks if the passed character is alphabetic.

Prototype:              int isalpha(int c);

Parameters              c − This is the character to be checked.

Return Value:           This function returns non-zero value if c is an alphabet, else it returns 0.

*/
#include "../includes/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/* int main()
{
    int value;
    value = ft_isalpha('z');
    if(value == 1)
    {
        printf("I am upperCase");
    }
    else if(value == 2)
    {
        printf("I am lowercase");
    }
    else
    {
        printf("I am not an alphabet");
    }

    // ft_printAlphabet();
    return (0);
} */