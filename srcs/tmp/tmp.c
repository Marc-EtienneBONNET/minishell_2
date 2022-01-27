/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 07:55:42 by mbonnet           #+#    #+#             */
/*   Updated: 2022/01/27 11:14:19 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_print_list_chene(t_cmd *cmd)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (!cmd)
		return (1);
	printf(ROUGE"\tDEBUT structure cmd, %d\n"BLANC,g_term.nb_maillon);
	while (g_term.nb_maillon > i)
	{
		my_print_maillon(cmd, i);
		i++;
		x = 0;
		cmd = cmd->next;
	}
	printf(ROUGE"\tFIN structure cmd\n\n"BLANC);
	return (1);
}

int	my_print_maillon(t_cmd *cmd, int i)
{
	int	x;

	x = 0;
	if (!cmd)
		return (1);
	dprintf(2,BLEU"\n\n\tMaillon N %d\n"BLANC, i);
	dprintf(2,BLEU"\tNombre maillon : %d\n"BLANC, g_term.nb_maillon);
	dprintf(2,VERT"cmd \t\t:\t(%s)\n"BLANC, cmd->cmd);
	dprintf(2,VIOLET"fichier_1 \t:\t(%s)\n"BLANC, cmd->fichier_1);
	dprintf(2,VIOLET"fichier_2 \t:\t(%s)\n"BLANC, cmd->fichier_2);
	dprintf(2,VIOLET"intra_red \t:\t(%s)\n"BLANC, cmd->intra_red);
	dprintf(2,VERT"path \t\t:\t(%s)\n"BLANC, cmd->path);
	dprintf(2,VERT"arg\t\t:\t"BLANC);
	if (cmd->arg)
		while (cmd->arg[x] != NULL)
			dprintf(2,VERT"(%s)\t"BLANC, cmd->arg[x++]);
	else
		dprintf(2,VERT"((null))"BLANC);
	dprintf(2,"\n");
	if (cmd->red != NULL)
		dprintf(2,VERT"redirection\t:\t%s\n"BLANC, cmd->red);
	else
		dprintf(2,VERT"redirection\t:\t((null))\n"BLANC);
	return (1);
}