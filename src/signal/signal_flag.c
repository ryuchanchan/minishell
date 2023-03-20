#include "signal_flag.h"

volatile t_signal_flag  g_flag;

void    reset_flag(void)
{
   g_flag = SF_NONE;
}

t_signal_flag   get_flag(void)
{
    return (g_flag);
}

void    set_flag(t_signal_flag new)
{
    if (new == SF_NONE)
    {
        g_flag = SF_NONE;
        return ;
    }
    if (g_flag != SF_NONE)
        return ;
    if (new == SF_SIGINT || new == SF_SIGQUIT)
        g_flag = new;
}

bool has_signal_interrupt(void)
{
    return (g_flag == SF_SIGINT || g_flag == SF_SIGQUIT);
}
