#ifndef LOGGER_UTILS_H
# define LOGGER_UTILS_H

# include <stdarg.h>
# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

/*
** Macro to get the basename of the __FILE__ macro.
*/

# define __NAME__ (strrchr(__FILE__,'/') ? strrchr(__FILE__,'/')+1 : __FILE__)

/*
** Global variables, the file descriptor to write on, and the log level.
*/

int		g_lfd;
int		g_lvl;

/*
** Tools functions.
*/

int		logger_init_open_file(char *log_file);

void	log_fatal(int fd, char *file, int line, const char *fmt, ...);
void	log_error(int fd, char *file, int line, const char *fmt, ...);
void	log_warn(int fd, char *file, int line, const char *fmt, ...);
void	log_success(int fd, char *file, int line, const char *fmt, ...);
void	log_info(int fd, char *file, int line, const char *fmt, ...);
void	log_debug(int fd, char *file, int line, const char *fmt, ...);
void	log_trace(int fd, char *file, int line, const char *fmt, ...);

char	*logger_get_time(void);

#endif
