#ifndef RESOLVE_FILENAME_H
# define RESOLVE_FILENAME_H

# include "ms_error.h"
# include "ms_env.h"
# include "file_stat.h"
# include "string_array.h"
# include "key_value.h"

char	*resolve_filename(char *arg_0, char ***envp_p);

#endif
