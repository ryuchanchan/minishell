#ifndef COMMAND_H
# define COMMAND_H

# include "redirection.h"

typedef struct s_command {
	t_list			*args;
	t_list			*redirections;
	pid_t			pid;
	int				status;
} t_command;

t_command	*construct_command(void);
void		destruct_command(void *content);

#endif
