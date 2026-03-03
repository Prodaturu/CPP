#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		void complain(const std::string& level);  // Must match .cpp file exactly
};

#endif // HARL_HPP