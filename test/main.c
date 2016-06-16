/*
** Use-case of the logger library.
**
** - Compilation :
**
** $ clang -Wall -Wextra -Werror main.c liblogger.a -I incs
** 
** or use the Makefile rule :
**
** $ make test
**
** This file is under Apache 2.0 license, see LICENSE.md.
*/ 

#include "logger.h"

int	main(void)
{
	// Initialize the logger (level and output file).

	if (logger_init(D_TRACE, "out.log") != 0)
		printf("failed to open the logger\n");

	// Display log messages.

	log_fatal("%s", "fatal message");
	log_error("%s", "error message");
	log_warn("%s", "warning message");
	log_success("%s", "success message");
	log_info("%s", "info message");
	log_debug("%s", "debug message");
	log_trace("%s", "trace message");

	// Close the logger.

	logger_close();
	
	return (0);
}
