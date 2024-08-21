/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:17:30 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:15:07 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* 
	Description			The C library function char *strrchr(const char *str, int c) searches for the last occurrence of the character c (an unsigned char) in the string pointed to, by the argument str

	Prototype			char *strrchr(const char *str, int c)

	Parameters			str − This is the C string.
						c − This is the character to be located. It is passed as its int promotion, but it is internally converted back to char.

	Return Value		This function returns a pointer to the last occurrence of character in str. If the value is not found, the function returns a null pointer.

*/

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*p;

	i = ft_strlen(s);
	p = NULL;
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			p = &s[i];
			break ;
		}
		i--;
	}
	return ((char *)(p));
}

/* int main()
{
    char c[] = "Hello World today";
    int ch = '!';
    char *p = ft_strrchr(c, ch);
    printf(":%c: -> :%s:", ch, p);
} */
