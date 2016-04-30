/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_get_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <adrien.nouvel@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 18:42:46 by anouvel           #+#    #+#             */
/*   Updated: 2016/04/30 18:44:03 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

char	*logger_get_time(void)
{
	time_t		tm;
	char		*buf;
	struct tm	*tm_info;

	if (!(buf = (char *)malloc(sizeof(char) * 26)))
		return (NULL);
	tm = time(NULL);
	tm_info = localtime(&tm);
	strftime(buf, 26, "%Y/%m/%d %H:%M:%S", tm_info);
	return (buf);
}
