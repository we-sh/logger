/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:42:18 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:46:48 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

void	logger_info(int fd, char *file, int line, const char *fmt, ...)
{
	va_list	lst;
	char	*time;

	if (g_log_lvl < D_INFO)
		return ;
	va_start(lst, fmt);
	time = logger_get_time();
	dprintf(fd, "\033[36m[ %s ] [ %-5s ]\033[0m (l.%3d) %s -> ", \
			time, "INFO", line, file);
	vdprintf(fd, fmt, lst);
	va_end(lst);
	free(time);
}
