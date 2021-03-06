# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 11:53:15 by sle-guil          #+#    #+#              #
#    Updated: 2015/03/24 15:16:33 by sle-guil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
LOGIN_AUTEUR = sle_guil
DEBUG = no

HEADER = ./includes
SRCS_DIR = ./srcs/
LIBFT = libft/libft.a

SRCS_NAME =	main.c		print_prompt.c	parse.c		interpreteur.c	\
			builtins.c	runcmd.c		history.c	env_cp.c		\
			getenv_p.c	getenv_cpy.c	testpath.c	er_notfound.c	\
			bi_env.c	parse_path.c	bi_exit.c	bi_unsetenv.c	\
			env_free.c	env_refresh.c	script.c	bi_setenv.c		\
			bi_cd.c		bi_history_print.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

CC = clang
C_FLAG = -Wall -Wextra -Werror -pipe

ifeq ($(DEBUG), yes)
OPT_FLAG = -O0 -g
else
OPT_FLAG = -Os -g0
endif

#===============================#
#		Compilation rules 		#
#===============================#

all: $(NAME)

$(NAME): libft $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADER)
	@echo "$(NAME) created with $(OPT_FLAG) flag"

%.o: %.c
	@$(CC) -o $@ -c $< $(C_FLAG) $(OPT_FLAG) -I $(HEADER)
	@echo "$@ created"

libft:
	@make -C libft/

#===============================#
#		repository rules		#
#===============================#

set_debug:
	@cat Makefile | sed "s/DEBUG = no/DEBUG = yes/" > Makefile
	@echo "DEBUG MODE SET"

unset_debug:
	@cat Makefile | sed "s/DEBUG = yes/DEBUG = no/" > Makefile
	@echo "DEBUG MODE UNSET"

norme:
	@norminette $(SRCS)

auteur:
	@echo "$(LOGIN_AUTEUR)" > auteur

#===============================#
#		Cleaning rules			#
#===============================#

clean:
	@/bin/rm -f $(OBJS)
	@echo "*** cleaning object file"

libclean:
	@make -C libft/ fclean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "*** Binary file $(NAME) cleaned"

re: fclean libclean all

.PHONY: all libft clean libclean fclean re auteur
