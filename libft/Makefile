cc = gcc
TARGET = a.out

SRC = ./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_strlen.c \
		./ft_strlcpy.c \
		./ft_strlcat.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strnstr.c \
		./ft_strncmp.c \
		./ft_atoi.c \
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_toupper.c \
		./ft_tolower.c

OBJ = $(SRC:.c=.o)

$(NAME) = libft.o

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lc

all : $(TARGET)

$(TARGET) : $(NAME)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) $@ $<

clean :
	rm -f $(OBJS) $(TARGET)
#  $(NAME), all, clean, fclean, re