# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:14:39 by albernar          #+#    #+#              #
#    Updated: 2024/11/05 23:21:44 by albernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
CC = cc
FLAGS = -Wall -Wextra -Werror -g

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# FOLDERS
OBJ_DIR = .objs

# SOURCES
FT_PRINTF_PATH = ./lib/ft_printf/
LIBFT_PATH = ./lib/libft/

SRCS = \
main.c \
mandatory/process.c \
mandatory/process_utils.c \
mandatory/utils.c

SRCS_BONUS = \
main_bonus.c \
bonus/process_bonus.c \
bonus/heredoc_bonus.c \
mandatory/process_utils.c \
mandatory/utils.c

# OBJECTS
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

# EXECUTABLES
FT_PRINTF_LIB = $(addprefix $(FT_PRINTF_PATH), libftprintf.a)
LIBFT_LIB = $(addprefix $(LIBFT_PATH), libft.a)
NAME = pipex
NAME_BONUS = pipex_bonus

# RULES
all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(LIBFT_LIB) $(OBJS)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(FT_PRINTF_LIB) $(LIBFT_LIB) $(BONUS_OBJS)
	@echo "$(YELLOW)Creating $(NAME_BONUS)...$(RESET)"
	@$(CC) $(FLAGS) $(BONUS_OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) created successfully!$(RESET)"
	
$(OBJ_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -I./includes -o $@ -c $<

$(FT_PRINTF_LIB):
	@echo "$(YELLOW)Compiling FT_PRINTF...$(RESET)"
	@make -C $(FT_PRINTF_PATH) -s
	@echo "$(GREEN)FT_PRINTF created successfully!$(RESET)"

$(LIBFT_LIB):
	@echo "$(YELLOW)Compiling LIBFT...$(RESET)"
	@make -C $(LIBFT_PATH) -s
	@echo "$(GREEN)LIBFT created successfully!$(RESET)"
	
clean:
	@echo "$(RED)Cleaning FT_PRINTF files...$(RESET)"
	@make clean -C $(FT_PRINTF_PATH) -s
	@echo "$(RED)Cleaning LIBFT files...$(RESET)"
	@make clean -C $(LIBFT_PATH) -s
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@echo "$(RED)Cleaning FT_PRINTF files...$(RESET)"
	@make fclean -C $(FT_PRINTF_PATH) -s
	@echo "$(RED)Cleaning LIBFT files...$(RESET)"
	@make fclean -C $(LIBFT_PATH) -s
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean bonus re