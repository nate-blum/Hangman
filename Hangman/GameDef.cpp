#include "GameDef.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

bool contains(vector<char> vec, char c);

void game_def::guess() {
	char guess;
	cout << "\nWhat's your guess? ";
	cin >> guess;

	if (contains(word, guess)) {
		correct_guesses.push_back(guess);
	} else if (!contains(incorrect_guesses, guess)) {
		incorrect_guesses.push_back(guess);
		stage++;
	}
}

void game_def::setup() {
	std::string tmp_stages[] = {
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |\n" +
		"  |\n" +
		"  |\n" +
		"  |\n" +
		"--------\n",
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |       O\n" +
		"  |\n" +
		"  |\n" +
		"  |\n" +
		"--------\n",
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |       O\n" +
		"  |       |\n" +
		"  |\n" +
		"  |\n" +
		"--------\n",
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |       O\n" +
		"  |      /|\n" +
		"  |\n" +
		"  |\n" +
		"--------\n",
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |       O\n" +
		"  |      /|\\\n" +
		"  |\n" +
		"  |\n" +
		"--------\n",
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |       O\n" +
		"  |      /|\\\n" +
		"  |      /\n" +
		"  |\n" +
		"--------\n",
		std::string() +
		"  ---------\n" +
		"  |       |\n" +
		"  |       O\n" +
		"  |      /|\\\n" +
		"  |      / \\\n" +
		"  |\n" +
		"--------\n"
	};

	for (int i = 0; i < sizeof(tmp_stages) / sizeof(*tmp_stages); i++)
		stages.insert(pair<int, std::string>(i, tmp_stages[i]));
}

void game_def::display(bool end) {
	if (!end) {
		system("CLS");
		cout << stages[stage];

		cout << "\nCorrect:\n";
		for (char c : word) {
			if (contains(correct_guesses, c)) {
				cout << c << " ";
			}
			else {
				cout << "_ ";
			}
		}

		cout << "\n\nIncorrect:\n";
		for (char c : incorrect_guesses) {
			cout << c << " ";
		}
		cout << "\n";
	}
}

bool game_def::check_end() {
	vector<char> _correct_guesses(correct_guesses);
	vector<char> _word(word);

	sort(_correct_guesses.begin(), _correct_guesses.end());
	sort(_word.begin(), _word.end());

	vector<char>::iterator it;
	it = unique(_correct_guesses.begin(), _correct_guesses.end());
	_correct_guesses.resize(distance(_correct_guesses.begin(), it));
	it = unique(_word.begin(), _word.end());
	_word.resize(distance(_word.begin(), it));

	if (string(_correct_guesses.begin(), _correct_guesses.end()) == string(_word.begin(), _word.end())) {
		system("CLS");
		cout << "You win!\n\n";
		return true;
	} else if (incorrect_guesses.size() > 6) {
		system("CLS");
		cout << "You lose.\n\n";
		return true;
	}

	return false;
}

bool game_def::game_loop() {
	bool end = check_end();
	display(end);
	if (!end) guess();

	return end;
}

bool contains(vector<char> vec, char c) {
	return any_of(vec.begin(), vec.end(), [&](char d) {return c == d; });
}