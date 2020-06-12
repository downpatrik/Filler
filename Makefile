# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 15:19:28 by wvenita           #+#    #+#              #
#    Updated: 2020/06/06 22:47:10 by wvenita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	wvenita.filler

FLAGS	=	-Wall -Wextra -Werror

LIBDIR	=	libft
LIBLINK	=	-L $(LIBDIR) -lft
LIB		=	$(LIBDIR)/libft.a

SRCDIR	=	src
OBJDIR	=	tmp
SRCNAME	=	main.c\
			ft_filler.c\
			ft_parsing.c\
			ft_determinant.c\
			ft_free.c

SRC		=	$(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ		=	$(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

HEADERN	=	ft_filler.h
HAEDER	=	$(addprefix $(INCDIR), $(HEADERN))
INCDIR	=	./includes/
INCL	=	./libft/

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIB) $(HEADER)
		@$(CC) $(FLAGS) -o $@ $(OBJ) $(LIBLINK)
		-@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR):
		@mkdir -p tmp

$(LIB):
		@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HAEDER)
		@$(CC) $(FLAGS) -I $(INCDIR) -I $(INCL) -o $@ -c $<

clean:
		@make -C $(LIBDIR) clean
		@rm -rf $(OBJDIR)

fclean: clean
		@rm -f $(NAME)
		@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean