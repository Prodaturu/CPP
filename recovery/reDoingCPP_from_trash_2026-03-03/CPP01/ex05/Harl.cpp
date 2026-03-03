#include "Harl.hpp"

/* Levels of complaints */
void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


/* Complain function that maps levels to their corresponding functions */

void Harl::complain(const std::string& level)
{
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    const size_t NUM_LEVELS = sizeof(levels) / sizeof(levels[0]);
    
    for (size_t i = 0; i < NUM_LEVELS; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
