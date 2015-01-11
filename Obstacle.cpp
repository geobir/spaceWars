/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:20:11 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 15:55:34 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle(void) : Entity( _x, _y, _sizex, _sizey, _hp, _max_hp, _dam, _graph, _dir, _speed)
{
	return ;
}

Obstacle::Obstacle(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed): Entity(x, y, sizex, sizey, hp, max_hp, dam, graph, dir, speed)
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
