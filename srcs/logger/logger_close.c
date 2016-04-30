/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:42:34 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:43:26 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

int	logger_close(void)
{
	dprintf(g_log_fd, "\n\033[32m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m");
	dprintf(g_log_fd, "\033[32mEND OF THE APPLICATION INSTANCE\033[0m");
	dprintf(g_log_fd, "\033[32m <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m\n\n");
	return (close(g_log_fd));
}
