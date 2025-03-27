/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:03:05 by youmoumn          #+#    #+#             */
/*   Updated: 2025/03/27 14:48:39 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_atoi(char *s);
void	ft_putnbr(int n);
void	send_bit(int pid, int bit);
void	send_nl(int pid);
void	ft_bzero(char *s, size_t n);
void	handll_ctlc(int sig);
int		is_dig(char *pid);
int		handlle_out(char c, int f);

#endif