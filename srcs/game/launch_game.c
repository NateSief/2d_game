/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:54 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/15 17:51:22 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Charge toutes les textures de mes elements
void	charge_textures(t_mlx *mlx)
{
	int	(i) = 64;
	int	(j) = 64;
	
	mlx->map->t_wall = mlx_xpm_file_to_image(mlx->mlx, WALL_PATH, &i, &j);
	mlx->map->t_collectible = mlx_xpm_file_to_image(mlx->mlx, COLLECTIBLE_PATH, &i, &j);
	mlx->map->t_player = mlx_xpm_file_to_image(mlx->mlx, PLAYER_PATH, &i, &j);
	mlx->map->t_exit = mlx_xpm_file_to_image(mlx->mlx, EXIT_PATH, &i, &j);
	mlx->map->t_ground = mlx_xpm_file_to_image(mlx->mlx, GROUND_PATH, &i, &j);
} 

void	affiche(t_mlx *mlx, t_texture *texture, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, texture, j * 64, i * 64);
}

// Charge la map a son etat initial
void	charge_map(t_mlx *mlx)
{
	int	(i) = -1;
	int	j ;
	while (++i < mlx->jeu->dimensions->width)
	{
		j = -1;
		while (++j < mlx->jeu->dimensions->lenght)
		{
			if (mlx->jeu->map[i][j] == 'W')
				affiche(mlx, mlx->map->t_wall, i, j);
			if (mlx->jeu->map[i][j] == 'G')
				affiche(mlx, mlx->map->t_ground, i, j);
			if (mlx->jeu->map[i][j] == 'C')
				affiche(mlx, mlx->map->t_collectible, i, j);
			if (mlx->jeu->map[i][j] == 'E')
				affiche(mlx, mlx->map->t_exit, i, j);
			if (mlx->jeu->map[i][j] == 'P')
				affiche(mlx, mlx->map->t_player, i, j);
		}
	}
}



// Lance le lancement du jeu, l'ouverture de ma fenetre, la generation des 
// sprites de la map de base, puis fait une boucle qui gere toutes les actions
// en fonction des actions du joueur 
void	launch_game(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->jeu->dimensions->lenght*64, 
		mlx->jeu->dimensions->width*64, mlx->jeu->name);
	charge_textures(mlx);
	charge_map(mlx);
	mlx->count_mouvement = 0;
	mlx->left_items = mlx->jeu->info->collectibles;
	mlx->player = mlx->jeu->player;
	
	// mlx_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
