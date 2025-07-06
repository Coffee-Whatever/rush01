/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:10:39 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/06 18:29:52 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void rule_four(int *grid, int size, int *limits);

void rule_three(int *grid, int size, int *limits);

void rule_two(int *grid, int size, int *limits);

void rule_one_vertical(int *grid, int size, int *limits);

void rule_one_horisontal(int *grid, int size, int *limits);

void two_three_rows(int *unused, int *grid, int size, int *limits);

void two_three_columns(int *unused, int *grid, int size, int *limits);

void three_cases(int *grid, int size, int *limits);

int set(int *tile, int *used_stuff, int size, int flag) {
	int index;

	index = -1;
	if (!flag)
		return (-1);
	if (flag == 1) {
		while (++index < size) {
			if (used_stuff[index] == 0 && used_stuff[index + 4] == 0) {
				*tile = index + 1;
				return (1);
			}
		}
	}
	return (0);
}

void fill_out_array(int *array) {
	int index;

	index = -1;
	while (++index < 8) {
		array[index] = 0;
	}
}

int check(int *grid, int size, int cord_y, int cord_x) {
	int index;
	int used_stuff[8];
	int flag;

	index = -1;
	flag = 0;
	fill_out_array(used_stuff);
	while (++index < size) {
		if (grid[index * size + cord_x] != 'x' - 48)
			used_stuff[grid[index * size + cord_x] - 1] = 1;
	}
	index = -1;
	while (++index < size) {
		if (grid[cord_y * size + index] != 'x' - 48)
			used_stuff[grid[cord_y * size + index] + 3] = 1;
	}
	index = -1;
	while (++index < size) {
		if (used_stuff[index] == 0 && used_stuff[index + 4] == 0)
			flag += 1;
	}
	return (set(&(grid[cord_y * size + cord_x]), used_stuff, size, flag));
}

int sudoku_fill(int *grid, int size) {
	int cord_y;
	int cord_x;
	int modified;

	cord_y = -1;
	while (++cord_y < size) {
		cord_x = -1;
		while (++cord_x < size) {
			if (grid[cord_y * size + cord_x] == 'x' - 48) {
				modified = check(grid, size, cord_y, cord_x);
				if (modified == 1) {
					cord_y = 0;
					cord_x = -1;
				}
				if (modified == -1)
					return (-1);
			}
		}
	}
	return (0);
}

int solve(int *grid, int size, int *limits) {
	int unused[3];
	int loop_through;

	loop_through = 3;
	unused[0] = 1;
	unused[1] = 1;
	unused[2] = 1;
	rule_one_vertical(grid, size, limits);
	rule_one_horisontal(grid, size, limits);
	rule_two(grid, size, limits);
	rule_three(grid, size, limits);
	rule_four(grid, size, limits);
	while (loop_through-- > 0) {
		if (sudoku_fill(grid, size) == -1) {
			write(1, &"Error\n", 6);
			return (1);
		}
		two_three_columns(unused, grid, size, limits);
		two_three_rows(unused, grid, size, limits);
	}
	return (0);
}
