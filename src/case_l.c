/*
** case_l.c for case_l in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Nov 29 10:57:04 2014 anthony geiger
** Last update Sun Nov 30 21:51:34 2014 anthony geiger
*/

#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "struc.h"
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>

void		my_files_right(struct stat statinfo)
{
  if (S_ISREG(statinfo.st_mode))
    my_putchar('-');
  else if (S_ISLNK(statinfo.st_mode))
    my_putchar('l');
  else
    my_putchar('d');
  my_putchar(( statinfo.st_mode & S_IRUSR ) ? 'r' : '-');
  my_putchar(( statinfo.st_mode & S_IWUSR ) ? 'w' : '-');
  my_putchar(( statinfo.st_mode & S_IXUSR ) ? 'x' : '-');
  my_putchar(( statinfo.st_mode & S_IRGRP ) ? 'r' : '-');
  my_putchar(( statinfo.st_mode & S_IWGRP ) ? 'w' : '-');
  my_putchar(( statinfo.st_mode & S_IXGRP ) ? 'x' : '-');
  my_putchar(( statinfo.st_mode & S_IROTH ) ? 'r' : '-');
  my_putchar(( statinfo.st_mode & S_IWOTH ) ? 'w' : '-');
  my_putchar(( statinfo.st_mode & S_IXOTH ) ? 'x' : '-');
  my_putchar(' ');
}

void		my_aff_total()
{
  DIR		*rep;
  struct dirent	*ep;
  struct stat	statinfo;
  int		nb;
  int		stock;

  stock = 0;
  nb = 0;
  rep = opendir(".");
  if (rep == NULL)
    return ;
  while ((ep = readdir(rep)))
    {
      if (ep->d_name[0] == '.')
	continue;
      lstat(ep->d_name, &statinfo);
      nb = statinfo.st_blksize;
      stock = nb + stock;
    }
  my_putstr("total ");
  my_putnbr(stock / 1024);
  my_putchar('\n');
  closedir(rep);
}

void		aff_case_l(struct stat statinfo)
{
  struct passwd *pwd;
  struct group	*gr;
  char		*strtime;

  pwd = getpwuid(statinfo.st_uid);
  gr = getgrgid(statinfo.st_gid);
  my_putnbr((int)statinfo.st_nlink);
  my_putchar(' ');
  my_putstr(pwd->pw_name);
  my_putchar(' ');
  my_putstr(gr->gr_name);
  my_putchar(' ');
  my_espace_putnbr(statinfo.st_size);
  my_putchar(' ');
  strtime = ctime(&statinfo.st_mtime);
  my_putime(strtime);
}

void		stat_case_l(char **tab, int i)
{
  struct stat	statinfo;

  lstat(tab[i], &statinfo);
  if (lstat(tab[i], &statinfo) == -1)
    return ;
  my_files_right(statinfo);
  aff_case_l(statinfo);
  my_putstr(tab[i]);
  my_putchar('\n');
  i++;
}

void		case_l(t_boole *s)
{
  DIR		*rep;
  struct dirent	*ep;
  char		**tab;
  int		i;

  if (s->flagl == 0)
    return ;
  i = 0;
  my_aff_total();
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
      stat_case_l(tab, i);
      i++;
    }
  my_freetab(tab, i);
  closedir(rep);
}
