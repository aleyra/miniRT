.PHONY: all clean fclean re

# Name of file
NAME		=	miniRT

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	logs
PATH_LIBFT	=	libft
PATH_LIBG	=	minilibx

# List of sources
SRCS_DISP	=	#add file ds display
SRCS		=	$(addprefix $(PATH_SRC)/display/, $(SRCS_DISP)) \
				$(addprefix $(PATH_SRC)/, ) #add files à la racine

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(addprefix $(PATH_INC)/, ) #add .h
LIBFT		=	-L$(PATH_LIBFT)

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra
COMP_ADD	=	-I$(PATH_LIBFT)/includes -I$(PATH_INC)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ $(shell mkdir -p $(PATH_OBJ))
	@ make -C $(PATH_LIBFT)
	@ make -C $(PATH_LIBG)

$(NAME): $(OBJS) $(INCS)
#	@ $(shell cp libft/libft.a $(NAME))
#	@ ln -sf  minilibx/libmlx.dylib

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $(NAME)
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $(NAME)
	@ echo "$(_INFO) Compilation of $*"

#test: init $(NAME)
#	@ $(COMP) $(COMP_FLAG) main.c -L. ????? $(COMP_ADD)
#	@ ./a.out

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"
	@ make -C $(PATH_LIBFT) clean

fclean: clean
#	@ $(RM) -rf $(NAME)
	@ make -C $(PATH_LIBFT) fclean

re: fclean all
