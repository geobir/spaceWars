/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:13:37 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 11:30:04 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

#include "Entity.hpp"

class	Obstacle : public Entity
{
	public:
		Obstacle(int c, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed);
		Obstacle(void);
		Obstacle(Obstacle const &src);
		~Obstacle(void);

		Obstacle	&operator=(Obstacle const &rhs);
};

#endif
