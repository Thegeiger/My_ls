/*
** alpha_order.c for alpha order in /home/geiger_a/rendu/MY_LS
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 23 19:09:07 2014 anthony geiger
** Last update Sun Nov 30 14:31:21 2014 anthony geiger
*/

#include <stdlib.h>
#include "struc.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	a;
  int	b;

  i = 0;
  while (s1[i] != '\0' || s2 != '\0')
    {
      a = 0;
      b = 0;
      if (s1[i] >= 'A' && s1[i] <= 'Z')
	a = 32;
      if (s2[i] >= 'A' && s2[i] <= 'Z')
	b = 32;
      if (s1[i] + a < s2[i] + b)
	return (1);
      if (s1[i] + a > s2[i] + b)
	return (-1);
      i++;
    }
  return (1);
}

int	swap_alpha(char **tab, int x)
{
  int	pass;
  char	*m;

  if (my_strcmp(tab[x - 1], tab[x]) == -1)
    {
      m = tab[x - 1];
      tab[x - 1] = tab[x];
      tab[x] = m;
      pass = 1;
    }
  return (pass);
}

int	swap_unalpha(char **tab, int x)
{
  int	pass;
  char	*m;

  if (my_strcmp(tab[x - 1], tab[x]) == 1)
    {
      m = tab[x - 1];
      tab[x - 1] = tab[x];
      tab[x] = m;
      pass = 1;
    }
  return (pass);
}

char	**my_put_alpha_tab(char **tab, t_boole *s)
{
  int	x;
  int	pass;

  pass = 1;
  if (tab[0] == NULL)
    return (NULL);
  while (pass == 1)
    {
      pass = 0;
      x = 1;
      while (tab[x] != NULL)
	{
	  if (s->flagr == 0)
	    {
	      pass = swap_alpha(tab, x);
	    }
	  else
	    pass = swap_unalpha(tab, x);
	  x++;
	}
      my_putstr("");
    }
  return (tab);
}
