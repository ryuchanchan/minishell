# include "minishell.h"

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

static void	run(char *line, t_ms_state *state_p)
{
	t_list	*tokens;
	t_list	*commands;
	bool	is_open_quote;

	if (is_line_empty(line))
		return ;
	is_open_quote = false;
	tokens = lexer(line, &is_open_quote);
	if (check_and_expand(tokens, state_p, is_open_quote))
	{
		ft_lstclear(&tokens, destruct_token);
		state_p->exit_status = STAT_SYNTAX_ERR;
		return ;
	}
	commands = parser(tokens);
	ft_lstclear(&tokens, destruct_token);
	state_p->exit_status = executor(commands, state_p);
	ft_lstclear(&commands, destruct_command);
}

static void	after_readline(t_ms_state *state_p, char *line)
{
	if (get_flag() == SF_SIGINT)
	{
		rl_on_new_line();
		free(line);
		state_p->exit_status = 1;
		return ;
	}
	if (line && ft_strlen(line) > 0)
	{
		reset_flag();
		run(line, state_p);
		if (has_signal_interrupt() && state_p->exit_status != 0)
		{
			ft_printf("\n");
			rl_on_new_line();
		}
		add_history(line);
	}
}

void	minishell(t_ms_state *state_p)
{
	char	*line;

	line = "";
	while (line)
	{
		reset_flag();
		line = readline(PREFIX_SHELL);
		after_readline(state_p, line);
		free(line);
	}
}
