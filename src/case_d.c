/*
** case_d.c for case_d in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:26:49 2014 anthony geiger
** Last update Sun Nov 30 21:58:18 2014 anthony geiger
*/

#include "struc.h"
#include <stdlib.h>

void		aff_case_d(char *argv, t_boole *s)
{
  if (s->flagd == 1)
    {
      if (argv[0] == '-' && argv[1] == 'd')
	{
	  my_putchar('.');
	  my_putchar('\n');
	  exit (1);
	}
      my_putstr(argv);
      my_putchar('\n');
      exit (0);
    }
}
