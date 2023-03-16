#include "minishell.h"

/* begin: for debug  */
/*
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
*/
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
/*
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
*/
/* end: for debug */

static bool	is_line_empty(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

static void	minishell(char *line, char **envp)
{
	t_list	*tokens;
	t_list	*commands;
	bool	is_quote_not_closed;

	if (is_line_empty(line))
		return ;
	is_quote_not_closed = false;
	tokens = lexer(line, &is_quote_not_closed);
	if (validate_and_expand(tokens, is_quote_not_closed))
	{
		ft_lstclear(&tokens, destruct_token);
		return ;
	}
	print_tokens(tokens);
	commands = parser(tokens);
	//print_commands(commands);
	ft_lstclear(&tokens, destruct_token);
	executor(commands, &envp);
	ft_lstclear(&commands, destruct_command);
}

static void	update_line(char **line_p)
{
	free(*line_p);
	*line_p = readline(PREFIX_SHELL);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	set_signal();
	line = readline(PREFIX_SHELL);
	while (line)
	{
		if (ft_strlen(line) <= 0)
		{
			update_line(&line);
			continue ;
		}
		minishell(line, envp);
		add_history(line);
		update_line(&line);
	}
	rl_clear_history();
	ft_printf("exit\n");
	return (0);
}
