/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:43:32 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 13:20:20 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
	Description			The C library function int tolower(int c) converts a given letter to lowercase.

	Prototype			int tolower(int c);

	Parameters			c − This is the letter to be converted to lowercase.

	Return Value		This function returns lowercase equivalent to c, if such value exists, else c remains unchanged. The value is returned as an int value that can be implicitly casted to char.

 */
int	ft_tolower(int c)
{
	int	lower_case;

	lower_case = c + 32;
	if (lower_case >= 97 && 122 >= lower_case)
		return (lower_case);
	return (c);
}
