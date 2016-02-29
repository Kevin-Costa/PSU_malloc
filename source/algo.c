/*
** algo.c for algo in /home/plasko_a/projet/epitech/PSU_2014_malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Feb 15 14:28:46 2015 Antoine Plaskowski
** Last update Sun Feb 15 14:35:06 2015 Antoine Plaskowski
*/

#include	"algo.h"

size_t		multiple_pagesize(size_t const size)
{
  return (size + (PSIZE - size % PSIZE));
}
