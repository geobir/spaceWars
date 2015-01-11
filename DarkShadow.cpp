/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DarkShadow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:34:38 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 00:02:37 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DarkShadow.hpp"
#include "Enemy.hpp"

DarkShadow::DarkShadow(void) : Enemy()
{
	return ;
}

DarkShadow::DarkShadow(DarkShadow const &src) : Enemy(src)
{
	*this = src;
	return ;
}

DarkShadow::~DarkShadow(void)
{
	return ;
}

DarkShadow&	DarkShadow::operator=(DarkShadow const &rhs)
{
	Enemy::operator=(rhs);
	return *this;
}
