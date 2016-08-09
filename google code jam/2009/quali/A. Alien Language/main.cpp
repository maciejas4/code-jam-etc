#include <iostream>
#include <vector>

using namespace std;

//I WANT TO DO THIS OBJECT-ORIENTED IN FUTURE
int main()
{
  //L - count of letters in a word, D - count of words in the dictionary, N - count of test cases
  int L, D, N, indexToIncrease;
  string temp;
  char character;
  int possibleWords; //words possible to create from a pattern
  vector<string> dictionary;
  vector<vector<char> > decipheredWord; //a word is a vector of vectors of chars (vector of chars represents a set of possible letters on one position in a word)
  vector<char> possibleLetters;
  cin >> L >> D >> N;
  vector<int> characterIndicator;

//getting dictionary
  for (size_t i = 0; i < D; i++)
  {
    cin >> temp;
    dictionary.push_back(temp);
  }

//main loop
  for (size_t i = 0; i < N; i++)
  {
    //getting a word to decipher
    decipheredWord.clear();
    for (size_t j = 0; j < L; j++)
    {
      possibleLetters.clear();
      cin >> character;
      if(character == '(')
      {
        do
        {
          cin >> character;
          possibleLetters.push_back(character);
        } while(character != ')');
      }
      else
      {
        possibleLetters.push_back(character);
      }
      decipheredWord.push_back(possibleLetters);
    }

    //checking if any of the words from dictionary match the pattern
    possibleWords = 1;
    for (size_t i = 1; i <= L; i++)
    {
      possibleWords *= decipheredWord[i].size(); //e.g. possibleWords for (xyz)x(zrtz) would be 3*1*4 = 12
    }
    characterIndicator.clear();
    for (size_t i = 0; i < characterIndicator.size(); i++)
    {
      characterIndicator.push_back(0);
    }
    indexToIncrease = L - 1;
    for (size_t i = 0; i < possibleWords; i++)
    {
      if (characterIndicator[indexToIncrease] < decipheredWord[indexToIncrease].size() - 1)
      {
        characterIndicator[indexToIncrease]++;
      }
      else
      {
        
      }
    }
  }

  return 0;
}
