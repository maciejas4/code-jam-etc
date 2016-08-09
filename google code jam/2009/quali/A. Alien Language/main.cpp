#include <iostream>
#include <vector>

using namespace std;

//I WANT TO DO THIS OBJECT-ORIENTED IN FUTURE
int main()
{
  //L - count of letters in a word, D - count of words in the dictionary, N - count of test cases
  int L, D, N;
  string temp;
  char token;
  vector<string> dictionary;
  vector<string> decipheredWords;
  vector<vector<char>> decipheredWord; //a word is a vector of vectors of chars (vector of chars represents a set of possible letters on one position in a word)
  vector<char> possibleLetters;
  cin >> L >> D >> N;

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
    for (size_t j = 0; j < L; j++)
    {
      decipheredWord.clear();
      cin >> token;
      if(token == '(')
      {
        do
        {
          cin >> token;
        } while(token != ')')
      }
      else
    }
  }

  return 0;
}
