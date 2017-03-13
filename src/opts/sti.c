/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbadia <rbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:43:51 by rbadia            #+#    #+#             */
/*   Updated: 2017/03/13 15:49:38 by rbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
#include "graphic.h"


static void		print_sti(t_vm *vm, unsigned int pc[2], int r[3])
{
	printf("%d %d\n", r[1], r[2]);
	printf("       | -> store to %d + %d = %d ", r[1], r[2], (r[1] + r[2]));
	printf("(with pc and mod %d)\n", pc[0] + ((r[1] + r[2]) % IDX_MOD));
}

void	sti(t_vm *vm, t_process *process)
{
	unsigned int	pc[2];
	int				i;
	int				r[3];
	unsigned char	octal[2];

	pc[0] = process->pc;
	pc[1] = process->pc + 3;
	i = 1;
	r[0] = vm->map[PTR(pc[0] + 2)];
	if (vm->flag & verbose)
		printf("P %4d | sti r%u ", process->id, r[0]);
	r[0] = process->r[r[0] - 1];
	octal[0] = (vm->map[PTR(pc[0] + 1)] >> 4) & 3;
	octal[1] = (vm->map[PTR(pc[0] + 1)] >> 2) & 3;
	while (i < 3)
	{
		r[i] = get_param(vm, process, pc, (int[3]){octal[i - 1], 1, 1});
		++i;
	}
	if (vm->flag & verbose)
		print_sti(vm, pc, r);
	st_param(vm, pc[0] + ((r[1] + r[2]) % IDX_MOD), r[0]);
	refresh_map(vm, PTR(pc[0] + ((r[1] + r[2]) % IDX_MOD)), 4,
															process->id_player);
	process->pc = pc[1];
}