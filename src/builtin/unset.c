#include "ms_builtin.h"

int	builtin_unset(char **args, char ***envp_p)
{
    size_t  i;
    t_kv    *kv_p;

    i = 1;
    while (args[i])
    {
        kv_p = env_get_value(*envp_p, args[i]);
        i++;
        if (!kv_p)
            continue ;
        env_delete(envp_p, kv_p->key);
        kv_free(&kv_p);
    }
    return (0);
}
