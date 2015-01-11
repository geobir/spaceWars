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

int		inPut( Level level, int *x, int *y)
{

	int		c;

	timeout(0);
	c = getch();
	
	if ( c == 'w' )
		--*y;
	if ( c == 's' )
		++*y;
	if ( c == 'a' )
		--*x;
	if ( c == 'd' )
		++*x;
	if ( c == 32 )
		;//tir
	if ( c == 37 )
		;//left
	if ( c == 38 )
		;//up
	if ( c == 39 )
		;//right
	if ( c == 40 )
		;//down
	if (c == 27)
		return 0;
	return 1;
}


int		main( void )
{
	time_t	now;
	time_t	last = time( NULL );
	int		fps = 0;
	int		cFps = 0;
	Level		level(200, 50);
	int			c;

	int	x = 5;
	int	y = 5;

	initscr();
	cbreak();
	noecho();
//	keypad(menu_win, TRUE);

	while ( 42 )
	{
		now = time( NULL );
		clear();
		
		if (now != last)
		{
			fps = cFps;
			cFps = 0;
		}
		if (!inPut( level , &x, &y))
			break ;
		infoBar( level , fps );
		level.resetMap();
		//level.putObj(x, y, 8, 7, "  /\\      \\ \\     /  \\  <|    )>  \\  /    / /     \\/    ");
		level.printMap();
		
		if (fps > 60 || cFps > 150)
			usleep(5000);
		last = now;
		++cFps;
		refresh();
	}
	return 0;

}
