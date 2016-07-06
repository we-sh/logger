# Logger

The logger library provides a tool to write some logging messages into a file.

### Use case

The following snippet explains how to use the logger library (see `test/main.c` to try this example) :

```C
#include "logger.h"

int	main(void)
{
	if (logger_init(D_TRACE, "/tmp/out.log") != 0)
		printf("failed to open the logger\n");
	log_fatal("%s", "fatal message");
	log_error("%s", "error message");
	log_warn("%s", "warning message");
	log_success("%s", "success message");
	log_info("%s", "info message");
	log_debug("%s", "debug message");
	log_trace("%s", "trace message");
	logger_close();
	return (0);
}
```

### Initialization and exit

- The purpose of ```int logger_init(int level, char *log_file);``` is to setup the logger with some parameters.  It returns 0 on success, and a negative value otherwise.


```C
if (logger_init(D_TRACE, "/tmp/out.log") != 0)
	printf("failed to open the logger\n");
```

- To exit properly the logger, use the close function ```int logger_close(void);``` :

```C
logger_close();
```

#### Logger level

The log level must be one of the following macros, if it is not, the default ```D_OFF``` level will be used :

```C
# define D_OFF			0
# define D_FATAL		1
# define D_ERROR		2
# define D_WARN			3
# define D_SUCCESS		4
# define D_INFO			5
# define D_DEBUG		6
# define D_TRACE		7
```

The logic of the log level in the initializing function is the following:

- if the flag is ```D_OFF``` flag, the logger will not display anything
- if the flag is ```D_FATAL```, the logger will display only the ```D_FATAL``` logging messages
- if the flag is ```D_ERROR```, the logger will display the ```D_FATAL``` and ```D_ERROR``` logging messages (but not ```D_WARN``` to ```D_TRACE``` logging messages)
- ...
- if the flag is ```D_TRACE```, all the logging messages will be display

#### Output file

- It depends on the purpose of the logger, but for development, it seems to be a good idea to put the log file into /tmp or everywhere out of the project folder (the amount of access may be important).
- The function will setup a file with the following flags : ```O_WRONLY | O_APPEND | O_CREAT```. It means that :
 - the file is open in write-only mode
 - the new log message will be written at the end of the file
 - the file will be created if it doesn't exist yet

### Logger functions

Use the following functions to display a log message :

```C
void	log_fatal(const char * restrict format, ...);
void	log_error(const char * restrict format, ...);
void	log_warn(const char * restrict format, ...);
void	log_success(const char * restrict format, ...);
void	log_info(const char * restrict format, ...);
void	log_debug(const char * restrict format, ...);
void	log_trace(const char * restrict format, ...);
```

The arguments are the same as ```man 3 printf``` function.

> if the log level is ```D_WARN``` and the code contains a ```log_debug(...)```, this debug message will be simply ignored.

Each functions will provide a different output, here is a sample of the execution of the snippet at the top of the document :

```C
>>>>>>>>>>>>>>>>>> NEW INSTANCE OF THE APPLICATION <<<<<<<<<<<<<<<<<<

[ 12:50:30 ] (l. 26) main.c               -> fatal message
[ 12:50:30 ] (l. 27) main.c               -> error message
[ 12:50:30 ] (l. 28) main.c               -> warning message
[ 12:50:30 ] (l. 29) main.c               -> success message
[ 12:50:30 ] (l. 30) main.c               -> info message
[ 12:50:30 ] (l. 31) main.c               -> debug message
[ 12:50:30 ] (l. 32) main.c               -> trace message

>>>>>>>>>>>>>>>>>> END OF THE APPLICATION INSTANCE <<<<<<<<<<<<<<<<<<
```

Notice that the logger appends a `\n` at the end of the message, so it is not necessary to add it.

#### Purpose of logging level

There is no rules for the using of the levels, but we can considered that :

- ```FATAL``` will produce the end of the execution of the program (ex : wrong configuration)
- ```ERROR``` is a code failure (ex : cannot open a non-critical configuration file)
- ```WARN``` is not an error, but change the behavior of the program (ex : stub part of code)
- ```SUCCESS``` inform that an operation has exited with success
- ```INFO``` is like ```warn```, but it is not dangerous as a warning (ex : configuration file loaded)
- ```DEBUG``` is for developers, like ```INFO``` but not for the user (ex : display the size of a window)
- ```TRACE``` is for 'low level' developers (ex : display the i of a while loop)  


# The Team

* **Adrien Nouvel** [@anouvel](https://github.com/anouvel)
* **Gabriel Kuma** [@gabkk](https://github.com/gabkk)
* **Jean-Michel Gigault** [@jgigault](https://github.com/jgigault)
* **Matthias Leconte** [@Tix6](https://github.com/Tix6)
