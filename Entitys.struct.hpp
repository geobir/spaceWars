		/* \          
	   /  / \         
	  /  /   \        
	 /  /  \  \       Name:     Entitys.struct.hpp
	/  /  / \  \       
   /  /  /\  \  \     by:       gbir
  /  /  /  \  \  \    
 /  /__/____\  \  \   
/____________\  \  \ 
\________________\*/



#ifndef ENTITYS_STRUCT_HPP
# define ENTITYS_STRUCT_HPP

# include "Enemy.hpp"

typedef struct			s_Entitys {

	Enemy				*enemy;
	struct	s_Entitys	*next;
	
}						t_Entitys;


#endif