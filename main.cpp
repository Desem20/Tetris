#include "Game.h"
int main()
{
	bool exit = false;
	int choice;
	cout << "Press 1 to Start the game" << endl <<
		"press 2 to continue/hold the game" << endl <<
		"press 3 to make the pieces fall faster" << endl <<
		"press 4 to make the pieces fall Slower" << endl <<
		"press 9 to exit the game" << endl;
	while (!exit)
	{
		cin >> choice;
		Game game;
		switch (choice)
		{
		case START:
			game.Run();
			break;

		case EXIT:
			exit = true;
			break;
		}
	}
	system("pause>null");
}
