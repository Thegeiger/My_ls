/*
** tab_pointer.c for tab_pointer in /home/geiger_a/rendu/PSU_2014_my_ls
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Sat Nov 29 10:50:10 2014 anthony geiger
** Last update Fri Feb 20 11:49:14 2015 anthony geiger
*/

#include "struc.h"
#include <dirent.h>
#include <stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		how_many_files(char *argv)
{
  int		i;
  struct dirent	*ep;
  DIR		*rep;

  i = 0;
  rep = opendir(argv);
  if (rep == NULL)
    return (0);
  while ((ep = readdir(rep)))
    {
      i++;
    }
  return (i + 1);
}

char		**my_stock_name(char *argv)
{
  char		**tab;

  tab = malloc(sizeof(char *) * how_many_files(argv));
  if (tab == NULL)
    return (NULL);
  return (tab);
}

char		*my_strdup(char *str)
{
  char		*dest;
  int		i;

  i = 0;
  dest = malloc(sizeof(char) * my_strlen(str) + 1);
  if (dest == NULL)
    return (NULL);
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		**my_put_in_tab(char **tab, char *argv)
{
  DIR		*rep;
  struct dirent	*ep;
  int		i;

  i = 0;
  rep = opendir(argv);
  if (rep == NULL)
    return (NULL);
  while ((ep = readdir(rep)))
    {
      if (ep->d_name[0] == '.')
	continue ;
      tab[i] = (my_strdup(ep->d_name));
      i++;
    }
  tab[i] = NULL;
  closedir(rep);
  return (tab);
}
