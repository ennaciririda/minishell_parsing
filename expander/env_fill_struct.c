/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:01:18 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/04 11:48:39 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*env_fill_struct(char **env)
{
	int		i;
	int		j;
	t_env	*envir;

	envir = NULL;
	i = 0;
	j = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		add_back_env(&envir, ft_lstnew_env(ft_strjoin(ft_strdup("$"),
					ft_substr(env[i], 0, j)), ft_strdup(env[i] + j + 1)));
		i++;
	}
	return (envir);
}
