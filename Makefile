# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dfreire <dfreire@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/22 14:56:24 by dfreire        #+#    #+#                 #
#    Updated: 2019/05/31 18:32:44 by dfreire       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes

LIBFT_HEADER = -I./libft/includes

LIBFT_BINARY = -L./libft -lft

LIBFT = libft/libft.a

SRCS1 = push_swap.c parsing_args.c apply_ops_s.c apply_ops_p.c apply_ops_r.c\
		apply_ops_rr.c sorting.c general_sorting.c handling_stacks.c\
		finding_min_max.c define_rotations.c moves_a_to_b.c
SRCS2 = checker.c parsing_args.c apply_ops_s.c apply_ops_p.c apply_ops_r.c\
		apply_ops_rr.c handling_stacks.c

.PHONY: all clean fclean re

RED	= \033[0;31m
GREEN =	\033[0;32m
RESET = \033[0m

OBJDIR = objects

OBJS1 	= $(addprefix $(OBJDIR)/,$(SRCS1:.c=.o))
OBJS2 	= $(addprefix $(OBJDIR)/,$(SRCS2:.c=.o))

all: $(LIBFT) $(NAME1) $(NAME2)

$(LIBFT):
		@make -C libft re

$(OBJDIR):
		@mkdir $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
		@$(CC) $(CFLAGS) $(HEADER) $(LIBFT_HEADER) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT)
		@echo "$(GREEN)Compiling push_swap...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJS1) $(LIBFT_BINARY) -o $@
		@echo "$(GREEN)push_swap is ready$(RESET)"

$(NAME2): $(OBJS2) $(LIBFT)
		@echo "$(GREEN)Compiling checker...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJS2) $(LIBFT_BINARY) -o $@
		@echo "$(GREEN)checker is ready$(RESET)"

clean:
		@echo "$(RED)deleting object files...$(RESET)"
		@/bin/rm -f $(OBJS1) $(OBJS2)
		@rm -rf $(OBJDIR)
		@make -C ./libft clean

fclean: clean
		@echo "$(RED)deleting both executables...$(RESET)"
		@/bin/rm -f $(NAME1)
		@/bin/rm -f $(NAME2)
		@make -C ./libft fclean

re: fclean all