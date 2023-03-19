#ifndef MS_BUILTIN_H
# define MS_BUILTIN_H

# include "../libft/include/libft.h"

int	echo(char **args, char ***envp_p);
int	cd(char **args, char ***envp_p);
int	pwd(char **args, char ***envp_p);
int	export(char **args, char ***envp_p);
int	unset(char **args, char ***envp_p);
int	env(char **args, char ***envp_p);
int	exit(char **args, char ***envp_p);

#endif
