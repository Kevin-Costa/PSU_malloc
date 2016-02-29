/*
** manage_list.c for manage_list in /home/plasko_a/projet/epitech/PSU_2014_malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Feb 15 13:18:33 2015 Antoine Plaskowski
** Last update Sun Feb 15 15:24:32 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	"malloc.h"
#include	"manage_list.h"

t_meta		*first_list(t_meta *meta)
{
  if (meta != NULL)
    while (meta->prev != NULL)
      meta = meta->prev;
  return (meta);
}

t_meta		*push_list(t_meta *old, t_meta *meta)
{
  if ((old = first_list(old)) == NULL)
    {
      meta->prev = NULL;
      meta->next = NULL;
      return (meta);
    }
  old->prev = meta;
  meta->prev = NULL;
  meta->next = old;
  return (old);
}

t_meta		*sup_list(t_meta *meta)
{
  t_meta	*ret;

  if (meta == NULL)
    return (NULL);
  if (meta->prev != NULL)
    {
      meta->prev->next = meta->next;
      ret = meta->prev;
    }
  else
    ret = meta->next;
  if (meta->next != NULL)
    meta->next->prev = meta->prev;
  return (first_list(ret));
}
