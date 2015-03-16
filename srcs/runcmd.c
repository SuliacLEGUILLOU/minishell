/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:35:49 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/16 15:52:28 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name:	runcmd
 *	@brief:	This function run the cmd into fork after getting the rigth path
 *
 *	Note about "..." management :
 *		I could manage this type of argument by spliting the " caracter
 *		and then subsplit odd number with ' '
 */
static void	st_free(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd && cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

static char	**st_initopt(char const *cmd, char *dirpath)
{
	char	**new;
	char	*path;

	new = ft_strsplit(cmd, ' ');
	if (testpath(*new) >= 8)
	{
		free(dirpath);
		return (new);
	}
	path = parse_path(dirpath, cmd);
	free(dirpath);
	if (path)
	{
		free(*new);
		*new = path;
	}
	else
	{
		st_free(new);
		new = NULL;
	}
	return (new);
}

// Thing to add here...
// alias come here
// ~ = Home
// Better do a function...
void		runcmd(char const *cmd, char **env)
{
	char	**opt;
	pid_t	father;

	opt = st_initopt(cmd, getenv_cpy(env, "PATH"));
	father = fork();
	if (!father)
	{
		if (opt)
			execve(*opt, opt, env);
		er_notfound(cmd);
	}
	else
	{
		wait(NULL);
		st_free(opt);
	}
}
