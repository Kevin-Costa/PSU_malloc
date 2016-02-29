/*
** algo.h for algo in /home/plasko_a/projet/epitech/PSU_2014_malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Feb 15 14:29:55 2015 Antoine Plaskowski
** Last update Sun Feb 15 14:41:32 2015 Antoine Plaskowski
*/

#ifndef		ALGO_H_
# define	ALGO_H_

# include	<stddef.h>
# include	<unistd.h>

# define	PSIZE	(size_t)sysconf(_SC_PAGESIZE)

size_t		multiple_pagesize(size_t const size);

#endif		/* !ALGO_H_ */
