#include "do_exec.h"

void	do_exec(t_command *c_p, char ***envp_p, bool is_piped)
{
	char **args;

	if (!c_p->args)
		return ;
	args = sa_from_list(c_p->args);
	if (!args)
		fatal_error("executor");
	/*  */
	(void)is_piped;
	c_p->pid = fork();
	if (c_p->pid == 0)
	{
		execve(args[0], args, *envp_p);
		fatal_error(args[0]);
	}
	if (c_p->pid < 0)
		fatal_error("executor");
	/*  */
	free(args);
}
