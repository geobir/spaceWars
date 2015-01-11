		/* \          
	   /  / \         
	  /  /   \        
	 /  /  \  \       Name:     Level.class.hpp
	/  /  / \  \       
   /  /  /\  \  \     by:       gbir
  /  /  /  \  \  \    
 /  /__/____\  \  \   
/____________\  \  \ 
\________________\*/


#ifndef LEVEL_CLASS_HPP
# define LEVEL_CLASS_HPP

# include <iostream>

# include <ncurses.h>
# include <time.h>

# include "Player.hpp"

# include "Entitys.struct.hpp"
# include "Color.define.hpp"

# define SCOREBEGIN 50

class Level {


public:


	Level( void );
	Level( int x, int y );
	Level( Level const & src );
	~Level( void );

	Level &    operator=( Level const & rhs );

	int   		getX( void ) const;
	int   		getY( void ) const;
	void		setScore( int i );
	int			getScore( void ) const;
	void		setPlayer( void );
	void		setTime ( time_t cur );
	int			getTime( void ) const;

	void    resetMap( void );
	void    printMap( void );
	void	putObj(void *entity);


private:
	WINDOW		*_win;
	time_t		_begin;
	time_t		_curTime;
	const int   _x;
	const int   _y;
	int			_score;
	//std::string _map;

	Player		*_player1;
	t_Entitys	*_entity;


};



#endif