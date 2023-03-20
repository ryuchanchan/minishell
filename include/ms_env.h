#ifndef MS_ENV_H
# define MS_ENV_H

# include "ms_error.h"
# include "key_value.h"

t_kv	*env_find(const char **envp, const char *key);
//void	env_add(char ***envp_p, t_kv *kv_p);
//void	env_delete(char ***envp_p, char *key);

#endif
