#ifndef SIGNAL_FLAG_H
# define SIGNAL_FLAG_H

# include <stdbool.h>

typedef enum e_signal_flag
{
    SF_NONE,
    SF_SIGINT,
    SF_SIGQUIT
}   t_signal_flag;

void            reset_flag(void);
t_signal_flag   get_flag(void);
void            set_flag(t_signal_flag new_flag);
bool            has_signal_interrupt(void);

#endif
