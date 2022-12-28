#include <stdio.h>

#include "GameCore.h"
#include "Utils.h"

int main()
{
	HammurabiGame* game = nullptr;
	char buffer[1024];

	while (true)
	{
		if (game != nullptr)
			delete game;

		//fputs("Welcome to Hammurabi game.\n1. Start new game\n2. Load game\n3. Exit\n> ", stdout);
		std::cout << "Welcome to Hammurabi game.\n1. Start new game\n2. Load game\n3. Exit\n> ";

		int result;
		GetCorrectIntegerInput([](int x) { return x >= 1 && x <= 3; }, -1, "Please, enter 1, 2 or 3.\n> ", &result);
		switch (result)
		{
		case 1:
			game = new HammurabiGame();
			game->Play();
			break;
		case 2:
		{
			//FILE* file = nullptr;
			//fputs("Enter file name or press enter to go back:\n> ", stdout);
			//do
			//{
			//	fgets(buffer, 1024, stdin);
			//	if (buffer == "")
			//		break;
			//	fopen_s(&file, buffer, "r");
			//} while (file == nullptr && fputs("File not found, enter file name or press enter to go back:\n> ", stdout));
			//if (file == nullptr)
			//	break;

			std::ifstream file;
			file.open("save.hmr");

			if (!file.is_open())
			{
				std::cout << "No save file found." << std::endl;
				continue;
			}
			game = HammurabiGame::LoadFrom(file);
			if (game == nullptr)
			{
				std::cout << "Save file is corrupt." << std::endl;
				continue;
			}

			file.close();

			game->Play();
			break;
		}
		case 3:
			return 0;
		}
	}

	return 0;
}