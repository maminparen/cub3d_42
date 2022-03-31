# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 17:05:12 by cdarrell          #+#    #+#              #
#    Updated: 2021/11/20 15:01:44 by cdarrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
HEADER		=	libft.h

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

SRCS_DIR 	=	src/
SRC			=	gnl/get_next_line.c	gnl/gnl.c \
				is/ft_isalnum.c	is/ft_isalpha.c	is/ft_isascii.c	is/ft_isdigit.c	is/ft_isprint.c \
				lst/ft_lstadd_back.c	lst/ft_lstadd_front.c	lst/ft_lstclear.c	lst/ft_lstdelone.c	lst/ft_lstiter.c	lst/ft_lstlast.c	lst/ft_lstmap.c	lst/ft_lstnew.c	lst/ft_lstsize.c \
				malloc_free/ft_dyn_arr_free_char.c malloc_free/ft_dyn_arr_free_int.c	malloc_free/ft_dyn_arr_mal_char.c	malloc_free/ft_dyn_arr_mal_int.c	malloc_free/ft_free_split.c \
				math/ft_abs.c	math/ft_identity_matrix_4x4.c	math/ft_max.c	math/ft_min.c \
				mem/ft_bzero.c	mem/ft_calloc.c	mem/ft_memchr.c	mem/ft_memcmp.c	mem/ft_memcpy.c	mem/ft_memmove.c	mem/ft_memset.c \
				put/ft_nbrlen_ull.c	put/ft_putchar.c	put/ft_putchar_fd.c	put/ft_putendl_fd.c	put/ft_puterror.c	put/ft_putnbr.c	put/ft_putnbr_fd.c	put/ft_putnbr_ull.c	put/ft_putstr.c	put/ft_putstr_fd.c \
				str/ft_split.c	str/ft_strchr.c	str/ft_strcmp.c str/ft_strcpy.c	str/ft_strdup.c	str/ft_striteri.c	str/ft_strjoin.c	str/ft_strlcat.c	str/ft_strlcpy.c	str/ft_strlen.c	str/ft_strmapi.c	str/ft_strncmp.c	str/ft_strnstr.c	str/ft_strrchr.c	str/ft_strtrim.c	str/ft_substr.c \
				to/ft_atoi.c	to/ft_itoa.c	to/ft_tolower.c	to/ft_toupper.c

INCLUDE		=	include/

OBJS		=	${addprefix ${SRCS_DIR}, ${SRC:.c=.o}}

RM			=	rm -f

LIBC		=	ar -rcs

#COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[32m"
C_GOOD		=	"\033[32m"

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

$(NAME)		:	$(OBJS)
				@$(LIBC) $(NAME) $(OBJS)
				@echo "\tCompiling...\t" [ $(NAME) ] $(SUCCESS)

%.o			:	%.c	${HEADER} Makefile
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all			:	$(NAME)  

clean		:
				@${RM} ${OBJS}
				@echo "\tCleaning...\t" [ $(NAME) ] $(OK)
				
fclean		:	clean
				@${RM} ${OBJS} ${NAME}
				@echo "\tDeleting...\t" [ $(NAME) ] $(OK)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
