/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuwahat <tkuwahat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:23:25 by tkuwahat          #+#    #+#             */
/*   Updated: 2025/03/23 15:05:53 by tkuwahat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int grid[4][4], int row, int col, int num);

int	solve(int grid[4][4], int constraints[16], int row, int col)
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == 4)
		return (1); // すべての行を埋め終えたら成功
	next_row = (col == 3) ? row + 1 : row;
	next_col = (col + 1) % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, constraints, next_row, next_col))
				return (1);
			grid[row][col] = 0; // バックトラック
		}
		num++;
	}
	return (0);
}
