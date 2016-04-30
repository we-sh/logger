/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_init_open_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:42:52 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:44:15 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

int	logger_init_open_file(char *log_file)
{
	if (log_file == NULL)
		g_log_fd = -1;
	g_log_fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, 0755);
	return (g_log_fd);
}
