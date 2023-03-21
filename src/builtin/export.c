/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:16:52 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 16:36:52 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static bool is_invalid_name(char *str)
{
	size_t	i;

	if (!str || str[0] == '\0' || str[0] == '=')
		return (true);
	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (i == 0 && ft_isdigit(str[0]))
			return (true);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (true);
		i++;
	}
	return (false);
}

static bool	is_invalid_argument(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (is_invalid_name(args[i]))
		{
			ft_putstr_fd("export: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (true);
		}
		i++;
	}
	return (false);
}

static int	print_setted(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
		ft_printf("declare -x %s\n", envp[i++]);
	return (0);
}

int	builtin_export(char **args, char ***envp_p)
{
	if (!args[1])
		return (print_setted(*envp_p));
	if (is_invalid_argument(args))
		return (1);
	// 追加処理
	// &args[1] および envpの環境変数が同じものがないか見て
	// &arg[i]に=が含まれることを確認
	// &arg[i]の$name取得
	// $nameが&arg[i+1]以降のnameと重複がないことを確認
	// $nameとenvpないの変数のnameと重複があるか確認
	// 	ある-> あった要素を更新
	//	ない-> 要素を追加
	return (0);
}
