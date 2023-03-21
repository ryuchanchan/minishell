#include "minishell.h"

int	builtin_pwd(char **args, char ***envp_p)
{
    (void)envp_p;
    (void)args;
    char pwd[512];
    getcwd(pwd, 512);
    printf("%s\n", pwd);
    return (0);
}