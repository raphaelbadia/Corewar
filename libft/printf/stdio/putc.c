/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbadia <rbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:41:10 by rbadia            #+#    #+#             */
/*   Updated: 2016/12/02 21:45:26 by rbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		putc_(char c)
{
	write(1, &c, 1);
	return (1);
}
