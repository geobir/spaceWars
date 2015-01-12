/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 22:40:28 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 20:12:22 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity(void) : _x(0), _y(0), _sizex(1), _sizey(1), _hp(5), _max_hp(5), _dam(1), _graph("    "), _dir(1), _speed(1.0), _score(0)
{
	return ;
}

Entity::Entity(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed, int score) :
			_x(x), _y(y), _sizex(sizex), _sizey(sizey), _hp(hp), _max_hp(max_hp), _dam(dam), _graph(graph), _dir(dir), _speed(speed), _score(0)
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
/*	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_sizex = rhs._sizex;
	this->_sizey = rhs._sizey;
	this->_hp = rhs._hp;
	this->_max_hp = rhs._max_hp;
	this->_dam = rhs._dam;
	this->_graph = rhs._graph;
	this->_dir = rhs._dir;
	this->_speed = rhs._speed;
	this->_score = rhs._score;*/
	*this = rhs;
	return *this;
}

int			Entity::getX(void)
{
	return this->_x;
}

int			Entity::getY(void)
{
	return this->_y;
}

void		Entity::setX(int x)
{
	this->_x = x;
}

void		Entity::setY(int y)
{
	this->_y = y;
}

int			Entity::takeDamage(int amount)
{
	if (amount > this->_hp)
	{
		this->_hp = 0;
		return (1);
	}
	else
	{
		this->_hp = this->_hp - amount;
		return (0);
	}
}

int			Entity::getSizeX(void)
{
	return this->_sizex;
}

int			Entity::getSizeY(void)
{
	return this->_sizey;
}

int			Entity::getHP(void)
{
	return this->_hp;
}

void		Entity::setHP(int hp)
{
	this->_hp = hp;
}

int			Entity::getMaxHP(void)
{
	return this->_max_hp;
}

float		Entity::getSpeed(void)
{
	return this->_speed;
}

std::string	Entity::getGraph(void)
{
	return this->_graph;
}


int			Entity::isHit(int x, int y, int sizeX, int sizeY){
	
	if (    (this->_x >= x && (this->_x < x + sizeX))
		||    (this->_x <= x && (this->_x > x - sizeX)) )
	{
		if (    (this->_y >= y && this->_y < y + sizeY)
			||    (this->_y < y && (this->_y > y - sizeY)) )
		{
			return 1;
		}
	}

	return 0;
}
























