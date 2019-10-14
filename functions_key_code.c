/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:16:32 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 11:20:30 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				expose(void *param)
{
	t_window	*win;

	win = param;
	exit(0);
}

/*
 * key_press == использование клавы
 * close == закрытие окна на крестик красный
 * expose == ?
 */

int				key_press(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == ARROW_UP)
	{
		win->var.y1 += 30 / win->var.zoom;
		printf("up\n");
	}
    if (key == ARROW_DOWN)
	{
		win->var.y1 -= 30 / win->var.zoom;
		printf("down\n");
	}
    if (key == ARROW_LEFT)
	{
		win->var.x1 += 30 / win->var.zoom;
		printf("left\n");
	}
    if (key == ARROW_RIGHT)
	{
		win->var.x1 -= 30 / win->var.zoom;
		printf("right\n");
	}
    mlx_clear_window(win->mlx, win->win);
	fractol_while(win);
	return (0);
}

void	zoomin(int keys, int x, int y, t_window *win)
{
	double past_x;
	double past_y;

	if (keys == 4)
	{
		past_x = (x / win->var.zoom + win->var.x1);
		past_y = (y / win->var.zoom + win->var.y1);
		win->var.zoom *= 1.3;
		win->var.x1 = past_x - (x / win->var.zoom);
		win->var.y1 = past_y - (y / win->var.zoom);
		mlx_clear_window(win->mlx, win->win);
		fractol_while(win);
	}
}

void	zoomout(int keys, int x, int y, t_window *win)
{
	double past_x;
	double past_y;

	if (keys == 5)
	{
		past_x = (x / win->var.zoom + win->var.x1);
		past_y = (y / win->var.zoom + win->var.y1);
		win->var.zoom /= 1.3;
		win->var.x1 = past_x - (x / win->var.zoom);
		win->var.y1 = past_y - (y / win->var.zoom);
		mlx_clear_window(win->mlx, win->win);
		fractol_while(win);
	}
}

void	mouse_key(int keys, int x, int y, t_window *win)
{
	if (keys == 1)
	{
		if (win->flag_mouse == 1)
			win->flag_mouse = 0;
		else
			win->flag_mouse = 1;
	}
	if (keys == 4)
		zoomin(keys, x, y, win);
	else if (keys == 5)
		zoomout(keys, x, y, win);
}

void	julia_mouse(int x, int y, t_window *win)
{
	if (win->flag_mouse == 1)
	{
		win->var.dy2 = (double)(x - (double)SIZE / 2) / ((double)SIZE / 2);
		win->var.dy = (double)(y - (double)SIZE / 2) / ((double)SIZE / 2);
		mlx_clear_window(win->mlx, win->win);
		fractol_while(win);
	}
}