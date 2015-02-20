/*
** my_word_in_tab.c for my_word in /home/geiger_a/rendu/Bistromathique
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Thu Nov  6 12:56:09 2014 anthony geiger
** Last update Sun Nov 30 14:24:04 2014 anthony geiger
*/

#include <stdlib.h>
#include "win.h"

int	my_pstrlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  if (str[i] != '\0')
    i++;
  return (i);
}

void	my_freetab(char **tab, int lines)
{
  int	i;

  i = 0;
  while (i < lines)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

char	**place2(char **tab, t_win *wit, char *str)
{
  if (str[wit->nb] == ' ')
    {
      tab[wit->i][wit->j] = '\0';
      wit->i++;
      wit->nb++;
      wit->j = 0;
    }
  else
    {
      tab[wit->i][wit->j] = str[wit->nb];
      wit->nb++;
      wit->j++;
    }
  return (tab);
}

char	**my_word_in_tab2(char *str, t_win *wit)
{
  char	**tab;

  tab = malloc((wit->word + 1) * sizeof(char *));
  if (tab == NULL)
    return (NULL);
  while (wit->word)
    {
      tab[wit->i] = malloc((my_pstrlen(&str[wit->nb]) + 1) * sizeof(char **));
      if (tab[wit->i] == NULL)
	return (NULL);
      wit->nb = wit->nb + my_pstrlen(&str[wit->nb]);
      wit->word--;
      wit->i++;
    }
  tab[wit->i] = NULL;
  wit->lines = wit->i;
  wit->nb = 0;
  wit->i = 0;
  while (str[wit->nb])
    tab = place2(tab, wit, str);
  tab[wit->i][wit->j] = '\0';
  return (tab);
}

char     **my_word_in_tab(char *str)
{
  int   i;
  int   word;
  t_win struc;

  i = 0;
  word = 1;
  struc.j = 0;
  struc.i = 0;
  struc.nb = 0;
  while (str[i])
    {
      if (str[i] == ' ')
        {
          i++;
          word++;
          while (str[i] == ' ')
            i++;
        }
      else
        i++;
    }
  struc.word = word;
  return (my_word_in_tab2(str, &struc));
}
