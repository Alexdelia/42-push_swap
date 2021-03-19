# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/03/19 18:55:06 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME =
CC = 	clang -Wall -Werror -Wextra
RM = 	rm -rf
# FLAGS =	-O2

# **************************************************************************** #

MAKEFLAGS += --silent

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LBPATH =	./libft/
LBNAME =	$(LBPATH)libft.a
LBINC =		-I$(LBPATH)

# **************************************************************************** #

SRCSPATH =		./srcs/
OBJSPATH_CH =	./objs_checker/
OBJSPATH_PS =	./objs_push_swap/
INC =			./includes/

# will use another tech
SRCSNAME_CH = checker.c \
				ft_arg.c \
				ft_utils.c \

SRCS_CH = $(addprefix $(SRCSPATH), $(SRCSNAME_CH))
OBJSNAME_CH = $(SRCSNAME_CH:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS_CH = $(OBJSPATH_CH)*.o

SRCS_PS = push_swap.c

SRCS_PS = $(addprefix $(SRCSPATH), $(SRCSNAME_PS))
OBJSNAME_PS = $(SRCSNAME_PS:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS_PS = $(OBJSPATH_PS)*.o

# *************************************************************************** #

all:
	@make -C $(LBPATH)
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(CC) -I$(INC) -c $(SRCS)
	@mv *.o $(OBJSPATH)
	@$(CC) $(OBJS) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(NAME)
	@echo "$(B)$(MAG)$(BEL)\n\tpush_swap(2 exe)\tcompiled!\n$(D)"

$(LIBFTM):
	@make -C $(LBPATH) -f Makefile

libft:	$(LIBFTM)
	@echo "$(B)Libft compiled.$(D)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LBPATH) -f Makefile clean
	@rmdir $(OBJSPATH) 2> /dev/null || true
	@echo "$(B)Cleared.$(D)"


fclean: clean
	@$(RM) $(NAME) $(MLXM)
	@make -C $(LBPATH) -f Makefile fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft

# **************************************************************************** #
