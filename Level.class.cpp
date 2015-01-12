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


Level::Level( void ) : _x(100), _y(50), _score(SCOREBEGIN), _enemys( NULL ) {

	this->initMap();
	this->setPlayer();
	return ;

}


Level::Level(int x, int y) : _x(x), _y(y), _score(SCOREBEGIN), _enemys( NULL ) {

	this->initMap();
	this->setPlayer();

	return ;

}


Level::Level( Level const & src ) : _x(50), _y(50), _score(SCOREBEGIN), _enemys( NULL ) {

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

	this->putEnemy( new Enemy( 150, 20, 4, 3, 1, 1, 1," /| < |> \\| ", 0, 1.0, 10));
	this->putEnemy( new Enemy( 210, 40, 4, 3, 1, 1, 1," /| < |> \\| ", 0, 1.0, 10));
	this->putEnemy( new Enemy( 220, 30, 3, 3, 1, 1, 1," /}{ > \\}", 0, 2.0, 10));
	this->putEnemy( new Enemy( 210, 30, 3, 3, 1, 1, 1," /}{ > \\}", 0, 2.0, 10));
	this->putEnemy( new Enemy( 200, 30, 3, 3, 1, 1, 1," /}{ > \\}", 0, 2.0, 10));
	this->_player1 = new Player( 20, 3, 8, 7, 5, 5, 1,"   /\\      \\ \\     /  \\  <|    )>  \\  /    / /     \\/   ", 0, 1.0, 50, 0);
	//this->_player1 = new Player( 20, 25, 3, 3, 5, 5, 1," /}{ > \\}", 0, 1.0, 50);

	return ;

}

void	Level::initMap( void ) {

	std::cout << "\rMap init" << std::endl;
	//this->setPlayer();
	std::cout << "\rPlayer Creat" << std::endl;

	this->_beginTime = time( NULL );
	this->_curTime = time( NULL );
	this->_lastTime = time( NULL );
	this->_score = 40;

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
}

void	Level::drawInfoBar( void ) {
	std::string			ligne;
	std::string			bar(this->_x / 2 - 5, ' ');
	int 				Stime = this->_curTime - this->_beginTime;
	int					i = 0;
	std::string			s;
	std::stringstream	out;

	out << "Time: " << Stime;
	s = out.str();
	mvprintw(0, this->_x - 20, s.c_str());
	out.str("");
	out.clear();
	out << "FPS: " << this->_fps;
	s = out.str();
	mvprintw(0, 5, s.c_str());
	out.str("");
	out.clear();
	out << "Score: " << this->_score;
	s = out.str();
	mvprintw(0, this->_x - 30, s.c_str());
	while (i < this->_player1->getHP())
		mvprintw(0, this->_x / 2 - 10 + i++ * 2, "#");
	while (i < this->_player1->getMaxHP())
		mvprintw(0, this->_x / 2 - 10 + i++ * 2, "0");
	
	//std::cout << DARK_GRAY << "\rFPS: " << fps << RED << "    ♥ ♥ ♥" << CCOLOR <<" ♥ ♥";
	//std::cout << DARK_GRAY << "    Score: " << LIGHT_BLUE << level.getScore() << CCOLOR << std::endl;
}

void	Level::colide( void ) {
	t_Entitys	*cur;
	t_Entitys	*cur2;
	t_Entitys	*last = NULL;
	t_Entitys	*last2 = NULL;
//	t_Entitys	*dest = NULL;


	cur = this->_enemys;
	if (!cur)
		return ;

	while (cur)//player hit
	{

		if(cur->enemy->isHit(this->_player1->getX(), this->_player1->getY(), this->_player1->getSizeX(), this->_player1->getSizeY()))
		{

			//dest = cur;
			if (!last)
				this->_enemys = cur->next;
			else
				last->next = cur->next;
			this->_player1->setHP(this->_player1->getHP() - 1);
		}
		last = cur;
		cur = cur->next;
		//if (dest)
		//	delete dest;
	}

	//dest = NULL;
	cur = this->_enemys;

	while (cur)
	{
		last = NULL;
		cur2 = cur;
		while(cur2)
		{
			if(cur2 != cur && cur2->enemy->isHit(cur->enemy->getX(), cur->enemy->getY(), cur->enemy->getSizeX(), cur->enemy->getSizeY()))
			{
				//dest = cur2;
				this->_score += 10;
				if (!last)
					this->_enemys = cur2->next;
				else
					last->next = cur2->next;
				if (!last2)
					this->_enemys = cur->next;
				else
					last2->next = cur->next;

			}
			
			last = cur2;
			cur2 = cur2->next;
		}
		last2 = cur;
		cur = cur->next;
	}

}


void	Level::mouveEntitys( void ) {
	t_Entitys	*cur;

	cur = this->_enemys;


	if (this->_cur_fps % 20 == 1)
	{
		this->colide();
		while (cur)
		{
			cur->enemy->setX(cur->enemy->getX() - cur->enemy->getSpeed());
			cur = cur->next;
		}

	}

}


int		Level::printMap( void ) {
	t_Entitys	*cur;
	int			pY = this->_player1->getY();
	int			pX = this->_player1->getX();
	int			pSY = this->_player1->getSizeY();
	int			pSX = this->_player1->getSizeX();
	int			i = 0;
	std::string	graph;
	std::string	ligne;

	cur = this->_enemys;
	graph = this->_player1->getGraph();
	this->_curTime = time( NULL );
	//this->mouveEntitys();
	if (this->_player1->getHP() <= 0)
	{
		std::cout << "\rYou Die" << std::endl;
		return 1;
	}

	clear();
	this->mouveEntitys();
	if (this->_lastTime != this->_curTime)
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
	while (cur)
	{
		i = 0;
		pY = cur->enemy->getY();
		pX = cur->enemy->getX();
		pSY = cur->enemy->getSizeY();
		pSX = cur->enemy->getSizeX();
		graph = cur->enemy->getGraph();
		while (i < pSY ) {
			ligne = graph.substr(i * pSX , pSX);
			mvprintw(pY + i, pX, ligne.c_str());
			++i;
		}
		cur = cur->next;
	}
	refresh();
	if (this->_fps > 60 || this->_cur_fps > 150)
		usleep(2000);
	this->_cur_fps += 1;
	this->_lastTime = this->_curTime;
	return 0;
}

int		Level::inPut( void ) {

	int		c;
	int		pX  = this->_player1->getX();
	int		pY  = this->_player1->getY();
	std::string	ligne;

	timeout(0);
	c = getch();
	if ( c == 27 || c == 'q' || !this->_player1 )
		return 1; // esc
	if ( pY > 0 && c == 'w' )
		this->_player1->setY(pY - 1);
	else if ( pY + this->_player1->getSizeY() < this->_y && c == 's' )
		this->_player1->setY(pY + 1);
	if ( pX > 0 && c == 'a' )
		this->_player1->setX(pX - 1);
	else if ( pX + this->_player1->getSizeX() < this->_x && c == 'd' )
		this->_player1->setX(pX + 1);
	if ( c == 32 )
		this->putEnemy( new Enemy( this->_player1->getX() + 9, this->_player1->getY() + 3, 1, 1, 1, 1, 1,"-", 0, -2.0) );//tir
	if ( c == 37 )
		;//left
	if ( c == 38 )
		;//up
	if ( c == 39 )
		;//right
	if ( c == 40 )
		;//down

	return 0;
}

void	Level::putEnemy( Enemy *enemy ) {
	t_Entitys	*last;
	t_Entitys	*newEntity;


	newEntity = new t_Entitys;
	newEntity->enemy = enemy;
	newEntity->next = NULL;
	if (!this->_enemys)
	{
		this->_enemys = newEntity;
		return ;
	}

	last = this->_enemys;

	while (last->next)
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




















