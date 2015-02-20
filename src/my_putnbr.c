/*
** my_putnbr.c for putnbr in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:36:37 2014 anthony geiger
** Last update Sun Nov 30 14:36:47 2014 anthony geiger
*/

#include "struc.h"

void     my_putnbr(int nb)
{
  int   div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  while (nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      if (div == 1)
        my_putchar(nb % 10 + 48);
      else
        my_putchar(nb / div + 48);
      nb = nb % div;
      div = div / 10;
    }
}

int	my_countnb(int nb)
{
  int   div;
  int	i;

  i = 0;
  div = 1;
  if (nb < 0)
    nb = - nb;
  while (nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      nb = nb % div;
      div = div / 10;
      i++;
    }
  return (i);
}

void	my_espace_putnbr(int nb)
{
  int	i;
  int	div;

  i = my_countnb(nb);
  while (i != 5)
    {
      my_putchar(' ');
      i++;
    }
  div = 1;
  if (nb < 0)
    nb = - nb;
  while (nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      if (div == 1)
        my_putchar(nb % 10 + 48);
      else
        my_putchar(nb / div + 48);
      nb = nb % div;
      div = div / 10;
   }
}
