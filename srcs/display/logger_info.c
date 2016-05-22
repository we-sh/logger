#include "logger.h"

void	logger_info(int fd, char *file, int line, const char *fmt, ...)
{
	va_list	lst;
	char	*time;

	if (g_log_lvl < D_INFO)
		return ;

	time = logger_get_time();
	sprintf(g_out_info, "\033[36m[ %s ] [ %-5s ]\033[0m (l.%3d) %s -> ", \
			time, "INFO", line, file);

	va_start(lst, fmt);
	vsprintf(g_out_mesg, fmt, lst);
	va_end(lst);

	dprintf(fd, "%s%s\n", g_out_info, g_out_mesg);

	free(time);
}
