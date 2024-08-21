

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:26:45 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/24 18:03:28 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
Function name :-    ft_strmapi

Prototype :-     char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));

Parameters:  s: The string on which to iterate.
            f: The function to apply to each character.
    
Return value: The string created from the successive applications of ’f’. Returns NULL if the allocation fails.

External functs. malloc

Description Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’ 
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			(**ptr)(unsigned int, char);
	unsigned int	i;
	char			*str;

	ptr = &f;
	if (!s || !f)
		return (NULL);
	str = (char *) malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*ptr)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}


/* char* ft_strmapi(char const* s, char (*f)(unsigned int, char))
{
	size_t len;
	size_t i;
	char* str;

	i = 0;
	if (!s || !f)
		return (0);
	len = strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
} */


/* char f(unsigned int i, char c)
{
	char str;
	str = c + 1;
	return (str);
}

int main()
{
	char str1[] = "abc";
	char* str2;
    char (*ptr)(unsigned int, char);
    ptr = &f;
	str2 = ft_strmapi(str1, *ptr);
	printf("%s\n", str2);
} */