/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekojima <ekojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:10:36 by ekojima           #+#    #+#             */
/*   Updated: 2025/03/23 16:11:12 by ekojima          ###   ########.fr       */
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

int	check_constraints(int grid[4][4], int constraints[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (visible_count(grid[0][i], grid[1][i], grid[2][i],
				grid[3][i]) != constraints[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (visible_count(grid[3][i], grid[2][i], grid[1][i],
				grid[0][i]) != constraints[4 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (visible_count(grid[i][0], grid[i][1], grid[i][2],
				grid[i][3]) != constraints[8 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (visible_count(grid[i][3], grid[i][2], grid[i][1],
				grid[i][0]) != constraints[12 + i])
			return (0);
		i++;
	}
	return (1);
}
