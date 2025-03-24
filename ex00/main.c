/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekojima <ekojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:22:34 by tkuwahat          #+#    #+#             */
/*   Updated: 2025/03/24 17:00:08 by ekojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	parse_input(char *str, int *constraints);
void	print_grid(int *grid);
int		solve(int *grid, int *constraints, int row, int col);
int		is_valid(int *grid, int row, int col, int num);
int		check_constraints(int *grid, int *constraints);

int	main(int argc, char **argv)
{
	int	*grid;
	int	*constraints;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid = malloc(sizeof(int) * 16);
	constraints = malloc(sizeof(int) * 16);
	if (!grid || !constraints)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	parse_input(argv[1], constraints);
	if (solve(grid, constraints, 0, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	free(grid);
	free(constraints);
	return (0);
}
