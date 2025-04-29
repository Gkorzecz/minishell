/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkorzecz <gkorzec@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:37:08 by gkorzecz          #+#    #+#             */
/*   Updated: 2025/04/17 18:37:24 by gkorzecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*generate_prompt(void)
{
	char	*cwd;
	char	*prompt;
	char	*temp;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		cwd = ft_strdup("/");
	if (cwd == NULL)
		return (NULL);
	temp = ft_strjoin(cwd, "$ ");
	free(cwd);
	if (temp == NULL)
		return (NULL);
	prompt = ft_strdup(temp);
	free(temp);
	return (prompt);
}

static void	handle_interactive_input(t_cmd_set *p)
{
	char	*prompt;

	prompt = generate_prompt();
	if (prompt == NULL)
		ft_free_exit(p, 1, "Prompt error");
	p->input_text = readline(prompt);
	free(prompt);
}

static void	handle_non_interactive_input(t_cmd_set *p)
{
	char	*line;

	p->input_text = get_next_line(0);
	if (!p->input_text)
		ft_free_exit(p, p->status_code, NULL);
	line = p->input_text;
	p->input_text = ft_strtrim(p->input_text, "\n");
	if (p->input_text == NULL)
		ft_free_exit(p, 1, "exit");
	ft_free_all(line, NULL, NULL, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd_set	p;

	ft_init(&p, envp, argv, argc);
	while (1)
	{
		ft_set_signals(&p);
		if (isatty(0))
			handle_interactive_input(&p);
		else
			handle_non_interactive_input(&p);
		if (!ft_process_input(p.input_text, &p))
			break ;
	}
	ft_free_exit(&p, p.status_code, NULL);
}
