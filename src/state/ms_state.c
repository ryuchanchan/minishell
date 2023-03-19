#include "ms_state.h"

t_ms_state *construct_ms_state(char **envp)
{
	t_ms_state	*state_p;

	state_p = malloc(sizeof(t_ms_state));
	if (!state_p)
		return (NULL);
	state_p->exit_status = 0;
	state_p->envp = sa_clone((const char **)envp);
	if (!state_p->envp)
	{
		free(state_p);
		return (NULL);
	}
	return (state_p);
}

void	destruct_ms_state(t_ms_state *state_p)
{
	sa_free(state_p->envp);
	state_p->exit_status = 0;
	free(state_p);
}
