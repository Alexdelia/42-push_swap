# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/06/15 18:23:00 by adelille         ###   ########.fr        #
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
				ft_arg_utils.c \
				ft_utils.c \
				ft_checking.c \
				ft_check_sort.c \
				ft_operation/ft_op_s.c \
				ft_operation/ft_op_p.c \
				ft_operation/ft_op_r.c \
				ft_lst_color.c \
				ft_put_row.c

SRCS_CH = $(addprefix $(SRCSPATH), $(SRCSNAME_CH))
OBJSNAME_CH = $(SRCSNAME_CH:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS_CH = $(OBJSPATH_CH)*.o

SRCSNAME_PS = push_swap.c \
				ft_arg.c \
				ft_arg_utils.c \
				ft_utils.c \
				ft_find_best_algo.c \
				sort_algo/ft_mid_sort.c \
				sort_algo/ft_sort_3.c \
				sort_algo/ft_separate.c \
				sort_algo/ft_chunk.c \
				sort_algo/ft_opti_top_bot.c \
				sort_algo/ft_find_big_small.c \
				sort_algo/ft_locate.c \
				sort_algo/ft_sort_greater.c sort_algo/ft_sort_index.c \
				sort_algo/ft_sort_markup.c \
				sort_algo/ft_sa_needed.c \
				sort_algo/ft_b_to_a.c \
				sort_algo/ft_b_to_a.c sort_algo/ft_b_to_a_move.c \
				sort_algo/ft_align_a.c \
				markup/ft_fill_greater_keep.c markup/ft_fill_index_keep.c \
				markup/ft_fill_index.c markup/ft_init_markup.c \
				markup/ft_mt_new.c markup/ft_mt_addback.c markup/ft_mt_size.c \
				markup/ft_mt_last.c markup/ft_mt_min.c markup/ft_mt_readindex.c \
				markup/ft_mt_free.c markup/ft_free_markup.c markup/ft_mt_addfront.c \
				markup/mt_operation/ft_mt_s.c \
				markup/mt_operation/ft_mt_p.c \
				markup/mt_operation/ft_mt_r.c \
				ft_check_sort.c \
				ft_operation/ft_op_s.c \
				ft_operation/ft_op_p.c \
				ft_operation/ft_op_r.c

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
