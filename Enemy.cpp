/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:19:25 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 15:55:09 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : Entity(_x, _y, _sizex, _sizey, _hp, _max_hp, _dam, _graph, _dir, _speed, _score)
{
	return ;
}

Enemy::Enemy(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed, int score) :
			Entity(x, y, sizex, sizey, hp, max_hp, dam, graph, dir, speed, score)
{
	return ;
}

Enemy::Enemy(Enemy const &src) : Entity(src)
{
	*this = src;
	return ;
}

Enemy::~Enemy(void)
{
	return ;
}

Enemy&	Enemy::operator=(Enemy const &rhs)
{
	Entity::operator=(rhs);
	return *this;
}
