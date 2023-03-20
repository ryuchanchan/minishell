#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/wait.h>

# include "command.h"
# include "ms_error.h"
# include "ms_state.h"
# include "signal_flag.h"
# include "do_redirect.h"
# include "do_exec.h"

int	executor(t_list *commands, t_ms_state *state_p);

#endif
