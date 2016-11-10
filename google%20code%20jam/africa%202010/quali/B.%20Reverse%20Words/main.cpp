#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	int n;
	string line;
	vector<string> words;
	string word;
	stringstream ss;
	vector<string>::iterator it;

	cin >> n;
	cin.ignore();
	for (size_t i = 0; i < n; i++)
	{
		words.clear();
		ss.clear();
		getline(cin, line);
		ss << line;
		while (getline(ss, word, ' '))
		{
			it = words.insert(words.begin(), word);
		}
		cout << "Case #" << i + 1 << ": ";
		for (it = words.begin(); it != words.end(); ++it) //for (auto value : words) {cout << value << " ";}
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}

//test