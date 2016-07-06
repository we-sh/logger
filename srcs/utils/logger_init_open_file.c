#include "logger.h"

int	logger_init_open_file(char *log_file)
{
	if (log_file == NULL)
		g_lfd = -1;
	g_lfd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, 0755);
	return (g_lfd);
}
