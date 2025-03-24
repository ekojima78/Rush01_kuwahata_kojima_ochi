/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekojima <ekojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:21:14 by tkuwahat          #+#    #+#             */
/*   Updated: 2025/03/24 17:01:06 by ekojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int *grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row * 4 + i] == num)
			return (0);
		if (grid[i * 4 + col] == num)
			return (0);
		i++;
	}
	return (1);
}
