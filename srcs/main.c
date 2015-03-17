/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:47:56 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/17 14:27:01 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	**loc_env;
	int		i;

	i = 1;
	loc_env = env_cp(env);
	if (ac == 1)
	{
		print_prompt(env);
		while (interpreter(loc_env, 0) > 0)
		{
			loc_env = env_refresh(loc_env);
			print_prompt(loc_env);
		}
	}
	else
	{
		while (i < ac)
			loc_env = script(av[i++], loc_env);
	}
	return (0);
}
