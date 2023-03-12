#ifndef COMMAND_H
# define COMMAND_H

# include "redirection.h"

typedef enum e_command_type {
    C_PIPE,
    C_COMMAND,
	C_BUILDIN
} t_command_type;

typedef struct s_command {
	t_command_type	type;
	t_list			*args;
	t_list			*redirections;
	pid_t			pid;
	int				status;
} t_command;

t_command	*construct_command(void);
void		destruct_command(void *content);

#endif
