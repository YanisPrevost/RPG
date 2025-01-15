##
## EPITECH PROJECT, 2024
## B-MUL-200-MAR-2-1-myrpg-yanis.prevost
## File description:
## Makefile
##

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m
BOLD = \033[1m

SRCLIB	=	lib/my_atoi.c 		\
			lib/my_inttostr.c	\
			lib/my_strlen.c 	\
			lib/my_strcmp.c 	\
			lib/my_strcat.c 	\
			lib/my_printf.c 	\
			lib/my_put_nbr.c 	\
			lib/my_put_nbr_recursive.c 	\
			lib/my_putstr.c 	\
			lib/my_putchar.c 	\
			lib/str_to_word_array.c\

SRCNAME	=	src/*.c	\
			src/menu/*.c	\
			src/setup/*.c	\
			src/inventaire/*.c	\
			src/setting_folder/*.c	\
			src/shop/*.c	\
			src/fight_interface/*.c	\
			src/rng/*.c	\
			src/dialogue_code/*.c	\
			src/hub/*.c	\
			src/all_word/*.c	\
			src/gameplay/*.c	\

LIB 	= 	libmy.a

OBJLIB	=	$(SRCLIB:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME	=	my_rpg

UNAME	:=	$(shell uname -s)

1	= 	-I/opt/homebrew/Cellar/csfml/2.5.2_1/include/

2 	= 	-L/opt/homebrew/Cellar/csfml/2.5.2_1/lib

$(NAME): $(LIB) $(OBJNAME)
	@echo "$(YELLOW)$(BOLD)Compiling for $(UNAME)...$(NC)"
ifeq ($(UNAME),Linux)
	gcc -o $(NAME) $(SRCNAME) -lmy -L./ $(CSFML) $(CFLAGS) -g3
else ifeq ($(UNAME),Darwin)
	gcc -w -o $(NAME) $(SRCNAME) -lmy -L./ $(CSFML) $(1) $(2) -g3
endif
	@echo "$(GREEN)$(BOLD)Executable $(NAME) created!$(NC)"

$(LIB): $(OBJLIB)
	@echo "$(BLUE)$(BOLD)Creating static library $(LIB)...$(NC)"
	ar rc libmy.a lib/*.o
	rm lib/*.o
	@echo "$(GREEN)$(BOLD)Static library $(LIB) created!$(NC)"

all: $(LIB) $(NAME)

clean:
	@echo "$(RED)$(BOLD)Cleaning up object files and library...$(NC)"
	rm -f $(OBJLIB) $(OBJNAME) libmy.a
	@echo "$(GREEN)$(BOLD)Clean complete!$(NC)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(NC)"
	rm -f $(NAME)
	rm -rf my_rpg.dSYM
	@echo "$(GREEN)$(BOLD)Full clean complete!$(NC)"

re: fclean all
	@echo "$(YELLOW)$(BOLD)Rebuilding everything...$(NC)"
