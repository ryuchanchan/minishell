#ifndef EXECUTOR_H
# define EXECUTOR

# include <stdio.h>
# include <fcntl.h> 

# include "command.h"

/*

typedef struct s_pid {
    int pids;
} t_pid;
*/

char    **list_to_array(t_list *list);
void    redirect_output(t_list *filenames, int *fdout);
void    redirect_input(t_list *filenames, int *fdin);
int     do_heredoc(char *str);

#endif
