#include "logger.h"

char	*logger_get_time(void)
{
	time_t		tm;
	char		*buf;
	struct tm	*tm_info;

	if (!(buf = (char *)malloc(sizeof(char) * 26)))
		return (NULL);
	tm = time(NULL);
	tm_info = localtime(&tm);
	strftime(buf, 26, "%Y/%m/%d %H:%M:%S", tm_info);
	return (buf);
}
