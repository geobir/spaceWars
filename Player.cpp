/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:04:15 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 15:57:15 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) : Entity( _x, _y, _sizex, _sizey, _hp, _max_hp, _dam, _graph, _dir, _speed), _score(50), _invincible(0)
{
	return ;
}

Player::Player(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed, int score) :
			Entity(x, y, sizex, sizey, hp, max_hp, dam, graph, dir, speed), _score(score), _invincible(0)
{
	return ;
}

Player::Player(Player const &src) : Entity(src), _score(50), _invincible(0)
{
	*this = src;
	return ;
}

Player::~Player(void)
{
	return ;
}

Player&	Player::operator=(Player const &rhs)
{
	this->_score = rhs._score;
	this->_invincible = rhs._invincible;
	Entity::operator=(rhs);
	return *this;
}
