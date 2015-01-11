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
# include <sstream>

# include <ncurses.h>
# include <time.h>
# include <unistd.h>

# include "Player.hpp"

# include "Entitys.struct.hpp"
# include "Color.define.hpp"

# define SCOREBEGIN 50

class Level {


public:

	Player		*_player1;

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

	void		initMap( void );
	void		drawInfoBar( void );
	void		printMap( void );
	int			inPut( void );
	void		putObj(void *entity);



private:
	WINDOW		*_win;
	time_t		_beginTime;
	time_t		_curTime;
	time_t		_lastTime;
	const int   _x;
	const int   _y;
	int			_score;
	int			_fps;
	int			_cur_fps;

	t_Entitys	*_entity;


};



#endif