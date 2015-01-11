/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:13:45 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 11:15:11 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <iostream>

class	Entity
{
	
	public:
		Entity(int x, int y, int sizex, int sizey, int hp, int maxhp, int dam, std::string graph, int dir, float speed);
		Entity(void);
		Entity(Entity const &src);
		~Entity(void);

		Entity	&operator=(Entity const &rhs);
		void	setX(int x);
		void	setY(int y);
		//void	takeDamage(int	amount);
		//void	shoot(void);

	protected:
		int			_x;
		int			_y;
		int			_sizex;
		int			_sizey;
		int			_hp;
		int			_max_hp;
		int			_dam;
		std::string	_graph;
		int			_dir;
		float		_speed;
};

#endif
