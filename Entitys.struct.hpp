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

typedef struct			s_Entitys {

	void				*entity;
	struct	s_Entitys	*next;
	
}						t_Entitys;


#endif