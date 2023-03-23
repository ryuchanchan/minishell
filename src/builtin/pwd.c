/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:42:35 by rykawamu          #+#    #+#             */
/*   Updated: 2023/03/23 01:42:57 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

int builtin_pwd(char **args, char ***envp_p)
{
    char buf[PATH_MAX];
    
    (void)envp_p;
    (void)args;
    if (getcwd(buf, PATH_MAX) == NULL)
    {
        perror("pwd");
        return (1);
    }
    ft_printf("%s\n", buf);
    return (0);
}
