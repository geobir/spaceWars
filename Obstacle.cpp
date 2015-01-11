/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:20:11 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 11:30:18 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed): Entity()
{
	return ;
}

Obstacle::Obstacle(void)
{
	return ;
}

Obstacle::Obstacle(Obstacle const &src) : Entity(src)
{
	*this = src;
	return ;
}

Obstacle::~Obstacle(void)
{
	return ;
}

Obstacle&	Obstacle::operator=(Obstacle const &rhs)
{
	Entity::operator=(rhs);
	return *this;
}
