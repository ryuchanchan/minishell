/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:16:01 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:16:03 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_VALUE_H
# define KEY_VALUE_H

# define KV_SEP "="

# include "string_array.h"

typedef struct e_kv
{
	char	*key;
	char	*value;
}	t_kv;

t_kv	*construct_kv(const char *str);
void	destruct_kv(t_kv **key_value_pp);
char	*kv_to_string(const t_kv *key_value_p);

#endif
