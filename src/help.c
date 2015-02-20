/*
** help.c for help in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Nov 29 14:19:09 2014 anthony geiger
** Last update Sun Nov 30 22:06:59 2014 anthony geiger
*/

#include <stdlib.h>
#include "struc.h"

int			my_help(void)
{
  my_putstr("Usage : ls [OPTION]...\n");
  my_putstr("Only : \n");
  my_putstr("-t : Sort by time of the last modification.\n");
  my_putstr("-l : Display more information than ls in column.\n");
  my_putstr("-d : Diplay the current directory.\n");
  my_putstr("-r : Reverse.\n");
  my_putstr("Can be use for the moment.\n");
  my_putstr("More flag will coming soon please wait.\n");
  my_putstr("If you don't want to wait CODE IT YOURSELF !\n");
  my_putstr("This is a beta please if you see a bug report it\n");
  my_putstr("Thank for use your ls.\n");
  exit (0);
  return (1);
}
