/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:21:13 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/06 16:21:18 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //For write function

void	display(int *grid, int side)
{
	int	y;
	int	x;
	int	display_char;
	int	skip_new_line;

	y = -1;
	skip_new_line = 1;
	display_char = 48;
	while (++y < side)
	{
		x = -1;
		if (!skip_new_line)
			write(1, &"\n", 1);
		skip_new_line = 0;
		while (++x < side)
		{
			display_char = 48 + grid[(y * side) + x];
			write(1, &display_char, 1);
			if (x != side - 1)
				write(1, &" ", 1);
		}
	}
}
//Comment for line 26:
//Display_char has value of 48 + x
//Because 48 is ASCII decimal code for 0
//So shifting it by x results in ASCII code for x
//Assuming that x is a digit from 0 to 9
//
//Comment for line 36:
//4*y because indexes look like this:
// 0  1  2  3
// 4  5  6  7
// 8  9  10 11
// 12 13 14 15
// so x goes from 0-1-2-3 and y goes 0-4-8-12

void	fill_it(int *grid, int side)
{
	int	y;
	int	x;

	y = 0;
	while (y < side)
	{
		x = 0;
		while (x < side)
		{
			grid[(y * side) + x] = (int) 'x' - 48;
			x++;
		}
		y++;
	}
}
//Comment for line 69:
//Once we have some code to actually fill out the grid the line below will be:
//	grid[(y * 4) + x] = 48;
//For now it looks like this:
//	(y + x) % 3
//So the display function shows more than zeros
