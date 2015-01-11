/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DarkShadow.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:40 by bdismuke          #+#    #+#             */
/*   Updated: 2015/01/11 00:02:43 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARKSHADOW_HPP
# define DARKSHADOW_HPP

# include "Enemy.hpp"

class		DarkShadow : public Enemy
{
	public:
		DarkShadow(void);
		DarkShadow(DarkShadow const &src);
		~DarkShadow(void);

		DarkShadow	&operator=(DarkShadow const &rhs);
};

#endif
