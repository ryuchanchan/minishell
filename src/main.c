#include "minishell.h"

/* begin: for debug  */
__attribute__((destructor))
void	destructor(void)
{
	int	status;

	status = system("leaks minishell &> result_leaks");
	if (status)
	{
		write(2, "Memory leak is found!\n", 8);
		system("cat result_leaks >/dev/stderr");
		exit(1);
	}
}

static void print_tokens(t_list *t)
{
	t_token	*t_p;
	t_list	*tokens;

	tokens = t;
	printf("===== print_tokens: begin =====\n");
	while (tokens != NULL)
	{
		t_p = tokens->content;
		printf("==========\n");
		printf("str: %s\n", t_p->str);
		printf("type: %d\n", t_p->type);
		printf("==========\n");
		tokens = tokens->next;
	}
	printf("===== print_tokens: end =====\n");
}

static void print_args(t_list *a)
{
	char	*a_p;
	size_t	i;
	t_list	*args;

	args = a;
	printf("	===== print_args: begin =====\n");
	i = 0;
	while (args != NULL)
	{
		a_p = args->content;
		printf("	==========\n");
		printf("	arg[%zu]:	%s\n", i++, a_p);
		printf("	==========\n");
		args = args->next;
	}
	printf("	===== print_args: end =====\n");
}

static void print_redirections(t_list *r)
{
	t_redirection	*r_p;
	t_list	*redirections;

	redirections = r;
	printf("	===== print_redirections: begin =====\n");
	while (redirections != NULL)
	{
		r_p = redirections->content;
		printf("	==========\n");
		printf("	type:		%d\n", r_p->type);
		printf("	filename:	%s\n", r_p->filename);
		printf("	==========\n");
		redirections = redirections->next;
	}
	printf("	===== print_redirections: end =====\n");
}

static void print_commands(t_list *c)
{
	t_command	*c_p;
	t_list *commands;

	commands = c;
	printf("===== print_commadns: begin =====\n");
	while (commands != NULL)
	{
		c_p = commands->content;
		printf("==========\n");
		printf("pid:	%d\n", c_p->pid);
		printf("status:	%d\n", c_p->status);
		printf("type:	%d\n", c_p->type);
		print_args(c_p->args);
		print_redirections(c_p->redirections);
		printf("==========\n");
		commands = commands->next;
	}
	printf("===== print_commands: end =====\n");
}
/* end: for debug */

static void	minishell(char *line)
{
	t_list	*tokens;
	t_list	*commands;
	// t_list	*head;
	//  t_node	*node;
	//  t_list	*command;
	//  t_pid	pid;
	//  int		fdin;
	//  int		fdout;
	//  int		pipe_fd[2];
	//  int tmpin = dup(0);
	//  int tmpout = dup(1);
	//  char **arr;
	//  extern char	**environ;
	//  int status;

	// ft_printf("%s\n", line);
	tokens = lexer(line);
	print_tokens(tokens);
	/*
	 *Todo: tokens validation check & expansion
	 *The following are check items.
	 *	1. The first token must not be a PIPE.
	 *	2. PIPE must not be consecutive.
	 *	3. REDIRECTION must be followed by WORD.
	 *	4. The last token must not be PIPE, REDIRECTION.
	 *
	 *If the check items are not satisfied, an error message is output and free token and return.
	 *Example message
	 *	minishell: syntax error near unexpected token '>'
	 */
	/* parser */
	commands = parser(tokens);
	print_commands(commands);

	ft_lstclear(&tokens, destruct_token);
	ft_lstclear(&commands, destruct_command);

	/* executor */
	/*
	node = parser(head);
	fdin = dup(tmpin);
	while (node != NULL)
	{
		command = node->commands;
		redirect_input(node->filenames, &fdin);
		dup2(fdin, 0);
		close(fdin);
		if (node->next != NULL)
		{
			pipe(pipe_fd);
			fdout = pipe_fd[1];
			fdin = pipe_fd[0];
		}
		else
			fdout = dup(tmpout);
		redirect_output(node->filenames, &fdout);
		// print_filenames(node->filenames, &fdout);
		dup2(fdout, 1);
		close(fdout);
		arr = list_to_array(command);
		pid.pids = fork();
		if (pid.pids == 0)
		{
			execve(arr[0], arr, environ);
			perror(arr[0]);
			exit(1);
		}
		free(arr);
		node = node->next;
	}
	dup2(tmpin,0);
	dup2(tmpout,1);
	close(tmpin);
	close(tmpout);
	waitpid(pid.pids, &status, 0);
	*/
}

static void update_line(char **line_p)
{
	free(*line_p);
	*line_p = readline(PREFIX_SHELL);
}

int	main(int argc, char **argv, char **envp)
{
	char *line;

	(void)argc;
	(void)argv;
	(void)envp;
	set_signal();
	line = readline(PREFIX_SHELL);
	while (line)
	{
		if (ft_strlen(line) <= 0)
		{
			update_line(&line);
			continue;
		}
		minishell(line);
		add_history(line);
		update_line(&line);
	}
	ft_printf("exit\n");
	rl_clear_history();
	return (0);
}
