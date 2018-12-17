CC = Clang
COMPILE = $(CC) -c

# Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

NAME = libft.a
CLEANUP =rm -rf
MKDIR = mkdir -p

PATHO =objs/
PATHI =includes/

INCS = libft.h

#--------------------Part I--------------------#
SRCS +=ft_sqrt.c #DONE
SRCS +=ft_memcpy.c #DONE
SRCS +=ft_memset.c #DONE
SRCS +=ft_strlen.c #DONE

#--------------------Part II-------------------#
SRCS +=ft_putchar.c #DONE
SRCS +=ft_putstr.c #DONE
SRCS +=ft_strnew.c #DONE

#--------------------Part III------------------#
SRCS +=ft_lstdel.c #DONE
SRCS +=ft_lstdelone.c #DONE
SRCS +=ft_lstnew.c #DONE

#--------------------Part IV-------------------#
SRCS +=ft_lstaddback.c #DONE
SRCS +=ft_strcspn.c #DONE

OBJS =$(patsubst %.c, $(PATHO)%.o, $(SRCS))

WFLAGS +=-Wall
WFLAGS +=-Werror
WFLAGS +=-Wextra
IFLAGS =-I $(PATHI)
CFLAGS =$(WFLAGS)

.PHONY: all clean fclean
.SILENT:
	
vpath %.c .
vpath %.h includes

all : $(PATHO) $(NAME)

$(NAME): $(OBJS)
	ar rus $@ $^
	@printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $(IFLAGS) $< -o $@
	@printf "$(BLUE)Compiling $<\n$(NC)"

$(PATHO) :
	$(MKDIR) $(PATHO)

clean:
	@$(CLEANUP) $(PATHO)*.o
	@printf "$(RED)All *.o files removed\n$(NC)"

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	@printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all
