/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekojima <ekojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:10:36 by ekojima           #+#    #+#             */
/*   Updated: 2025/03/24 17:08:16 by ekojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible_count(int a, int b, int c, int d)
{
	int	count;
	int	max;

	count = 1;
	max = a;
	if (b > max)
	{
		count++;
		max = b;
	}
	if (c > max)
	{
		count++;
		max = c;
	}
	if (d > max)
	{
		count++;
		max = d;
	}
	return (count);
}

int	check_constraints(int *grid, int *constraints)
{
	int	i;
	int	top;
	int	bottom;
	int	left;
	int	right;

	i = 0;
	while (i < 4)
	{
		top = visible_count(grid[i], grid[4 + i], grid[8 + i], grid[12 + i]);
		bottom = visible_count(grid[12 + i], grid[8 + i], grid[4 + i], grid[i]);
		left = visible_count(grid[i * 4], grid[i * 4 + 1], grid[i * 4 + 2],
				grid[i * 4 + 3]);
		right = visible_count(grid[i * 4 + 3], grid[i * 4 + 2], grid[i * 4 + 1],
				grid[i * 4]);
		if (top != constraints[i] || bottom != constraints[4 + i]
			|| left != constraints[8 + i] || right != constraints[12 + i])
			return (0);
		i++;
	}
	return (1);
}
