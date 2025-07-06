/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_threes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:01:27 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/06 18:17:45 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_values_rows(int *tile, int *unused, int offset, int turn_around)
{
	int	index;

	index = 3;
	while (--index > -1)
	{
		if (*(tile + offset) != 'x' - 48 || *(tile + offset + 1) != 'x' - 48)
			return ;
		if (turn_around)
		{
			if (unused[index])
			{
				*(tile + offset) = index + 1;
				offset++;
			}
		}
		else if (unused[2 - index])
		{
			*(tile + offset) = 3 - index;
			offset++;
		}
	}
}

void	set_values_columns(int *tile, int *unused, int offset, int turn_around)
{
	int	index;

	index = -1;
	while (++index < 3)
	{
		if (*(tile + offset * 4) != 'x' - 48
			|| *(tile + (offset + 1) * 4) != 'x' - 48)
			return ;
		if (turn_around)
		{
			if (unused[index])
			{
				*(tile + offset * 4) = index + 1;
				offset++;
			}
		}
		else if (unused[2 - index])
		{
			*(tile + offset * 4) = 3 - index;
			offset++;
		}
	}
}

void	two_three_rows(int *unused, int *grid, int size, int *limits)
{
	int	index;

	index = -1;
	while (++index < size)
	{
		if (limits[size * 2 + index] == '2' && limits[size * 3 + index] == '3')
		{
			if (grid[size * index] != 'x' - 48)
			{
				unused[grid[size * index] - 1] = 0;
				set_values_rows(&(grid[size * index]), unused, 2, 1);
				unused[grid[size * index] - 1] = 1;
			}
		}
		if (limits[size * 2 + index] == '3' && limits[size * 3 + index] == '2')
		{
			if (grid[size * index + 3] != 'x' - 48)
			{
				unused[grid[size * index + 3] - 1] = 0;
				set_values_rows(&(grid[size * index]), unused, 0, 0);
				unused[grid[size * index + 3] - 1] = 1;
			}
		}
	}
}

void	two_three_columns(int *unused, int *grid, int size, int *limits)
{
	int	index;

	index = -1;
	while (++index < size)
	{
		if (limits[index] == '2' && limits[size + index] == '3')
		{
			if (grid[index] != 'x' - 48)
			{
				unused[grid[index] - 1] = 0;
				set_values_columns(&(grid[index]), unused, 2, 0);
				unused[grid[index] - 1] = 1;
			}
		}
		if (limits[index] == '3' && limits[size + index] == '2')
		{
			if (grid[size * (size - 1) + index] != 'x' - 48)
			{
				unused[grid[size * (size - 1) + index] - 1] = 0;
				set_values_columns(&(grid[index]), unused, 0, 1);
				unused[grid[size * (size - 1) + index] - 1] = 1;
			}
		}
	}
}
