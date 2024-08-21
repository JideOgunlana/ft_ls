/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:29:53 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:21:45 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Description			The C library function int toupperr(int c) converts a given letter to upperrcase.

	Prototype			int toupper(int c);

	Parameters			c − This is the letter to be converted to lowercase.

	Return Value		This function returns uppercase equivalent to c, if such value exists, else c remains unchanged. The value is returned as an int value that can be implicitly casted to char.

 */

int	ft_toupper(int c)
{
	int	upper_case;

	upper_case = c - 32;
	if (upper_case >= 65 && upper_case <= 90)
		return (upper_case);
	else
		return (c);
}

/* int main()
{
    char c = 'a';
    printf("%c", c);
    int b = ft_toupper(c);
    printf("%c", b);
    printf("%c", 80);
    return (0);
} */