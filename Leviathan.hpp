/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Leviathan.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:33:19 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 15:03:00 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVIATHAN_HPP
# define LEVIATHAN_HPP

# include "Enemy.hpp"

class		Leviathan : public Enemy
{
	public:
		Leviathan(void);
		Leviathan(Leviathan const &src);
		~Leviathan(void);

		Leviathan	&operator=(Leviathan const &rhs);
};

#endif
