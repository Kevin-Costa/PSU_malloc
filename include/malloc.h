/*
** malloc.h for malloc in /home/plasko_a/programation/c/malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Aug 28 23:23:55 2014 Antoine Plaskowski
** Last update Sun Feb 15 15:41:01 2015 Antoine Plaskowski
*/

#ifndef		MALLOC_H_
# define	MALLOC_H_

# include	<stdbool.h>
# include	<stddef.h>

# define	E_SBRK		((void *)-1)

typedef	struct	s_meta	t_meta;

struct		s_meta
{
  size_t	size;
  t_meta	*prev;
  t_meta	*next;
};

void		*malloc(size_t const size);
void		*calloc(size_t const nmemb, size_t const size);
void		*realloc(void * const ptr, size_t const size);
void		free(void * const ptr);
void		show_alloc_mem(void);

#endif		/* !MALLOC_H_ */
