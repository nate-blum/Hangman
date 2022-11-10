#include <iostream>
#include "GameDef.h"
using namespace std;

int main() {
	string again;

	do {
		game_def game = game_def();

		bool end;

		do {
			end = game.game_loop();
		} while (!end);

		cout << "Play again (true/false)? ";
		cin >> again;
	} while (again != "false");
}