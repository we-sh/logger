#include "logger.h"

int	logger_init(int level, char *log_file)
{
	int	ret;

	if ((ret = logger_init_open_file(log_file)) < 0)
		return (ret);
	g_log_lvl = D_OFF;
	if (level >= D_FATAL && level <= D_TRACE)
	{
		g_log_lvl = level;
		dprintf(g_log_fd, "\n\033[32m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m");
		dprintf(g_log_fd, "\033[32mNEW INSTANCE OF THE APPLICATION\033[0m");
		dprintf(g_log_fd, "\033[32m <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m\n\n");
	}
	return (0);
}
