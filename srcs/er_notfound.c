/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_notfound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:24:38 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/17 15:31:29 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	er_notfound(char const *cmd)
{
	write(2, "minishell: invalide commande: ", 30);
	while (*cmd && *cmd != ' ')
		write(2, cmd++, 1);
	write(2, "\n", 1);
	bi_exit("0");
}
