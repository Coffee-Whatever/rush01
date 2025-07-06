/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:10:39 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/05 16:59:07 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Posible rules:
//RULE 1: If colXtop is equal to n
//towers need to be in an ascending order
//
//RULE 2: If colXbot is equal to 1
//the highest tower needs to be beside it
//
//RULE 3: If colXtop + colXbot = n + 1
//colXtop - 1 is the index of the highest tower
//
//RULE 4: If colXbot is equal to 1 and colXtop equal to 2
//tile next to colXtop is n - 1

void	rule_four(int *grid, int size, int *limits)
{
	int	index;

	index = -1;
	while (++index < size)
	{
		if (limits[index] == 50 && limits[size + index] == 49)
			grid[index] = size - 1;
		if (limits[index] == 49 && limits[size + index] == 50)
			grid[size * (size - 1) + index] = size - 1;
	}
	index = -1;
	while (++index < size)
	{
		if (limits[size * 2 + index] == 50 && limits[size * 3 + index] == 49)
			grid[index * size] = size - 1;
		if (limits[size * 2 + index] == 49 && limits[size * 3 + index] == 50)
			grid[index * size + size - 1] = size - 1;
	}
}

void	rule_three(int *grid, int size, int *limits)
{
	int	index;
	int	condition;
	int	upperbound;

	index = -1;
	while (++index < size)
	{
		upperbound = limits[index];
		condition = upperbound + limits[size + index];
		if ((int)condition == size + 97)
		{
			grid[index + size * (limits[index] - 49)] = size;
		}
	}
	index = -1;
	while (++index < size)
	{
		upperbound = limits[2 * size + index];
		condition = upperbound;
		condition += limits[3 * size + index];
		if ((int)condition == size + 97)
		{
			grid[index * size + upperbound - 49] = size;
		}
	}
}

void	rule_two(int *grid, int size, int *limits)
{
	int	index;

	index = -1;
	while (++index < size)
	{
		if (limits[index] - 48 == 1)
			grid[index] = size;
		if (limits[size + index] - 48 == 1)
			grid[size * (size - 1) + index] = size;
	}
	index = -1;
	while (++index < size)
	{
		if (limits[size * 2 + index] - 48 == 1)
			grid[index * size] = size;
		if (limits[size * 3 + index] - 48 == 1)
			grid[index * size + size - 1] = size;
	}
}

void	rule_one_vertical(int *grid, int size, int *limits)
{
	int	index;
	int	cord_y;

	index = -1;
	while (++index < size)
	{
		cord_y = -1;
		if (limits[index] - 48 == size)
		{
			while (++cord_y < size)
			{
				grid[index + (cord_y * size)] = 1 + cord_y;
			}
		}
		cord_y = -1;
		if (limits[size + index] - 48 == size)
		{
			while (++cord_y < size)
			{
				grid[index + (cord_y * size)] = size - cord_y;
			}
		}
	}
}

void	rule_one_horisontal(int *grid, int size, int *limits)
{
	int	index;
	int	cord_x;

	index = -1;
	while (++index < size)
	{
		cord_x = -1;
		if (limits[2 * size + index] - 48 == size)
		{
			while (++cord_x < size)
			{
				grid[(index * size) + cord_x] = 1 + cord_x;
			}
		}
		cord_x = -1;
		if (limits[3 * size + index] - 48 == size)
		{
			while (++cord_x < size)
			{
				grid[(index * size) + cord_x] = size - cord_x;
			}
		}
	}
}

void	solve(int *grid, int size, int *limits)
{
	rule_one_vertical(grid, size, limits);
	rule_one_horisontal(grid, size, limits);
	rule_two(grid, size, limits);
	rule_three(grid, size, limits);
	rule_four(grid, size, limits);
}
