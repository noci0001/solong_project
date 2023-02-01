/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:45:34 by snocita           #+#    #+#             */
/*   Updated: 2023/02/01 11:04:48 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 		&img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 55, 55, 0x00FFFF66);

int	shut(void)
{
	exit(1);
	return (0);
}

int	deal_key(int key, t_window *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(1);
	}
	// if (key == 0)
	// {
	// 	param->
	// }
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	texture_go(t_window *param1, t_data *param2)
{
	void		*image;
	int			img_width;
	int			img_height;

	param2->addr = "./textures/character/cat-char.xpm";

	param2->img = mlx_new_image(param1->mlx_ptr, 50, 50);
	mlx_put_image_to_window(param1->mlx_ptr, param1->win_ptr,
		param2->img, 0, 0);
	image = mlx_xpm_file_to_image(param1->mlx_ptr, param2->addr,
			&img_width, &img_height);
	if (image == NULL)
		write(1, "U SUCK", 7);
	mlx_put_image_to_window(param1->mlx_ptr, param1->win_ptr, image, 0, 0);
}

void	image_handle(t_window *param1, t_data *param2)
{
	void		*image;
	int			img_width;
	int			img_height;

	param2->addr = "./textures/objects/heart.xpm";
	param2->img = mlx_new_image(param1->mlx_ptr, 50, 50);
	mlx_put_image_to_window(param1->mlx_ptr, param1->win_ptr,
		param2->img, 500, 500);
	image = mlx_xpm_file_to_image(param1->mlx_ptr, param2->addr,
			&img_width, &img_height);
	if (image == NULL)
		write(1, "U SUCK", 7);
	mlx_put_image_to_window(param1->mlx_ptr, param1->win_ptr, image, 0, 0);
}

int	main(void)
{
	t_window	window;
	t_data		img1;
	t_data		character;

	window.mlx_ptr = mlx_init();
	window.win_width = 1500;
	window.win_height = 1000;
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.win_width,
			window.win_height, "Yo mama");
	texture_go(&window, &character);
	image_handle(&window, &img1);
	mlx_key_hook(window.win_ptr, deal_key, &window);
	mlx_hook(window.win_ptr, ON_DESTROY, 0, shut, &window);
	mlx_loop(window.mlx_ptr);
}
