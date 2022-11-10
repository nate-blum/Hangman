#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

class game_def {
public:
	map<int, std::string> stages;
	vector<char> incorrect_guesses;
	vector<char> correct_guesses;
	vector<char> word;
	int stage;

	game_def() {
		stage = 0;
        static const char arr[] = { 'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd' };
        word = vector<char>(arr, arr + sizeof(arr) / sizeof(arr[0]));
		incorrect_guesses = vector<char>();
		correct_guesses = vector<char>();
		stages = map<int, std::string>();

		setup();
	}

	bool game_loop();
private:
	void setup();
	void guess();
	void display(bool end);
	bool check_end();
};