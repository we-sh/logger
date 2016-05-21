/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:41:54 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:48:48 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_UTILS_H
# define LOGGER_UTILS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>

# define OUT_SIZE	2048

/*
** Macro to get the basename of the __FILE__ macro.
*/

# define __FILENAME__	\
	(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/*
** Global variables, the file descriptor to write on, and the log level.
*/

int			g_log_fd;
int			g_log_lvl;

/*
** Global variables to store the output message.
*/

static char	g_out_info[OUT_SIZE];
static char	g_out_mesg[OUT_SIZE];

/*
** Tools functions.
*/

int		logger_init_open_file(char *log_file);

void	logger_fatal(int fd, char *file, int line, const char *fmt, ...);
void	logger_error(int fd, char *file, int line, const char *fmt, ...);
void	logger_warn(int fd, char *file, int line, const char *fmt, ...);
void	logger_info(int fd, char *file, int line, const char *fmt, ...);
void	logger_debug(int fd, char *file, int line, const char *fmt, ...);
void	logger_trace(int fd, char *file, int line, const char *fmt, ...);

char	*logger_get_time(void);

#endif