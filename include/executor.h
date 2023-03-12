#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <stdio.h>
# include <fcntl.h> 

# include "command.h"

char    **list_to_array(t_list *list);
void    redirect_output(t_list *filenames, int *fdout);
void    redirect_input(t_list *filenames, int *fdin, int tmpin, int tmpout);
int     do_heredoc(char *str, int tmpin, int tmpout);
void    executor(t_list *commands, char ***envp_p);

#endif
