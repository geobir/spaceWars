		/* \          
	   /  / \         
	  /  /   \        
	 /  /  \  \       Name:     main.cpp
	/  /  / \  \       
   /  /  /\  \  \     by:       gbir
  /  /  /  \  \  \    
 /  /__/____\  \  \   
/____________\  \  \ 
\________________\*/

#include <unistd.h>
#include <iostream>


#include "Level.class.hpp"


void	infoBar( Level level, int fps) {
	start_color();
	init_pair(1, 1, 2);
	attrset (COLOR_PAIR(1));
	std::cout << DARK_GRAY << "\rFPS: " << fps << RED << "    ♥ ♥ ♥" << CCOLOR <<" ♥ ♥";
	std::cout << DARK_GRAY << "    Score: " << LIGHT_BLUE << level.getScore() << CCOLOR << std::endl;
}


int		main( void )
{
	time_t	now;
	time_t	last = time( NULL );
	int		fps = 0;
	int		cFps = 0;
	Level	level(200, 50);

	int	x = 5000;
	int	y = 5;

	while ( 42 )
	{
		if (level.inPut())
			break ;
		//infoBar( level , fps );
		//level.resetMap();
		if (level.printMap())
			break ;
		//std::cout << "." ;
//		if (fps > 60 || cFps > 150)
//			usleep(5000);
	}
	return 0;

}
