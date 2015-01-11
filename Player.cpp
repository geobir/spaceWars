/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:04:15 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 11:32:11 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) : Entity(), _score(50)
{
	this->_invincible = 0;
	return ;
}

Player::Player(int x, int y, int sizex, int sizey, int hp, int maxhp, int dam, std::string graph, int dir, float speed, int score) :
		Entity(), _score(score) 
{
	this->_invincible = 0;
	return ;
}

Player::Player(Player const &src) : Entity(src), _score(50)
{
	this->_invincible = 0;
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
