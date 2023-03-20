#include "minishell.h"


static char *extract_key(const char *str)
{
    char *key;
    char **splitted;

    if (str[0] == *KV_SEP)
    {
        key = ft_strdup("");
        if (!key)
            exit_error(NULL);
        return (key);
    }
    splitted = ft_split(str, *KV_SEP);
    if (!splitted)
        exit_error(NULL);
    key = ft_strdup(splitted[0]);
    if (!key)
        exit_error(NULL);
    sa_free(splitted);
    return (key);
}

static char *extract_value(const char *position_sep)
{
    char *value;

    value = ft_strdup((position_sep + 1));
    if (!value)
        exit_error(NULL);
    return (value);
}

t_kv *kv_construct(const char *str)
{
    char *position_sep;
    t_kv *kv;

    if (!str)
        return (NULL);
    position_sep = ft_strchr(str, *KV_SEP);
    if (!position_sep)
        return (NULL);
    kv = malloc(sizeof(t_kv) * 1);
    if (!kv)
        exit_error(NULL);
    kv->key = extract_key(str);
    kv->value = extract_value(position_sep);
    return (kv);
}

char *kv_join(const t_kv *key_value_p)
{
    char *tmp;
    char *joined;

    if (!key_value_p)
        return (NULL);
    tmp = ft_strjoin(key_value_p->key, KV_SEP);
    if (!tmp)
        exit_error(NULL);
    joined = ft_strjoin(tmp, key_value_p->value);
    free(tmp);
    if (!joined)
        exit_error(NULL);
    return (joined);
}

void kv_free(t_kv **key_value_pp)
{
    if (!*key_value_pp)
        return ;
    free((*key_value_pp)->key);
    (*key_value_pp)->key = NULL;
    free((*key_value_pp)->value);
    (*key_value_pp)->value = NULL;
    free(*key_value_pp);
    *key_value_pp = NULL;
}