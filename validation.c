/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:15:22 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/05 16:28:23 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_the_data_out(char *data, int *visibility, int side_size)
{
	int	index;

	index = 0;
	while (*data != '\0')
	{
		if ((int) '0' <= (int) *data && (int) *data <= (int) 48 + side_size)
		{
			visibility[index] = *data;
			index++;
		}
		data++;
	}
}

int	validate_range(char *data, int side_size)
{
	while (*data != '\0')
	{
		if ((int) ' ' == (int) *data)
			data++;
		else if ((int) *data <= 48 + side_size)
			data++;
		else
		{
			write(1, &"Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	validate_data(int argsc, char *data)
{
	int	counter;

	if (argsc <= 1)
	{
		write(1, &"Error\n", 6);
		return (0);
	}
	counter = 0;
	while (*data != '\0')
	{
		if ((int) '1' <= (int) *data && (int) *data <= (int) '9')
		{
			counter++;
		}
		else if ((int) ' ' != (int) *data)
		{
			return (0);
		}
		data++;
	}
	return ((int)(counter / 4));
}
//return 0 when data has invalid characters
//that is characters outside of '1' - '4'
//otherwise returns square root of number of arguments
//which is equal to our grid side lenght
//by default it will be 4
