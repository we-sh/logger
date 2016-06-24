#include "logger.h"

void	logger_warn(int fd, char *file, int line, const char *fmt, ...)
{
	va_list	lst;
	char	*time;
	char	*out_info;
	char	*out_mesg;
	char 	*f;

	if (g_log_lvl < D_WARN)
		return ;

	f = NULL;
	if (strlen(file) >= 20)
	{
		f = strdup(file + (strlen(file) - 20));
		f[0] = '+';
	
	}
	else
		f = strdup(file);
	time = logger_get_time();
	asprintf(&out_info, "[ %s ] (l.%3d) %-20.20s -> ", \
			time, line, f);
	free(f);

	va_start(lst, fmt);
	vasprintf(&out_mesg, fmt, lst);
	va_end(lst);

	dprintf(fd, "\033[31m\033[1;33m%s%s\033[0m\n", out_info, out_mesg);

	free(out_info);
	free(out_mesg);
	free(time);
}
