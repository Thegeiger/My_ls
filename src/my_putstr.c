/*
** my_putstr.c for my_putstr in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:33:53 2014 anthony geiger
** Last update Sun Nov 30 14:33:57 2014 anthony geiger
*/

#include "struc.h"

void     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void    my_putime(char *str)
{
  int   i;

  i = 4;
  while (str[i + 9])
    {
      my_putchar(str[i]);
      i++;
    }
  my_putchar(' ');
}
