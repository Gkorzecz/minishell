/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkorzecz <gkorzec@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:32:55 by gkorzecz          #+#    #+#             */
/*   Updated: 2025/04/17 18:32:59 by gkorzecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	error_unclosed_quotes(void)
{
	ft_printf_fd(2, "mini: ");
	ft_printf_fd(2, "unexpected EOF while looking for matching `'\"\n");
}

/* shows error message on stderr, sets the p->status_code to err_code */
void	*put_err(char *err_msg, char *cmd, int err_code, t_cmd_set *p)
{
	if (p && err_code >= 0)
		p->status_code = err_code;
	g_exit_status = err_code;
	if (err_msg)
	{
		if (!ft_strncmp(err_msg, "Unclosed_Quote", 14))
			error_unclosed_quotes();
		else if (err_msg && !ft_strncmp(err_msg, "NoFile_NoDir", 12))
			ft_printf_fd(2, "mini: %s: No such file or directory\n", cmd);
		else if (!ft_strncmp(err_msg, "Perm_Denied", 11))
			ft_printf_fd(2, "mini: %s: Permission denied\n", cmd);
		else if (!ft_strncmp(err_msg, "No_Cmd", 6) && p->status_code != 2)
			ft_printf_fd(2, "mini: %s: command not found\n", cmd);
		else if (!ft_strncmp(err_msg, "DupForkPipe_Failed", 18))
			ft_printf_fd(2, "mini: %s: dup2,fork or pipe failed\n", cmd);
		else if (!ft_strncmp(err_msg, "Empty_Pipe", 10) && p->status_code != 2)
			ft_printf_fd(2, "mini: %s: invalid null command\n", cmd);
		else if (!ft_strncmp(err_msg, "Is_Directory", 12))
			ft_printf_fd(2, "mini: %s: Is a directory\n", cmd);
	}
	else if (cmd && cmd[0] != '\0')
		ft_printf_fd(2, "mini: %s\n", cmd);
	return (NULL);
}
