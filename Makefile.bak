##
## Makefile for malloc in /home/plasko_a/programation/c/malloc
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Thu Aug 28 22:53:51 2014 Antoine Plaskowski
## Last update Sun Feb 15 21:43:16 2015 Antoine Plaskowski
##

HOSTTYPE		=	$(shell echo $(shell uname -m)-$(shell uname -s) | tr [:upper:] [:lower:])

NAME			=	libmy_malloc_$(HOSTTYPE).so

SL_NAME			=	libmy_malloc.so

CC			?=	gcc

LN			=	ln

RM			=	rm -f

MKDIR			=	mkdir -p

RMDIR			=	rmdir --ignore-fail-on-non-empty

ECHO			=	/bin/echo

DEBUG			?=	no

LEVEL			?=	3

COLOR			?=	no

LIB			=	-l pthread

INCLUDE			=	-I include/

CFLAGS			=	-Wall -Wextra -O$(LEVEL)
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-fPIC
CFLAGS			+=	$(INCLUDE)

ifeq ($(CC), clang)
CFLAGS			+=	-Weverything -Wno-padded
endif

ifneq ($(DEBUG), no)
CFLAGS			+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS			+=	-fdiagnostics-color
endif

LDFLAGS			=	-shared -Wl,-e,start_lib
LDFLAGS			+=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS			+=	-s
endif

DFLAGS			=	-Y -w80 $(INCLUDE)

SRC			=

include				source.mk

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME) $(SL_NAME)

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(SL_NAME)		:
				$(LN) -s $(NAME) $(SL_NAME)

clean			:
				$(RM) $(OBJ)

fclean			:
				$(RM) $(OBJ)
				$(RM) $(NAME) $(SL_NAME)

re			:	fclean all

depend			:
				makedepend $(SRC) $(DFLAGS)

%.o			:	%.c
				$(CC) -c $< -o $@ $(CFLAGS)

%.s			:	%.c
				$(CC) -S $< -o $@ $(CFLAGS)

.PHONY			:	all clean fclean re %.o %.s

.SUFFIXES		:	.o.c .s.c

# DO NOT DELETE

source/malloc.o: include/malloc.h include/algo_list.h include/manage_list.h
source/malloc.o: include/algo.h
source/start_lib.o: include/start_lib.h
source/manage_list.o: include/malloc.h include/manage_list.h
source/algo_list.o: include/malloc.h include/manage_list.h include/algo_list.h
source/algo.o: include/algo.h
