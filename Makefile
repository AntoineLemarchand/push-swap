WIDTH= 79

define building
	@printf '%s\n' "-> Building $1"
	@make -sC $1 > /dev/null
	@echo "√"
endef

define compiling
	@printf '%s\n' "-> Compiling $1"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $1 -o $2
	@echo "√"
endef

define finishing
	@printf '%s\n' "-> Finishing $1"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "√"
endef

define cleaning
	@printf '%s\n' "-> Cleaning $1"
	@make $2 -sC $1 > /dev/null
	@echo "√"
endef

define removing
	@printf '%s\n' "-> Removing $1"
	@$(RM) $1 > /dev/null
	@echo "√"
endef

SRCS		= $(addprefix srcs/, \
			  	parsing.c \
			  	stack.c \
				stackop.c \
				sortsmall.c \
				costsort.c \
				utils.c \
				sort.c \
			  	main.c \
				)

OBJS		= $(SRCS:.c=.o)

NAME		= push_swap

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

CPPFLAGS	= -Iincludes

LIBS		= ./libft/libft.a

%.o : %.c
			$(call compiling,$<,$(<:.c=.o),0)

${NAME}:	$(OBJS)
			$(call building,libft)
			$(call finishing,$(NAME))

all:		$(NAME)

clean:	
			$(call removing,$(OBJS))

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call removing,${NAME})

re:			fclean all
