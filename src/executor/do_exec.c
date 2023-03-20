#include "do_exec.h"

static bool	is_builtin(char *arg_0)
{
	if (!arg_0)
		return (false);
	if (ft_strcmp(arg_0, "echo") == 0)
		return (true);
	if (ft_strcmp(arg_0, "cd") == 0)
		return (true);
	if (ft_strcmp(arg_0, "pwd") == 0)
		return (true);
	if (ft_strcmp(arg_0, "export") == 0)
		return (true);
	if (ft_strcmp(arg_0, "unset") == 0)
		return (true);
	if (ft_strcmp(arg_0, "env") == 0)
		return (true);
	if (ft_strcmp(arg_0, "exit") == 0)
		return (true);
	return (false);
}

static int do_exec_builtin(char **args, char ***envp_p)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args, envp_p));
	if (ft_strcmp(args[0], "cd") == 0)
		return builtin_cd(args, envp_p);
	if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env(args, envp_p));
	if (ft_strcmp(args[0], "pwd") == 0)
		return builtin_pwd(args, envp_p);
	/*
	if (ft_strcmp(args[0], "export") == 0)
		return builtin_export(args, envp_p);
	if (ft_strcmp(args[0], "unset") == 0)
		return builtin_unset(args, envp_p);
	if (ft_strcmp(args[0], "exit") == 0)
		return builtin_exit(args, envp_p);
	*/
	return (-1);
}

static void do_exec_fork(t_command *c_p, char **args, char ***envp_p)
{
	char *path_resolved;

	c_p->pid = fork();
	if (c_p->pid == 0)
	{
		if (is_builtin(args[0]))
			exit(do_exec_builtin(args, envp_p));
		path_resolved = resolve_filename(args[0], envp_p);
		if (!path_resolved)
			fatal_error("executor");
		execve(path_resolved, args, *envp_p);
		free(path_resolved);
		fatal_error(args[0]);
	}
	if (c_p->pid < 0)
		fatal_error("executor");
}

void	do_exec(t_command *c_p, char ***envp_p, bool is_piped)
{
	char **args;

	if (!c_p->args)
		return ;
	args = sa_from_list(c_p->args);
	if (!args)
		fatal_error("executor");
	if (!is_piped && is_builtin(args[0]))
		c_p->status = do_exec_builtin(args, envp_p);
	else
		do_exec_fork(c_p, args, envp_p);
	free(args);
}
