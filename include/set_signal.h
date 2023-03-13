#ifndef SET_SIGNAL_H
# define SET_SIGNAL_H

# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/include/libft.h"

static volatile sig_atomic_t is_interrupted = 0;
void set_signal(void);

#endif
