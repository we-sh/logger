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
	log_fatal("%s", "lol");
	log_error("%s", "lol");
	log_warn("%s", "lol");
	log_info("%s", "lol");
	log_debug("%s", "lol");
	log_trace("%s", "lol");
	logger_close();
	return (0);
}
