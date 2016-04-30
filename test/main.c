/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:43:06 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:47:50 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

int	main(void)
{
	if (logger_init(D_TRACE, "out.log") != 0)
		printf("failed to open the logger\n");
	log_fatal("%s\n", "lol");
	log_error("%s\n", "lol");
	log_warn("%s\n", "lol");
	log_info("%s\n", "lol");
	log_debug("%s\n", "lol");
	log_trace("%s\n", "lol");
	logger_close();
	return (0);
}
