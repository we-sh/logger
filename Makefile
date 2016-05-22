#
# This file is under Apache 2.0 license, see LICENSE.md.
# 

# ---------------------------------------------------------------------------- #
# PROJECT DATA
# ---------------------------------------------------------------------------- #

NAME		=	liblogger.a

# ---------------------------------------------------------------------------- #

SRCS		=	\
				logger/logger_init.c					\
				logger/logger_close.c					\
				display/logger_fatal.c					\
				display/logger_error.c					\
				display/logger_warn.c					\
				display/logger_info.c					\
				display/logger_debug.c					\
				display/logger_trace.c					\
				utils/logger_get_time.c					\
				utils/logger_init_open_file.c			\

# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION
# ---------------------------------------------------------------------------- #

CFLAGS		=	\
				-Wall -Wextra -Werror			\

# >>> REQUIRED FOR LIBRARIES >>> THINK ABOUT CHANGING THE *LIBS rules

CPPFLAGS	=	\
				-I $(DIRINC)					\

LDFLAGS		=	\

LDLIBS		=	\

# GLOBAL SETUP
AR			=	ar
CC			=	clang
RM			=	rm
MKDIR		=	mkdir
MAKE		=	make

DIRSRC		=	./srcs/
DIROBJ		=	./.objs/
DIRINC		=	./incs/
DIRLIB		=	./libs/

# EXTRA COLOR
C_DFL		=	\033[0m
C_GRA		=	\033[30m
C_RED		=	\033[31m
C_GRE		=	\033[32m
C_YEL		=	\033[33m
C_BLUE		=	\033[34m
C_MAG		=	\033[35m
C_CYA		=	\033[36m
C_WHI		=	\033[37m

# ============================================================================ #

# ---------------------------------------------------------------------------- #
# SOURCES NORMALIZATION
# ---------------------------------------------------------------------------- #

SRC			=	$(addprefix $(DIRSRC), $(SRCS))
OBJ			=	$(addprefix $(DIROBJ), $(notdir $(SRC:.c=.o)))

# ---------------------------------------------------------------------------- #
# RULES
# ---------------------------------------------------------------------------- #

all			:	libs $(NAME)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) build completed\n" "$(MAKE)"

$(NAME)		:	$(DIROBJ) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) linking objects\n" "$(CC)"
	@$(AR) rc $(NAME) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) index project\n" "ranlib"
	@ranlib $(NAME)

# ---------------------------------------------------------------------------- #
# CUSTOMISABLE RULES

libs		:

fcleanlibs	:

# ---------------------------------------------------------------------------- #

clean		:
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove objects\n" "$(RM)"
	@$(RM) -rf $(DIROBJ)

fclean		:	fcleanlibs clean
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove binaries\n" "$(RM)"
	@$(RM) -f $(NAME)

re			:	fclean all

$(DIROBJ)	:
	@$(MKDIR) -p $(DIROBJ)

depend		:
	@sed -e '/^#start/,/^end/d' Makefile > .mftmp && mv .mftmp Makefile
	@printf "#start\n\n" >> Makefile
	@$(foreach s, $(SRC),													\
		printf '$$(DIROBJ)'										>> Makefile	&& \
		$(CC) -MM $(s) $(CPPFLAGS)								>> Makefile	&& \
																			\
		printf '\t\t@printf "$$(C_GRE)[ $(NAME) ] '				>> Makefile && \
		printf '[ %%-6s ]$$(C_DFL) " "$(CC)"\n'					>> Makefile && \
		printf '\t\t@printf "compiling $(s)\\n"\n'				>> Makefile	&& \
																			\
		printf '\t\t@$$(CC) -c $(s) -o '						>> Makefile	&& \
		printf '$(addprefix $(DIROBJ), $(notdir $(s:.c=.o))) '	>> Makefile	&& \
		printf '$$(CPPFLAGS) $$(CFLAGS) \n\n'					>> Makefile	&& \
																			\
		printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generated\n"										|| \
																			\
		(sed -e '/^#start/,$$d' Makefile > .mftmp && mv .mftmp Makefile		&& \
		printf "#start\n\n"										>> Makefile	&& \
		printf "$(C_RED)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generation failed\n"								) \
	;)
	@printf "\n#end\n" >> Makefile

.PHONY	:	 libs

# ---------------------------------------------------------------------------- #
# AUTO-GENERATED SECTION - do not modify
# ---------------------------------------------------------------------------- #

#start

$(DIROBJ)logger_init.o: srcs/logger/logger_init.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/logger/logger_init.c\n"
		@$(CC) -c ./srcs/logger/logger_init.c -o ./.objs/logger_init.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_close.o: srcs/logger/logger_close.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/logger/logger_close.c\n"
		@$(CC) -c ./srcs/logger/logger_close.c -o ./.objs/logger_close.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_fatal.o: srcs/display/logger_fatal.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/display/logger_fatal.c\n"
		@$(CC) -c ./srcs/display/logger_fatal.c -o ./.objs/logger_fatal.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_error.o: srcs/display/logger_error.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/display/logger_error.c\n"
		@$(CC) -c ./srcs/display/logger_error.c -o ./.objs/logger_error.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_warn.o: srcs/display/logger_warn.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/display/logger_warn.c\n"
		@$(CC) -c ./srcs/display/logger_warn.c -o ./.objs/logger_warn.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_info.o: srcs/display/logger_info.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/display/logger_info.c\n"
		@$(CC) -c ./srcs/display/logger_info.c -o ./.objs/logger_info.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_debug.o: srcs/display/logger_debug.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/display/logger_debug.c\n"
		@$(CC) -c ./srcs/display/logger_debug.c -o ./.objs/logger_debug.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_trace.o: srcs/display/logger_trace.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/display/logger_trace.c\n"
		@$(CC) -c ./srcs/display/logger_trace.c -o ./.objs/logger_trace.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_get_time.o: srcs/utils/logger_get_time.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/utils/logger_get_time.c\n"
		@$(CC) -c ./srcs/utils/logger_get_time.c -o ./.objs/logger_get_time.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)logger_init_open_file.o: srcs/utils/logger_init_open_file.c incs/logger.h
		@printf "$(C_GRE)[ liblogger.a ] [ %-6s ]$(C_DFL) " "clang"
		@printf "compiling ./srcs/utils/logger_init_open_file.c\n"
		@$(CC) -c ./srcs/utils/logger_init_open_file.c -o ./.objs/logger_init_open_file.o $(CPPFLAGS) $(CFLAGS) 


#end
