/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:07:06 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/28 13:44:20 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Permet de free la structure TEXTURES
static void	free_textures(t_game *game)
{
	if (TEXTS->t_collectibles)
		mlx_destroy_image(game->mlx->mlx, TEXTS->t_collectibles);
	if (TEXTS->t_exit)
		mlx_destroy_image(game->mlx->mlx, TEXTS->t_exit);
	if (TEXTS->t_ground)
		mlx_destroy_image(game->mlx->mlx, TEXTS->t_ground);
	if (TEXTS->t_player)
		mlx_destroy_image(game->mlx->mlx, TEXTS->t_player);
	if (TEXTS->t_wall)
		mlx_destroy_image(game->mlx->mlx, TEXTS->t_wall);
	free(TEXTS);
}

// Permet de free la structure MLX
void	ft_free_mlx(t_game *game)
{
	if (game->mlx->texts)
		free_textures(game);
	if (game->mlx->win)
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	if (game->mlx->mlx)
	{
		mlx_destroy_display(game->mlx->mlx);
		free(game->mlx->mlx);
	}	
	free(game->mlx);
}
