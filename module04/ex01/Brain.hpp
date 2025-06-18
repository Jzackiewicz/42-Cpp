#pragma once

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain& obj);
		Brain &operator=(const Brain &other);
		~Brain(void);
		
		void		setIdea(std::string idea, unsigned int idx);
		std::string	getIdea(unsigned int idx);
};