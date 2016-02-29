/*
** algo_list.c for algo_list in /home/plasko_a/projet/epitech/PSU_2014_malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Feb 15 13:24:10 2015 Antoine Plaskowski
** Last update Sun Feb 15 14:22:51 2015 Antoine Plaskowski
*/

#include	"malloc.h"
#include	"manage_list.h"
#include	"algo_list.h"

t_meta		*find_memory(t_meta *l_free, size_t size)
{
  l_free = first_list(l_free);
  while (l_free != NULL)
    {
      if (size <= l_free->size)
	return (l_free);
      l_free = l_free->next;
    }
  return (l_free);
}
