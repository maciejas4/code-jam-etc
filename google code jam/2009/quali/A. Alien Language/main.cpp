#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
NOTES:
-I WANT TO DO THIS OBJECT-ORIENTED IN FUTURE
-VARIABLES' NAMES COULD BE BETTER
-SOME OF IT NEEDS OPTIMIZATION, BECAUSE IT CHECKS LITERALLY EACH CASE EVEN THOUGH SOME OF THEM SHOULD BE SKIPPED, APPROPRIATE INDICATOR IS IN THE CODE
*/

//checks if the given word is in the dictionary
bool WordIsInDictionary(vector<string> dictionary, string word)
{
	for (size_t i = 0; i < dictionary.size(); i++)
	{
		if (dictionary[i] == word)
		{
			return true;
		}
	}
	return false;
}

//checks if there is a word with a given letter on a given position in the dictionary (needed for optimization)
bool WordMightBeInDict(char c, int index, vector<string> dictionary)
{
  for (auto word : dictionary)
  {
    if (word[index] == c)
    {
      return true;
    }
  }
  return false;
}

int main()
{
	//L - count of letters in a word, D - count of words in the dictionary, N - count of test cases
	int L, D, N, indexToIncrease, iterator;
	string temp;
	string wordFromPattern = "";
	char character;
	long long possibleWordsCount; //words possible to create from a pattern
  int matchingCount; //how many words from dictionary match the pattern
	vector<string> dictionary;
	vector<vector<char> > decipheredWord; //a word is a vector of vectors of chars (vector of chars represents a set of possible letters on one position in a word)
	vector<char> possibleLetters;
	cin >> L >> D >> N;
	vector<int> characterIndicator; //e.g. 1,0,2 for (xyz)x(zrtz) means "yxt"

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
		//getting a word to decipher
		decipheredWord.clear();
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
			decipheredWord.push_back(possibleLetters);
		}

		//checking if any of the words from dictionary match the pattern
		possibleWordsCount = 1;
		for (size_t j = 0; j < L; j++)
		{
			possibleWordsCount *= decipheredWord[j].size(); //e.g. possibleWordsCount for (xyz)x(zrtz) would be 3*1*4 = 12
		}
		characterIndicator.clear();
		for (size_t j = 0; j < L; j++)
		{
			characterIndicator.push_back(0);
		}
		//firstly check the word constructed from first letters
		wordFromPattern = "";
		for (size_t j = 0; j < L; j++)
		{
			wordFromPattern += decipheredWord[j][0];
		}
		matchingCount = 0;
		if (WordIsInDictionary(dictionary, wordFromPattern))
		{
			matchingCount++;
		}
		indexToIncrease = L - 1;
		//this loop finds all possible words from a pattern and checks them against the dictionary
    //OPTIMIZATION VERY MUCH NEEDED HERE, e.g. don't check 0xxxx for (mno)(zxcq)(zxcq)(zxcq)(zxcq) if there are no words starting with 'm' in the dictionary
		//cout << endl;
		for (size_t j = 0; j < possibleWordsCount - 1; j++)
		{
			//find the word
			wordFromPattern = "";
			while (characterIndicator[indexToIncrease] == decipheredWord[indexToIncrease].size() - 1)
			{
				indexToIncrease--;
			}
			if (indexToIncrease < 0) break; //important break, current loop is very little likely to run possibleWordsCount times
			for (size_t k = indexToIncrease + 1; k < L; k++)
			{
				characterIndicator[k] = 0;
			}
      characterIndicator[indexToIncrease]++;
			while (!WordMightBeInDict(decipheredWord[indexToIncrease][characterIndicator[indexToIncrease]], indexToIncrease, dictionary) && characterIndicator[indexToIncrease] < decipheredWord[indexToIncrease].size() - 1)
      {
        characterIndicator[indexToIncrease]++;
      }
			if (!WordMightBeInDict(decipheredWord[indexToIncrease][characterIndicator[indexToIncrease]], indexToIncrease, dictionary) && characterIndicator[indexToIncrease] == decipheredWord[indexToIncrease].size() - 1)
			{
				indexToIncrease--;
				for (size_t k = indexToIncrease + 1; k < L; k++)
				{
					characterIndicator[k] = 0;
				}
				continue;
			}
			indexToIncrease = L - 1;
			for (size_t k = 0; k < L; k++)
			{
				wordFromPattern += decipheredWord[k][characterIndicator[k]];
			}
			//check the word
			cout << "Case #" << i + 1 << wordFromPattern << endl;
			if (WordIsInDictionary(dictionary, wordFromPattern))
			{
				matchingCount++;
			}
      
			// for (auto value : characterIndicator)
			// {
			// 	cout << value;
			// }
			// cout << endl;
      
		}
		cout << "Case #" << i + 1 << ": " << matchingCount << endl;

	}

	return 0;
}
