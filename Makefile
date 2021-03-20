# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/03/20 15:04:57 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME =	
CH =	checker
PS =	push_swap
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
LBM =		libm

# **************************************************************************** #

SRCSPATH =		./srcs/
OBJSPATH_CH =	./objs_checker/
OBJSPATH_PS =	./objs_push_swap/
INC =			./includes/

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

all: $(NAME)

$(NAME): checker push_swap

checker: $(LBM)
	@mkdir $(OBJSPATH_CH) 2> /dev/null || true
	@$(CC) -I$(INC) $(LBINC) -c $(SRCS_CH)
	@mv *.o $(OBJSPATH_CH)
	$(CC) $(OBJS_CH) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(CH)
	@echo "$(B)$(MAG)$(BEL)\n\t$(CH)\tcompiled!\n$(D)"

push_swap: $(LBM)
	@mkdir $(OBJSPATH_PS) 2> /dev/null || true
	@$(CC) -I$(INC) $(LBINC) -c $(SRCS_PS)
	@mv *.o $(OBJSPATH_PS)
	@$(CC) $(OBJS_PS) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(PS)
	@echo "$(B)$(MAG)$(BEL)\n\t$(PS)\tcompiled!\n$(D)"

$(LBM):
	@make bonus -C $(LBPATH) -f Makefile

lib:	$(LIBFTM)
	@echo "$(B)$(MAG)$(BEL)Libft compiled.$(D)"

clean:
	@$(RM) $(OBJS_CH) $(OBJS_PS)
	@make -C $(LBPATH) -f Makefile clean
	@rmdir $(OBJSPATH_CH) 2> /dev/null || true
	@rmdir $(OBJSPATH_PS) 2> /dev/null || true
	@echo "$(B)Cleared.$(D)"


fclean: clean
	@$(RM) $(CH) $(PS)
	@make -C $(LBPATH) -f Makefile fclean

re: fclean all

.PHONY: all, clean, fclean, re, lib, checker, push_swap

# **************************************************************************** #
