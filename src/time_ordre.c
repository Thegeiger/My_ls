/*
** time_ordre.c for time in /home/geiger_a/rendu/PSU_2014_my_ls
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Fri Nov 28 16:22:39 2014 anthony geiger
** Last update Fri Feb 20 11:50:04 2015 anthony geiger
*/

#include "struc.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int		*my_time_in_tab(char *argv)
{
  int		*tab;
  DIR		*rep;
  struct stat	statinfo;
  int		i;
  struct dirent	*ep;

  i = 0;
  if ((tab = malloc(sizeof(int) * how_many_files(argv))) == NULL)
    return (0);
  rep = opendir(".");
  if (rep == NULL)
    return (0);
  while ((ep = readdir(rep)))
    {
      if (ep->d_name[0] == '.')
	continue;
      lstat(ep->d_name, &statinfo);
      tab[i] = statinfo.st_mtime;
      i++;
    }
  tab[i] = 0;
  return (tab);
}

int	my_strcmpnb(int nb1, int nb2)
{
  if (nb1 < nb2)
    return (1);
  if (nb1 > nb2)
    return (- 1);
  return (0);
}

int	swap_alphanb(char **tab, int x, int *nbtab)
{
  int	pass;
  char	*m;
  int	swpnb;

  if (my_strcmpnb(nbtab[x - 1], nbtab[x]) == -1)
    {
      swpnb = nbtab[x - 1];
      nbtab[x - 1] = nbtab[x];
      nbtab[x] = swpnb;
      m = tab[x - 1];
      tab[x - 1] = tab[x];
      tab[x] = m;
      pass = 1;
    }
  return (pass);
}

int	swap_unalphanb(char **tab, int x, int *nbtab)
{
  int	pass;
  char	*m;
  int	swpnb;

  if (my_strcmpnb(nbtab[x - 1], nbtab[x]) == 1)
    {
      swpnb = nbtab[x - 1];
      nbtab[x - 1] = nbtab[x];
      nbtab[x] = swpnb;
      m = tab[x - 1];
      tab[x - 1] = tab[x];
      tab[x] = m;
      pass = 1;
    }
  return (pass);
}

char	**my_time_ordre(char **tab, int *nbtab, t_boole *s)
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
	    pass = swap_alphanb(tab, x, nbtab);
	  else
	    pass = swap_unalphanb(tab, x, nbtab);
	  x++;
	}
      my_putstr("");
    }
  return (tab);
}
