
NAME			:=	solong.a
MAIN			:=	solong.c
MLXFLAGS		:=	-lmlx -framework OpenGL -framework AppKit
HEADER			:=	solong.h
CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
AR				:=	ar acs
RM				:=	rm -rf

SRC				:=	solong
SRCS			:=	$(addsuffix .c, $(SRC))
OBJS			:=	$(addsuffix .o, $(SRC))

OBJ_DIR			:=	obj
OBJS			:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		:=	./libft
LIBFT			:= $(LIBFT_PATH)/libft.a

MLX_PATH		:=	./minilibx-linux
MLX				:= $(MLX_PATH)/libmlx.a

.c: $(SRCS)
				$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
				cp $(MLX) $(NAME)
				$(AR) obj/*.c solong.a

$(LIBFT):
				make -C $(LIBFT_PATH) all

$(MLX):			
				make -C $(MLX_PATH) all

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				make -C $(LIBFT_PATH) clean
				make -C $(MLX_PATH) clean
				$(RM) OBJ_DIR/

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				make -C $(MLX_PATH) clean
				$(RM) $(OBJ_DIR)/

fclean+:		clean
				make -C $(LIBFT_PATH) fclean
				make -C $(MLX_PATH) clean
				$(RM) $(OBJ_DIR)/
				$(RM) a.out

re:				fclean all

exec:			re
				$(CC) $(CFLAGS) $(MLXFLAGS) $(MAIN) $(NAME)
				./a.out

.PHONY: all clean fclean re

.SILENT:clean