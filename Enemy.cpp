/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:19:25 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 10:59:26 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed) : Entity()
{
	return ;
}

Enemy::Enemy(void)
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
