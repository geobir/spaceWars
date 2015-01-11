/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Leviathan.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:11:52 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 00:02:30 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Leviathan.hpp"
#include "Enemy.hpp"

Leviathan::Leviathan(void) : Enemy()
{
	return ;
}

Leviathan::Leviathan(Leviathan const &src) : Enemy(src)
{
	*this = src;
	return ;
}

Leviathan::~Leviathan(void)
{
	return ;
}

Leviathan&	Leviathan::operator=(Leviathan const &rhs)
{
	Enemy::operator=(rhs);
	return *this;
}
