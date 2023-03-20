#include "ms_builtin.h"

ssize_t env_get_index(char **envp, char *key)
{
    size_t  i;
    t_kv    *kv_p;

    if (!envp || !key)
        return (-1);
    i = 0;
    while (envp[i])
    {
        kv_p = kv_construct(envp[i]);
        if (ft_strcmp(kv_p->key, key) == 0)
        {
            kv_free(&kv_p);
            return (i);
        }
        kv_free(&kv_p);
        i++;
    }
    return (-1);
}

t_kv *env_get_value(char **envp, char *key)
{
    ssize_t index;
    t_kv    *kv_p;

    index = env_get_index(envp, key);
    if (index < 0)
        return (NULL);
    kv_p = kv_construct(envp[index]);
    return (kv_p);
}

void env_delete(char ***envp_p, char *key)
{
    ssize_t i;
    ssize_t index;
    ssize_t size;
    char    **new;

    index = env_get_index(*envp_p, key);
    if (index < 0)
        return ;
    size = sa_size((const char **)*envp_p);
    new = malloc(sizeof(char *) * (size - 1));
    if (!new)
        exit_error(NULL);
    free((*envp_p)[index]);
    i = 0;
    while ((*envp_p)[i])
    {
        if (i < index)
            new[i] = (*envp_p)[i];
        else
            new[i] = (*envp_p)[i + 1]; 
        i++;       
    }
    free(*envp_p);
    *envp_p = new;
}

// void print_env(char **envp)
// {
//     int i;

//     i = 0; 
//     // printf("envp = [\n");
//     while (envp[i])
//     {
//         // printf("----------------\n");
//         printf("%s\n", envp[i]);
//         i++;
//     }
//     // printf("]\n");
// }

int	builtin_env(char **args, char ***envp_p)
{
    (void)args;
    sa_print((const char **)*envp_p, 0);
    // exit(0);
    return (0);
}