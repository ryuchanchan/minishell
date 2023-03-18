#ifndef DO_EXEC_H
# define DO_EXEC_H

# include "command.h"
# include "string_array.h"
# include "ms_error.h"

void	do_exec(t_command *c_p, char ***envp_p, bool is_piped);

#endif
