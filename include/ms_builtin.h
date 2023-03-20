/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:14:25 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:14:39 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTIN_H
# define MS_BUILTIN_H

# include "../libft/include/libft.h"

int	builtin_echo(char **args, char ***envp_p);

/*
int	builtin_cd(char **args, char ***envp_p);
int	builtin_pwd(char **args, char ***envp_p);
int	builtin_export(char **args, char ***envp_p);
int	builtin_unset(char **args, char ***envp_p);
int	builtin_env(char **args, char ***envp_p);
int	builtin_exit(char **args, char ***envp_p);
*/

#endif
