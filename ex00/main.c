/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuwahat <tkuwahat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:22:34 by tkuwahat          #+#    #+#             */
/*   Updated: 2025/03/23 14:54:36 by tkuwahat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	parse_input(char *str, int constraints[16]);
void	print_grid(int grid[4][4]);
int		solve(int grid[4][4], int constraints[16], int row, int col);

int	main(int argc, char **argv)
{
	int	grid[4][4] = {{0}};
	int	constraints[16] = {0};

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	parse_input(argv[1], constraints);
	if (solve(grid, constraints, 0, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
