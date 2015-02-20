/*
** my_ls.c for my_ls in /home/geiger_a/rendu/MY_LS
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 23 15:08:17 2014 anthony geiger
** Last update Sun Nov 30 21:52:13 2014 anthony geiger
*/

#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "struc.h"
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>

void		simple_ls(t_boole *s, int i, char *argv)
{
  DIR		*rep;
  struct dirent	*ep;
  char		**tab;

  if (s->flagl == 1 || s->fakeflag == 1)
    return ;
  aff_case_d(argv, s);
  tab = my_stock_name(".");
  tab = my_put_in_tab(tab, ".");
  if (s->flagt == 0)
    my_put_alpha_tab(tab, s);
  else
    my_time_ordre(tab, my_time_in_tab("."), s);
  rep = opendir(".");
  if (rep == NULL)
    return ;
  while ((ep = readdir(rep)))
    {
      if (ep->d_name[0] == '.')
	continue ;
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  my_freetab(tab, i);
}

void		boole_init(t_boole *s)
{
  s->flagl = 0;
  s->flagr = 0;
  s->flagd = 0;
  s->flagt = 0;
  s->flag_r = 0;
  s->fakeflag = 0;
  s->flagh = 0;
}

void			flag_gestion(char **argv, t_boole *s, int i)
{
  int			y;

  y = 0;
  if (argv[i][y] == '-')
    {
      while (argv[i][y])
	{
	  y++;
	  (argv[i][y] == 'l' ? (s->flagl = 1) : (s->fakeflag = 0));
	  (argv[i][y] == 'r' ? (s->flagr = 1) : (s->fakeflag = 0));
	  (argv[i][y] == 'd' ? (s->flagd = 1) : (s->fakeflag = 0));
	  (argv[i][y] == 't' ? (s->flagt = 1) : (s->fakeflag = 0));
	  ((argv[i][y] == '-' && argv[i][y + 1] == 'h') ?
	   (my_help() && (s->flagh = 0)) : (s->fakeflag = 1));
	}
    }
  ((s->flagt == 0 && s->flagd == 0 && s->flagr == 0 && s->flagl == 0
    && s->flagh == 0) ?
   (s->fakeflag = 1) : (s->fakeflag = 0));
  if (s->fakeflag == 1 && argv[1][0] == '-')
    my_putstr("Try 'ls --h' for more information.\n");
}

void			my_ls(char **argv, int argc)
{
  int			i;
  t_boole		s;

  i = 1;
  boole_init(&s);
  while (argv[i])
    {
      flag_gestion(argv, &s, i);
      i++;
    }
  if (argc == 1)
    simple_ls(&s, 0, argv[i - 1]);
  else
    {
      case_l(&s);
      simple_ls(&s, 0, argv[i - 1]);
    }
}

int		main(int argc, char **argv)
{
  my_ls(argv, argc);
  return (0);
}
