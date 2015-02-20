/*
** struc.h for struc in /home/geiger_a/rendu/MY_LS
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 23 15:20:11 2014 anthony geiger
** Last update Sun Nov 30 21:53:59 2014 anthony geiger
*/

#ifndef STRUC_H_
# define STRUC_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef	struct	s_boole
{
  int		flagl;
  int		flagr;
  int		flagd;
  int		flag_r;
  int		flagt;
  int		fakeflag;
  int		flagh;
}		t_boole;

typedef struct          s_struc
{
  char                  c;
  int                   (*ptr_tab)(char *argv, int argc, t_boole *s);
}                       t_struc;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putnbr(int nb);
void		my_ls(char **argv, int argc);
char		**my_put_alpha_tab(char **tab, t_boole *s);
int		my_strlen(char *str);
void		my_affiletype(unsigned char c);
void		my_espace_putnbr(int nb);
char		**my_word_in_tab(char *str);
void		my_putime(char *str);
void		my_freetab(char **tab, int lines);
void		case_l(t_boole *s);
char		**my_time_ordre(char **tab, int *nbtab, t_boole *s);
int		my_strlen(char *str);
int		how_many_files(char *argv);
char		**my_stock_name(char *argv);
char		*my_strdup(char *str);
char		**my_put_in_tab(char **tab, char *argv);
void		my_files_right(struct stat statinfo);
void		my_aff_total();
void		aff_case_l(struct stat statinfo);
void		stat_case_l(char **tab, int i);
int		*my_time_in_tab(char *argv);
int		my_help(void);
void		aff_case_d(char *argv, t_boole *s);

#endif /* !STRUC_H_ */
