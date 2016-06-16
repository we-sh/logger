#include "logger.h"

int	logger_close(void)
{
	dprintf(g_log_fd, "\n\033[32m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m");
	dprintf(g_log_fd, "\033[32mEND OF THE APPLICATION INSTANCE\033[0m");
	dprintf(g_log_fd, "\033[32m <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m\n\n");
	return (close(g_log_fd));
}
