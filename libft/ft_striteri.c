

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:31:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/27 15:01:56 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
Function name:   ft_striteri

Prototype:     void ft_striteri(char *s, void (*f)(unsigned int,char*));

Parameters  s: The string on which to iterate.
            f: The function to apply to each character.

Return value None

External functs. None

Description Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to ’f’ to be modified if necessary. 

*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if ((f != NULL) && (s != NULL))
	{
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)(i, s + i);
			i++;
		}
	}
}

/* void f(unsigned int i, char* c)
{
	*c = 'a' + i + 7;
    printf("%c", *c);
}


int main()
{
    char str1[] = "abc";
    void (*ptr)(unsigned int, char*);
    ptr = &f;
	ft_striteri(str1, ptr);
    return (0);
} */