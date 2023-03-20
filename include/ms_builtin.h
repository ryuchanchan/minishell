#ifndef MS_BUILTIN_H
# define MS_BUILTIN_H

# include "../libft/include/libft.h"
# include "key_value.h"
# include "string_array.h"
# include <stdio.h>


int	builtin_echo(char **args, char ***envp_p);
int	builtin_env(char **args, char ***envp_p);
int	builtin_cd(char **args, char ***envp_p);
int	builtin_pwd(char **args, char ***envp_p);
int	builtin_export(char **args, char ***envp_p);

t_kv *kv_construct(const char *str);
void kv_free(t_kv **key_value_pp);
char *kv_join(const t_kv *key_value_p);
void exit_error(char *msg);
t_kv *env_get_value(char **envp, char *key);
ssize_t env_get_index(char **envp, char *key);
/*
int	builtin_unset(char **args, char ***envp_p);
int	builtin_exit(char **args, char ***envp_p);
*/

#endif
