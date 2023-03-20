#ifndef MS_STATE_H
# define MS_STATE_H

# include "string_array.h"

typedef struct s_ms_state
{
    char    **envp;
    int     exit_status;
    int     tmpin;
    int     tmpout;
}   t_ms_state;

t_ms_state  *construct_ms_state(char **envp);
void        destruct_ms_state(t_ms_state *state_p);

#endif
