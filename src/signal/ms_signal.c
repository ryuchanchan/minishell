#include "ms_signal.h"

static void	signal_interrupt_handler(int sig){
	if (sig != SIGINT)
		return;
	if (get_flag() == SF_NONE)
		set_flag(SF_SIGINT);
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
