/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkorzecz <gkorzec@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:23:28 by gkorzecz          #+#    #+#             */
/*   Updated: 2025/04/22 19:24:08 by gkorzecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_exit(t_cmd_set *p, int exit_code, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (p && p->input_text != NULL)
		free(p->input_text);
	if (p && p->envp && *p->envp)
		ft_free_array(&p->envp);
	if (p && p->cmds)
		ft_lstclear(&p->cmds, ft_lst_free);
	rl_clear_history();
	exit(exit_code);
}
