/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:09:05 by jye               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/02/24 18:43:07 by jye              ###   ########.fr       */
=======
/*   Updated: 2017/02/24 16:38:31 by vcombey          ###   ########.fr       */
>>>>>>> b939ef7d56c7762bef6e6430f0f6f5a846b6ed89
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# define ERROR "Error"
# define MAP_MAX_SIZE (MEM_SIZE - 1)

/*
** The following flag should be added, -n -dump
** -n [number] player
** -dump dump vm at cycle
** r1 == given out as player_id at launch
** *******
** MEM_SIZE / player == offset between each player
** *******
** if process has not live in CYCLE_TO_DIE, process will be killed
** *******
** *******
** game is over when all process are dead
** *******
** Player X (champion_name) won where X is the player’s number and
** champion_name is its name.
** *******
** A process shows that player X (champion_name) is alive
** *******
** live T_DIR-> T_DIR is the player number required for live
** -------
** ld T_DIR | T_IND , T_REG, for T_DIR as argument, directly stack as int,
**					  for T_IND as argument -> *(PC + (IND % IDX_MOD))
** 												taking directly
**												4 bytes as its T_DIR
** ldi T_REG | T_IND | T_DIR, T_DIR | T_REG, T_REG,
** *((1st param + 2nd param) % IDX_MOD) -> REG
** or
** *((*(PC + T_IND % IDX_MOD) + 2nd param) % IDX_MOD) -> REG
** 1 cycle 1 byte // jump when cycle finishes for opt
** fork carry over all property of the current process
** process are unique
*/

typedef struct	s_champ
{
	char			*name;
	char			*comment;
	unsigned char	*byte_code;
	unsigned int	size;
	unsigned int	last_live;
	unsigned int	live;
	unsigned int	id_player;
}				t_champ;

typedef struct	s_arg
{
	char	**av;
	int		i;
	int		ac;
}				t_arg;

typedef struct	s_vm
{
	enum			e_flag
	{
		dump = 1,
		visual = 2,
		aff = 4
	}				flag;
	unsigned int	dump_cycle;
	unsigned int	nb_player;
	unsigned int	cycle_to_die;
	unsigned int	checks;
	unsigned long	nb_process;
	unsigned long	cycle; // current cycle;
	unsigned char	map[MEM_SIZE];
	t_champ			*champ;
}				t_vm;

typedef struct	s_process
{
	unsigned int	r[16];
	unsigned int	last_live;
	unsigned int	exec_cycle;
	unsigned int	op_code;
	unsigned int	pc;
	unsigned int	carry;
}				t_process;

typedef struct	s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
	void			*data;
}				t_lst;

/*
** OPT function
*/

void	live(t_vm *vm, t_process *process);
void	ld(t_vm *vm, t_process *process);

/*
** LST function
*/
t_lst			*init_lst__(void *data);
void			push_lst__(t_lst **node, void *data);
void			pop_lst__(t_lst **node, void (*del)());
void			append_lst__(t_lst *node, void *data);
#endif
