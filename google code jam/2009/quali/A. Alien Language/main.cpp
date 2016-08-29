#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	//L - count of letters in a word, D - count of words in the dictionary, N - count of test cases
	int L, D, N, iterator;
	string temp;
	char character;
	vector<string> dictionary;
	vector<vector<char>> pattern; //a pattern is a vector of vectors of chars (vector of chars represents a set of possible letters on one position in a word)
	vector<char> possibleLetters;
	cin >> L >> D >> N;

	//getting dictionary
	cin.ignore();
	for (size_t i = 0; i < D; i++)
	{
		getline(cin, temp);
		dictionary.push_back(temp);
	}

	//main loop
	for (size_t i = 0; i < N; i++)
	{
		vector<string> tempDictionary(dictionary);
		//getting a pattern
		pattern.clear();
		iterator = 0;
		getline(cin, temp);

		for (size_t j = 0; j < L; j++)
		{
			possibleLetters.clear();
			character = temp[iterator++];
			if (character == '(')
			{
				do
				{
					character = temp[iterator++];
					possibleLetters.push_back(character);
				} while (temp[iterator] != ')');
				iterator++;
			}
			else
			{
				possibleLetters.push_back(character);
			}
			pattern.push_back(possibleLetters);
		}

		//checking if any of the words from dictionary match the pattern
		for (size_t j = 0; j < L; j++)
		{
			for (vector<string>::iterator iter = tempDictionary.begin(); iter != tempDictionary.end();)
			{
				temp = *iter;
				if (find(pattern[j].begin(), pattern[j].end(), temp[j]) == pattern[j].end())
				{
					iter = tempDictionary.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		cout << "Case #" << i + 1 << ": " << tempDictionary.size() << endl;
	}
	return 0;
}
