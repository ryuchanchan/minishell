/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:37:48 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:38:54 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_value.h"

static char	*extract_key(const char *str, const char *position_sep)
{
	size_t	n;

	if (!position_sep)
		return (ft_strdup(str));
	if (position_sep == str)
		return (ft_strdup(""));
	n = (position_sep - str) / sizeof(char);
	return (ft_strndup(str, n));
}

static char	*extract_value(const char *position_sep)
{
	if (!position_sep)
		return (ft_strdup(""));
	return (ft_strdup((position_sep + 1)));
}

t_kv	*construct_kv(const char *str)
{
	char	*position_sep;
	t_kv	*kv;

	if (!str)
		return (NULL);
	position_sep = ft_strchr(str, *KV_SEP);
	kv = malloc(sizeof(t_kv) * 1);
	if (!kv)
		return (NULL);
	kv->key = extract_key(str, position_sep);
	kv->value = extract_value(position_sep);
	if (!(kv->key) || !(kv->value))
	{
		free(kv->key);
		free(kv->value);
		free(kv);
		return (NULL);
	}
	return (kv);
}

void	destruct_kv(t_kv **key_value_pp)
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

char	*kv_to_string(const t_kv *key_value_p)
{
	char	*tmp;
	char	*joined;

	if (!key_value_p)
		return (NULL);
	tmp = ft_strjoin(key_value_p->key, KV_SEP);
	if (!tmp)
		return (NULL);
	joined = ft_strjoin(tmp, key_value_p->value);
	free(tmp);
	return (joined);
}
