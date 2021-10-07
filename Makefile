# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/10/07 18:01:03 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME =	
CH =	checker
PS =	push_swap
CC = 	clang -Wall -Werror -Wextra -g
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

SRCSNAME_CH = checker/checker.c \
				checker/ft_arg.c \
				checker/ft_arg_utils.c \
				checker/ft_checking.c \
				checker/ft_check_sort.c \
				checker/ft_operation/ft_op_s.c \
				checker/ft_operation/ft_op_p.c \
				checker/ft_operation/ft_op_r.c \
				checker/ft_lst_color.c \
				checker/ft_put_row.c \
				ft_utils.c

SRCS_CH = $(addprefix $(SRCSPATH), $(SRCSNAME_CH))
OBJSNAME_CH = $(SRCSNAME_CH:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS_CH = $(OBJSPATH_CH)*.o

SRCSNAME_PS = push_swap.c \
			  	ft_arg.c \
				ft_indexing.c case_5.c \
				ft_solve.c opti.c ft_stack_sort.c \
				ft_loop.c ft_push_back_to_a.c \
				stack/ft_s.c stack/ft_p.c \
				stack/ft_r.c stack/ft_rr.c \
				stack/ft_rotator.c stack/ft_push_init.c \
				stack/ft_get_last.c \
				ft_is_sort.c ft_free.c \
				ft_isint.c ft_isnum.c \
				ft_utils.c ft_utils_2.c \

SRCS_PS = $(addprefix $(SRCSPATH), $(SRCSNAME_PS))
OBJSNAME_PS = $(SRCSNAME_PS:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS_PS = $(OBJSPATH_PS)*.o

# *************************************************************************** #

all: checker push_swap

checker: $(LBM)
	@mkdir $(OBJSPATH_CH) 2> /dev/null || true
	@$(CC) -I$(INC) $(LBINC) -c $(SRCS_CH)
	@mv *.o $(OBJSPATH_CH)
	$(CC) $(OBJS_CH) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(CH)
	@echo "$(B)$(MAG)$(BEL)\n\t $(CH)\tcompiled!\n$(D)"

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
	@$(RM) $(CH) $(PS) *.o
	@make -C $(LBPATH) -f Makefile fclean

re: fclean all

.PHONY: all, clean, fclean, re, lib, checker, push_swap

# **************************************************************************** #
