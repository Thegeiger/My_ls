##
## Makefile for make in /home/geiger_a/rendu/MY_LS
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Sun Nov 23 15:17:22 2014 anthony geiger
## Last update Fri Feb 20 11:46:51 2015 anthony geiger
##

CC	= gcc

RM      = rm -f

NAME    = my_ls

CFLAGS  += -Wextra -Wall -Werror -g
CFLAGS  += -pedantic
CFLAGS  += -I./include

LDFLAGS =

SRCS    = src/my_putnbr.c \
	src/my_word_in_tab.c \
        src/my_putstr.c \
        src/my_ls.c \
	src/time_ordre.c \
	src/alpha_order.c \
	src/help.c \
	src/tab_pointer.c \
	src/case_l.c \
	src/case_d.c \
        src/my_putchar.c

OBJS    = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
