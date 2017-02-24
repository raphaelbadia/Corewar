/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:38:56 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/21 21:48:18 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			empty(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\n' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}
