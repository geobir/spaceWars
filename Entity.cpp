/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:40:28 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 11:15:08 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(void)
{
	return ;
}

Entity::Entity(int x, int y, int sizex, int sizey, int hp, int maxhp, int dam, std::string graph, int dir, float speed) :
		_x(x), _y(y), _sizex(sizex), _sizey(sizey), _hp(hp), _max_hp(maxhp), _dam(dam), _graph(graph), _dir(dir), _speed(speed)
{
	return ;
}

Entity::Entity(Entity const &src)
{
	*this = src;
	return ;
}

Entity::~Entity(void)
{
	return ;
}

Entity&		Entity::operator=(Entity const &rhs)
{
	return *this;
}

void		Entity::setX(int x)
{
	this->_x = x;
}

void		Entity::setY(int y)
{
	this->_y = y;
}
