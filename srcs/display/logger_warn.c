/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_warn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:42:24 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:47:16 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

void	logger_warn(int fd, char *file, int line, const char *fmt, ...)
{
	va_list	lst;
	char	*time;

	if (g_log_lvl < D_WARN)
		return ;
	va_start(lst, fmt);
	time = logger_get_time();
	dprintf(fd, "\033[33m[ %s ] [ %-5s ]\033[0m (l.%3d) %s -> ", \
			time, "WARN", line, file);
	vdprintf(fd, fmt, lst);
	va_end(lst);
	free(time);
}
