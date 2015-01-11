		/* \          
	   /  / \         
	  /  /   \        
	 /  /  \  \       Name:     Level.class.cpp
	/  /  / \  \       
   /  /  /\  \  \     by:       gbir
  /  /  /  \  \  \    
 /  /__/____\  \  \   
/____________\  \  \ 
\________________\*/


#include "Level.class.hpp"


Level::Level( void ) : _x(100), _y(50), _score(SCOREBEGIN), _entity( NULL ) {

	this->initMap();
	this->setPlayer();
	return ;

}


Level::Level(int x, int y) : _x(x), _y(y), _score(SCOREBEGIN), _entity( NULL ) {

	this->initMap();
	this->setPlayer();

	return ;

}


Level::Level( Level const & src ) : _x(50), _y(50), _score(SCOREBEGIN), _entity( NULL ) {

	*this = src;

	return ;

}


Level::~Level( void ) {

	if (this->_player1)
		delete this->_player1;

	//supr entity

	endwin();

	return ;

}

void	Level::setPlayer( void ) {

	//his->_player1 = new Player();
	this->_player1 = new Player( 3, 3, 8, 7, 5, 5, 1,"   /\\      \\ \\     /  \\  <|    )>  \\  /    / /     \\/   ", 0, 1.0, 50);

	return ;

}

void	Level::initMap( void ) {

	std::cout << "\rMap init" << std::endl;
	//this->setPlayer();
	std::cout << "\rPlayer Creat" << std::endl;

	this->_beginTime = time( NULL );
	this->_curTime = time( NULL );
	this->_lastTime = time( NULL );

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
}

void	Level::drawInfoBar( void ) {
	std::string			ligne;
	std::string			bar(this->_x / 2 - 5, ' ');
	int 				Stime = this->_curTime - this->_beginTime;
	std::string			s;
	std::stringstream	out;

	out << Stime;
	s = out.str();
	mvprintw(0, this->_x - 15, s.c_str());
	out.str("");
	out << this->_fps;
	s = out.str();
	mvprintw(0, this->_x - 5, s.c_str());

	printw(bar.c_str()); addch(ACS_DIAMOND);
	
	//std::cout << DARK_GRAY << "\rFPS: " << fps << RED << "    ♥ ♥ ♥" << CCOLOR <<" ♥ ♥";
	//std::cout << DARK_GRAY << "    Score: " << LIGHT_BLUE << level.getScore() << CCOLOR << std::endl;
}


void	Level::printMap( void ) {
	t_Entitys	*last;
	int			pY = this->_player1->getY();
	int			pX = this->_player1->getX();
	int			pSY = this->_player1->getSizeY();//static ?
	int			pSX = this->_player1->getSizeX();
	int			i = 0;
	std::string	graph;
	std::string	ligne;

	last = this->_entity;
	graph = this->_player1->getGraph();
	this->_curTime = time( NULL );
	
	clear();
	if (this->_curTime != this->_lastTime)
	{
		this->_fps = this->_cur_fps;
		this->_cur_fps = 0;
	}
	this->drawInfoBar();
	while (i < pSY ) {
		ligne = graph.substr(i * pSX + 1, pSX);
		mvprintw(pY + i, pX, ligne.c_str());
		++i;
	}
	while (last)
	{
		mvprintw(3, 3, "HER");
		last = last->next;
	}
	refresh();
	if (this->_fps > 60 || this->_cur_fps > 150)
		usleep(5000);
	this->_cur_fps += 1;
	this->_lastTime = this->_curTime;
}

int		Level::inPut( void ) {

	int		c;
	int		pX  = this->_player1->getX();
	int		pY  = this->_player1->getY();
	std::string	ligne;

	timeout(0);
	c = getch();
	if ( pY > 0 && c == 'w' )
		this->_player1->setY(pY - 1);
	else if ( pY + this->_player1->getSizeY() < this->_y && c == 's' )
		this->_player1->setY(pY + 1);
	if ( pX > 0 && c == 'a' )
		this->_player1->setX(pX - 1);
	else if ( pX + this->_player1->getSizeX() < this->_x && c == 'd' )
		this->_player1->setX(pX + 1);
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
	if (c == 27 || c == 'q')
		return 1; // esc
	return 0;
}

void	Level::putObj(void *entity){
	t_Entitys	*last;
	t_Entitys	*newEntity;


	newEntity = new t_Entitys;
	newEntity->entity = entity;
	newEntity->next = NULL;
	if (!this->_entity)
	{
		this->_entity = newEntity;
		return ;
	}

	last = this->_entity;

	while (last)
		last = last->next;
	last->next = newEntity;
}


int		Level::getX( void ) const {
	return this->_x;
}
int		Level::getY( void ) const {
	return this->_y;
}
void	Level::setScore ( int i ) {
	this->_score = i;
}
int		Level::getScore( void ) const{

	return this->_score;
}
void	Level::setTime ( time_t cur ) {
	this->_curTime = cur;
}
int		Level::getTime( void ) const{

	return this->_curTime;
}


 Level &   Level::operator=( Level const & rhs ) {

//	this->_map = rhs.getLevel();

	return *this;

}




















