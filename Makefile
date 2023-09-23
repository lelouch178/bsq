##
## EPITECH PROJECT, 2023
## Makefiles Project
## File description:
## Makefile | Originally created by Adrien LACHAMBRE | Edited by Virgile LEGROS
##

# ================================= [SETUP] ================================== #

ifeq ($(shell uname),Linux)
    ECHO := echo -e
else ifeq ($(OS),Windows_NT)
    ECHO := echo.
else
    ECHO := echo
endif

DEFAULT 	=	"\033[0m"
BOLD_T  	=	"\033[1m"
DIM_T   	=	"\033[2m"
RED_C		=	"\033[38;2;102;9;0m" # 102 9 0
GOLD_C 		=	"\033[38;2;230;175;21m" # 230 175 21
LIGHT_RED	=	"\033[38;2;168;15;1m" # 168 15 1
LIGHT_GOLD	=	"\033[38;2;250;242;94m" # 250 242 94
PURPLE_C   	=	"\033[38;2;119;0;173m"# rgb(119, 0, 173)
BLUE_C 		=	"\033[38;2;131;187;251m"# rgb(131, 187, 251)
LIGHT_PURPLE=	"\033[38;2;157;0;230m"# rgb(157, 0, 230)
LIGHT_BLUE	=	"\033[38;2;185;217;253m"# rgb(185, 217, 253)
GREEN_C 	=	"\033[32m"
LIGHT_CYAN	=	"\033[96m"

define success_message
	@$(ECHO) $(BOLD_T)$(GOLD_C)"\n[✔] COMPILED:"$(DEFAULT)$(LIGHT_GOLD)		\
	"$(1)\n"$(DEFAULT) || $(ECHO)$(BOLD_T)$(RED_C)"[✘]				   		\
		"$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED)"$(1)\n"$(DEFAULT)
endef

define fail_message
	$(ECHO) $(BOLD_T)$(RED_C)"[✘] BUILD FAILED:"$(LIGHT_RED) "$(1)\n"$(DEFAULT)
endef

# ================================ [PROJECT] ================================= #

SRC			=   src/main.c 													\
				src/bsq.c 													\
				src/utils.c 												\
    			src/my_getnbr.c 											\
				src/error_from_file.c										 \
				src/error_from_line.c 										\
				src/get_nbr_rows_cols.c 									\
				src/find_square_max_size.c 									 \
				src/error_from_generation.c 								\
    			src/load_file_and_init_array.c 								 \

OBJ 		= 	$(patsubst src/%.c,obj/%.o,$(SRC))

NAME		=	bsq

CFLAGS    	+=	-Wall -Wextra -Wfloat-equal -Wundef -Wcast-align			\
				-Wwrite-strings -Wredundant-decls -Wshadow -I./include

MAKEFLAGS	+=	--no-print-directory

# ============================== [BASIC RULES] =============================== #

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(OBJ) $(CFLAGS) -o $(NAME)
	$(call success_message, $(NAME))

clean:
	@find . -type f \( -iname "*~" \) -delete
	@find . -name "*.o" -delete -o -name "*.gcno" -delete -o -name "*.gcda"
	@$(RM) -f tests/unit_test
	@$(RM) generate_map
	@$(ECHO) $(PURPLE_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(PURPLE_C) \
		"DELETED: "$(DEFAULT) $(LIGHT_PURPLE)"$(NAME)'s unit_test"$(DEFAULT)
	@$(RM) -rf obj/
	@$(ECHO) $(PURPLE_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(PURPLE_C) \
		"DELETED: "$(DEFAULT) $(LIGHT_PURPLE)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(PURPLE_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(PURPLE_C) \
		"DELETED: "$(DEFAULT) $(LIGHT_PURPLE)"$(NAME)'s valgrind files"		\
	$(DEFAULT)

fclean:
	@$(RM) $(NAME)
	@$(RM) -rf obj/
	@$(ECHO) $(PURPLE_C)$(DIM_T)"[fclean] "$(DEFAULT) $(BOLD_T)$(PURPLE_C)	\
		"DELETED: "$(DEFAULT) $(LIGHT_PURPLE)"$(NAME) binary"$(DEFAULT)

re:	fclean	all

# ============================== [UTILS RULES] =============================== #

lib:
	@make re -C ./lib/my/

obj/%.o:	src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && $(ECHO) $(BLUE_C)"[OK] "	\
	$(BOLD_T)"$<"$(DEFAULT) || ($(ECHO) $(PURPLE_C)[KO]$(BOLD_T)"$<"		\
	$(DEFAULT); $(call fail_message, $(NAME)); exit 1)

# ============================ [DEBUGGING RULES] ============================= #

debug:
	@gcc $(SRC) $(CFLAGS) -g -o $(NAME)
	$(call success_message, $(NAME))

valgrind:
	@gcc $(SRC) $(CFLAGS) -g3 -o $(NAME)
	$(call success_message, $(NAME))
	@make clean
	@valgrind -s --track-origins=yes ./$(NAME) $(ARGS)

valgrind_plus	$(KINDS):
	@echo "KINDS= all | definite | indirect | possible | reachable"
	@gcc $(SRC) $(CFLAGS) -g3 -o $(NAME)
	$(call success_message, $(NAME))
	@make clean
	@valgrind -s --track-origins=yes --leak-check=full						\
	--show-leak-kinds=$(KINDS) ./$(NAME) $(ARGS)
KINDS	?=	all

g3only:
	@gcc $(SRC) -o $(NAME) $(CFLAGS) -g3
	$(call success_message, $(NAME))
	@make clean

gprof	$(ARGS):
	@$(ECHO) $(BLUE_C)"\nRunning gprof" $(DEFAULT)
	@gcc $(SRC) -o $(NAME) $(CFLAGS) -pg
	$(call success_message, $(NAME))
	@./$(NAME) $(ARGS)
	@make clean
	@gprof -b -p $(NAME)

GITIGNORE_FILES = *.o *.a *.log *.json *.vscode vgcore.* .idea/ *.txt		\
					$(NAME) .devcontainer/ .DS_Store .gitignore				\
					*.gcno *.gcda tests/unit_tests html/ coverage.*         \

gitignore:
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[DOING GITIGNORE]$(DEFAULT)$(GREEN_C);	\
	for file in $(GITIGNORE_FILES); do										 \
	    $(ECHO) $$file; 													 \
	done >> .gitignore;

.PHONY: all clean fclean re lib debug valgrind valgrind_plus g3only gprof	\
		gitignore
