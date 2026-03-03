#include "Harl.hpp"

/* Levels of complaints */
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

/* Convert level string to integer for switch statement */
int Harl::getLevelIndex(const std::string& level)
{
    if (level == "DEBUG") return 0;
    if (level == "INFO") return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR") return 3;
    return -1; // Invalid level
}

/* Complain function that uses switch to filter messages from level and above */
void Harl::complain(const std::string& level)
{
    int levelIndex = getLevelIndex(level);
    
    switch (levelIndex)
    {
		case 0: // DEBUG - fall through to show all levels
		debug();
		// fall through
        case 1: // INFO - fall through to show INFO, WARNING, ERROR
		info();
		// fall through
        case 2: // WARNING - fall through to show WARNING, ERROR
		warning();
		// fall through
        case 3: // ERROR - show only ERROR
		error();
		break; 	// break at ERROR; it's the highest level of complaint
        default: // Invalid level
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
