/*
** start_lib.c for start_lib in /home/plasko_a/projet/epitech/PSU_2014_malloc/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Feb  2 22:38:00 2015 Antoine Plaskowski
** Last update Thu Feb 12 05:50:29 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

#include	"start_lib.h"

const char malloc_interp[] __attribute__((section(".interp"))) =
  "/usr/lib/ld-linux-x86-64.so.2";

void		start_lib(void)
{
  char		*coucou = "coucou\n";
  write(1, coucou, strlen(coucou));
  _exit(0);
}
