#include <iostream>
#include <vector>

using namespace std;

int main()
{
  //c - credit, i - number of items, p - price o an item
  int casesCount, c, i, p;
  bool found;
  vector<int> items;
  cin >> casesCount;
  for (size_t j = 0; j < casesCount; j++)
  {
    cin >> c;
    cin >> i;
    items.clear();
    //getting a vector of items
    for (size_t k = 0; k < i; k++)
    {
      cin >> p;
      items.push_back(p);
    }
    //looking for 2 items which prices sum up to credit. would it be faster if i sorted first?
    for (size_t k = 0; k < items.size() - 1; k++)
    {
      if (items[k] >= c) continue;
      for (size_t l = k + 1; l < items.size(); l++)
      {
        if (items[k] + items[l] == c)
        {
          cout << "Case #" << j + 1 << ": " << k + 1 << " " << l + 1 << endl;
          found = true;
          break;
        }
      }
      if (found)
      {
        found = false;
        break;
      }
    }
  }

  return 0;
}
