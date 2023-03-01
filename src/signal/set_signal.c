#include "set_signal.h"

static void	signal_interrupt_handler(int sig){
	if (sig != SIGINT)
		return;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	signal_quit_handler(int sig){
	if (sig != SIGQUIT)
		return;
	rl_redisplay();
}

void set_signal(void)
{
	signal(SIGINT, signal_interrupt_handler);
	signal(SIGQUIT, signal_quit_handler);
}
