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


Level::Level( void ) : _x(100), _y(50), _score(SCOREBEGIN) {

	this->resetMap();
	this->setPlayer();
	return ;

}


Level::Level(int x, int y) : _x(x), _y(y), _score(SCOREBEGIN) {

	this->resetMap();
	this->setPlayer();

	return ;

}


Level::Level( Level const & src ) : _x(50), _y(50), _score(SCOREBEGIN) {

	*this = src;

	return ;

}


Level::~Level( void ) {

	if (this->_player1)
		delete this->_player1;

	return ;

}

void	Level::setPlayer( void ) {

	this->_player1 = new Player();

	return ;

}

void	Level::resetMap( void ) {
	this->_win = newwin(this->_x, this->_y, 0, 0);
	this->_begin = time( NULL );
	this->_curTime = this->_begin;
}


void	Level::printMap( void ) {
/*	int			x = 0;
	int			y = 0;

	std::cout << "\r" << DARK_GRAY << std::string(this->_x , '<') << std::endl;
	while (y < this->_y)
	{
		std::cout << "\r" << LIGHT_BLUE  << this->_map.substr(y * this->_x, this->_x) << CCOLOR << std::endl;
		++y;
	}
	std::cout << "\r" << DARK_GRAY << std::string(this->_x , '<') << std::endl;
*/
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




















