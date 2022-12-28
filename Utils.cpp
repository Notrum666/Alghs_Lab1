#include "Utils.h"

bool GetCorrectIntegerInput(std::function<bool(int x)> validator, int tries, const char* errorMessage, int* result)
{
	//char buffer[22]; // -long_max\n0
	//char* parsingEnd;
	//do
	//{
	//	fgets(buffer, 22, stdin);
	//	*result = std::strtol(buffer, &parsingEnd, 10);
	//	if (parsingEnd != buffer && *parsingEnd == '\n' && validator(*result))
	//		return true;
	//	fputs(errorMessage, stdout);
	//} while (tries == -1 || --tries > 0);
	//return false;
	while (!(std::cin >> *result) || !validator(*result))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (tries > 0 && --tries == 0)
			return false;
		std::cout << errorMessage;
	}

	return true;
}