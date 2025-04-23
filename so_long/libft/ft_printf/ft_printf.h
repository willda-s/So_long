/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:49:10 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/13 03:00:21 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

int		ft_formatspercentage(va_list args, const char format);

int		ft_putstr(char *str);

int		ft_putnbr(int n);

size_t	hexa_nbr(unsigned int n);

void	ft_puthexa(unsigned int n, bool upper_case);

int		prt_hexa(unsigned int n, bool upper_case);

size_t	address_nbr(unsigned long n);

void	ft_putaddress(unsigned long n, bool upper_case);

int		prt_address(unsigned long n, bool upper_case);

int		ft_putchar(int c);

int		ft_printf(const char *str, ...);

int		ft_putnbr_unsigned(unsigned int n);

char	*ft_itoa_unsigned(unsigned int n);

int		ft_strlenint_unsigned(unsigned int n);

char	*ft_itoa(int n);

#endif