/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:10:39 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/06 12:35:40 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rule_four(int *grid, int size, int *limits);
void	rule_three(int *grid, int size, int *limits);
void	rule_two(int *grid, int size, int *limits);
void	rule_one_vertical(int *grid, int size, int *limits);
void	rule_one_horisontal(int *grid, int size, int *limits);

void	sudoku_fill(int *grid, int size, int *limits)
{
	int *const start = grid;


}

void	solve(int *grid, int size, int *limits)
{
	rule_one_vertical(grid, size, limits);
	rule_one_horisontal(grid, size, limits);
	rule_two(grid, size, limits);
	rule_three(grid, size, limits);
	rule_four(grid, size, limits);
	sudoku_fill(grid, size, limits);
}
