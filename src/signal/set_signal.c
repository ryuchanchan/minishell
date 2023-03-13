#include "set_signal.h"

static void	signal_interrupt_handler(int sig)
{
	if (sig != SIGINT)
		return;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void signal_heredoc_handler(int sig)
{
	if (sig != SIGINT)
		return;
	is_interrupted = 1;
	signal(SIGINT, signal_interrupt_handler);
	rl_on_new_line();
}

static void	signal_quit_handler(int sig)
{
	if (sig != SIGQUIT)
		return;
	rl_redisplay();
}

void set_signal(void)
{
	signal(SIGINT, signal_interrupt_handler);
	signal(SIGINT, signal_heredoc_handler);
	signal(SIGQUIT, signal_quit_handler);
}