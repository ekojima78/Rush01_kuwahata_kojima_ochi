/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuwahat <tkuwahat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:23:25 by tkuwahat          #+#    #+#             */
/*   Updated: 2025/03/23 17:04:39 by tkuwahat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int grid[4][4], int row, int col, int num);
int	check_constraints(int grid[4][4], int constraints[16]);

int	solve(int grid[4][4], int constraints[16], int row, int col)
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == 4)
		return (check_constraints(grid, constraints));
	if (col == 3)
		next_row = row + 1;
	else
		next_row = row;
	next_col = (col + 1) % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, constraints, next_row, next_col))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
