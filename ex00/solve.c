/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekojima <ekojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:23:25 by tkuwahat          #+#    #+#             */
/*   Updated: 2025/03/24 17:11:02 by ekojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int *grid, int row, int col, int num);
int	check_constraints(int *grid, int *constraints);

int	solve(int *grid, int *constraints, int row, int col)
{
	int	num;
	int	nrow;
	int	ncol;

	if (row == 4)
		return (check_constraints(grid, constraints));
	nrow = row + (col == 3);
	ncol = (col + 1) % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row * 4 + col] = num;
			if (solve(grid, constraints, nrow, ncol))
				return (1);
			grid[row * 4 + col] = 0;
		}
		num++;
	}
	return (0);
}
