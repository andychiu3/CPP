#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	h;
	
	h.complain("DEBUG");		
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	return (0);
}
