/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:59:08 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 14:42:37 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Entity.hpp"

class	Player : public Entity
{
public:
	Player(void);
	Player(int x, int y, int sizex, int sizey, int hp, int maxhp, int dam, std::string graph, int dir, float speed, int score);
	Player(Player const &src);
	~Player(void);

	Player	&operator=(Player const &rhs);

protected:
	int		_score;
	bool	_invincible;

};

#endif
