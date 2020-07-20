# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 15:48:09 by flafonso          #+#    #+#              #
#    Updated: 2019/07/01 12:22:46 by flafonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_TWO = checker

# Effects
END = \033[0m
BOLD = \033[1m
UNDER = \033[4m
REV = \033[7m

# Text Colors
GREY = \033[38;5;246m
RED = \033[38;5;160m
GREEN = \033[38;5;118m
YELLOW = \033[38;5;226m
BLUE = \033[38;5;12m
PURPLE = \033[38;5;129m
CYAN = \033[38;5;45m
WHITE = \033[38;5;231m
BLACK = \033[38;5;0m

# Backgrounds Colors
IGREY = \033[48;5;246m
IRED = \033[48;5;160m
IGREEN = \033[48;5;118m
IYELLOW = \033[48;5;226m
IBLUE = \033[48;5;12m
IPURPLE = \033[48;5;129m
ICYAN = \033[48;5;45m
IWHITE = \033[48;5;231m
IBLACK = \033[48;5;0m

INCL_PATH = ./includes
MAIN_PATH = ./main
LIB_PATH = ./libsrcs
SRCS_PATH = ./srcs
OBJLIB_PATH = ./obj
OBJ_PATH = ./obj
OBJM_PATH = ./main

INCL_NAME = push_swap.h

LIB_NAME = 	ft_atoi.c		\
			ft_isdigit.c	\
			ft_isspace.c	\
			ft_strdup.c		\
			ft_strchr.c		\
			ft_putstr.c		\
			ft_strdel.c		\
			ft_strsplit.c	\
			ft_strsub.c		\
			get_next_line.c

SRCS_NAME = error.c				\
			free.c				\
			fill.c				\
			push_swap.c			\
			push_swap_next.c	\
			checker.c			\
			op_next.c			\
			op.c				\
			for_sort.c			\
			visu_event.c		\
			visu.c				\
			special_case.c		\
			pre_print.c			\
			init.c

MAIN_NAME = main_push.c		\
			main_checker.c

OBJLIB_NAME = $(LIB_NAME:.c=.o)
OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJM_NAME = $(MAIN_NAME:.c=.o)

INCL = $(addprefix $(INCL_PATH)/, $(INCL_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJM = $(addprefix $(OBJM_PATH)/,$(OBJM_NAME))

INCL = ./includes/push_swap.h

CC = gcc

FLAG = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME) $(NAME_TWO)

$(NAME): $(OBJM) $(OBJ) $(OBJLIB) $(INCL)
	@$(CC) $(FLAG) ./main/main_push.o $(OBJ) $(OBJLIB) -F/Library/Frameworks -framework SDL2 -I $(INCL) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[$(NAME) done]$(END)"
	@sleep 0.75
	@clear

$(NAME_TWO): $(OBJM) $(OBJ) $(OBJLIB) $(INCL)
	@$(CC) $(FLAG) ./main/main_checker.o $(OBJ) $(OBJLIB) -F/Library/Frameworks -framework SDL2 -I $(INCL) -o $(NAME_TWO)
	@echo "$(BOLD)$(GREEN)[$(NAME_TWO) done]$(END)"
	@sleep 0.75
	@clear

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@echo "$(BOLD)$(GREY)[...]$(END)"
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(BOLD)$(GREY)[...]$(END)"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJM_PATH)/%.o: $(MAIN_PATH)/%.c
	@echo "$(BOLD)$(GREY)[...]$(END)"
	@mkdir $(OBJM_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

norme:
	@norminette $(LIB) $(SRCS) $(INCL)

git:
	@git add -A
	@git status
	@echo "$(UNDER)$(YELLOW)Un commentaire pour ton git:$(END)\n"
	@read -p "=> " COMMIT;\
	git commit -m "$$COMMIT"
	@git push

test:
	@echo "$(END)$(BOLD)$(UNDER)Text Colors :$(END)\n\n$(GREY)Gris\n$(RED)Rouge\n$(GREEN)Vert\n$(YELLOW)Jaune\n$(BLUE)Bleu\n$(PURPLE)Violet\n$(CYAN)Cyan\n$(WHITE)Blanc\n$(BLACK)Noir"
	@echo "\n"
	@echo "$(END)$(BOLD)$(UNDER)Backgrounds Colors :$(END)\n\n$(IGREY)Gris\n$(IRED)Rouge\n$(IGREEN)Vert\n$(IYELLOW)Jaune\n$(IBLUE)Bleu\n$(IPURPLE)Violet\n$(ICYAN)Cyan\n$(IWHITE)Blanc\n$(IBLACK)Noir"
	@echo "\n"
	@echo "$(END)$(BOLD)$(UNDER)Effects :$(END)\n\nNormal\n$(END)$(BOLD)Gras\n$(END)$(UNDER)Souligner\n$(END)$(REV)Inverse$(END)"

clean:
	@rm -rf $(OBJ) $(OBJLIB) $(OBJM)
	@echo "$(BOLD)$(GREEN)[clean]$(END)"

fclean: clean
	@rm -f $(NAME) $(NAME_TWO)
	@echo "$(BOLD)$(GREEN)[fclean]$(END)"

re: fclean all
