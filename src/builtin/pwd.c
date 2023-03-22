#include "minishell.h"

int	builtin_pwd(char **args, char ***envp_p)
{
    char pwd[512];
    
    (void)envp_p;
    (void)args;
    if (getcwd(pwd, 512) == NULL)
    {
        perror("pwd");
        exit(1);
    }
    printf("%s\n", pwd);
    return (0);
}
