/*
** malloc.c for malloc in /home/plasko_a/programation/c/malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Aug 28 23:09:29 2014 Antoine Plaskowski
** Last update Sun Feb 15 21:38:31 2015 Antoine Plaskowski
*/

#define		_BSD_SOURCE
#define		_DEFAULT_SOURCE

#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdint.h>
#include	<pthread.h>
#include	<errno.h>
#include	"malloc.h"
#include	"algo_list.h"
#include	"manage_list.h"
#include	"algo.h"

static t_meta	*g_free = NULL;
static t_meta	*g_heap = NULL;
static void	*g_break = NULL;
static pthread_mutex_t	mutex_stock = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t const size)
{
  t_meta	*meta;
  size_t	true_size;

  pthread_mutex_lock(&mutex_stock);
  if ((meta = find_memory(g_free, size)) != NULL)
    g_free = sup_list(meta);
  else
    {
      true_size = multiple_pagesize(sizeof(*meta) + size);
      if ((meta = sbrk((intptr_t)true_size)) == E_SBRK)
	{
	  pthread_mutex_unlock(&mutex_stock);
	  return (NULL);
	}
      meta->size = true_size - sizeof(*meta);
      if (g_heap == NULL)
	g_heap = meta;
      g_break = (char *)(meta + 1) + meta->size;
    }
  pthread_mutex_unlock(&mutex_stock);
  return (meta + 1);
}

void		*calloc(size_t const nmemb, size_t const size)
{
  size_t const	size_total = nmemb * size;
  void * const	ptr = malloc(size_total);

  return (ptr != NULL ? memset(ptr, 0, size_total) : NULL);
}

void		*realloc(void * const ptr, size_t const size)
{
  void		*data;
  t_meta	*meta;

  if (ptr == NULL)
    return (malloc(size));
  meta = (t_meta *)ptr - 1;
  if (size <= meta->size)
    return (ptr);
  if ((data = malloc(size)) == NULL)
    return (data);
  memcpy(data, ptr, meta->size);
  free(ptr);
  return (data);
}

void		free(void * const ptr)
{
  t_meta	*meta;

  pthread_mutex_lock(&mutex_stock);
  if (ptr == NULL)
    {
      pthread_mutex_unlock(&mutex_stock);
      return;
    }
  meta = (t_meta *)ptr - 1;
  g_free = push_list(g_free, meta);
  pthread_mutex_unlock(&mutex_stock);
}

void		show_alloc_mem(void)
{
  t_meta	*tmp;
  void		*next;

  printf("break : %p\n", g_break);
  tmp = g_heap;
  while (tmp != g_break)
    {
      next = (char *)(tmp + 1) + tmp->size;
      printf("%p  %p : %lu octets\n", (void *)(tmp + 1), next, tmp->size);
      tmp = next;
    }
}
