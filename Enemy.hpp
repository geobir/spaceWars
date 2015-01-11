/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:08:07 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 10:58:40 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Entity.hpp"

class	Enemy : public Entity
{
	public:
		Enemy(int x, int y, int sizex, int sizey, int hp, int max_hp, int dam, std::string graph, int dir, float speed);
		Enemy(void);
		Enemy(Enemy const &src);
		~Enemy(void);

		Enemy	&operator=(Enemy const &rhs);
};

#endif
