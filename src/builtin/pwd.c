/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:42:35 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/22 22:42:57 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(char **args, char ***envp_p)
{
    char pwd[512];
    
    (void)envp_p;
    (void)args;
    if (getcwd(pwd, 512) == NULL)
    {
        perror("pwd");
        return (1);
    }
    ft_printf("%s\n", pwd);
    return (0);
}
