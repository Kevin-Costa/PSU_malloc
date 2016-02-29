/*
** manage_list.h for manage_list in /home/plasko_a/projet/epitech/PSU_2014_malloc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Feb 15 13:48:54 2015 Antoine Plaskowski
** Last update Sun Feb 15 13:49:45 2015 Antoine Plaskowski
*/

#ifndef		MANAGE_LIST_H_
# define	MANAGE_LIST_H_

# include	"malloc.h"

t_meta		*first_list(t_meta *meta);

t_meta		*push_list(t_meta *old, t_meta *meta);

t_meta		*sup_list(t_meta *meta);

#endif		/* !MANAGE_LIST_H_ */
