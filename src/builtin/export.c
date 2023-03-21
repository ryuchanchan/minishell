#include "minishell.h"

void env_add(char ***envp_p, t_kv *kv_p)
{
    ssize_t index;
    size_t  size;
    size_t  i;
    char    *joined;
    char    **new;

    joined = kv_join(kv_p);
    index = env_get_index(*envp_p, kv_p->key);
    if (index >= 0)
    {
        free((*envp_p)[index]);
        (*envp_p)[index] = joined;
        return ;
    }
    size = sa_size((const char **)(*envp_p));
    new = malloc(sizeof(char *) * (size + 1));
    i = 0;
    while ((*envp_p)[i])
    {
        new[i] = (*envp_p)[i];
        i++;
    }
    free(*envp_p);
    new[size - 1] = joined;
    new[size] = NULL;
    *envp_p = new;
}

int	builtin_export(char **args, char ***envp_p)
{
    size_t i;
    t_kv *kv_p;
    
    i = 1;
    while (args[i])
    {
        kv_p = kv_construct(args[i]);
        if (!kv_p)
            kv_p = env_get_value(*envp_p, args[i]);
        i++;
        if (!kv_p)
            continue;
        env_add(envp_p, kv_p);
        kv_free(&kv_p);
    }
    return (0);
}