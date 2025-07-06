/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pklimkie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:22:32 by pklimkie          #+#    #+#             */
/*   Updated: 2025/07/06 16:19:20 by pklimkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		validate_data(int argsc, char *data);
void	get_the_data_out(char *data, int *visibility, int side_size);
void	fill_it(int *grid, int side);
int		solve(int *grid, int size, int *limits);
void	display(int *grid, int side);
int		validate_range(char *data, int side_size);

int	main(int argsc, char **argsv)
{
	int	side_size;
	int	lenght_of_array;
	int	*grid;
	int	*visibility;

	argsv++;
	visibility = NULL;
	side_size = validate_data(argsc, *argsv);
	if (side_size == 0)
		return (0);
	visibility = malloc(side_size * 4 * 4);
	get_the_data_out(*argsv, visibility, side_size);
	if (!validate_range(*argsv, side_size))
		return (0);
	lenght_of_array = side_size * side_size;
	grid = malloc(lenght_of_array * 4);
	fill_it(grid, side_size);
	if (solve(grid, side_size, visibility))
		return (0);
	display(grid, side_size);
	free(grid);
	free(visibility);
	return (0);
}
