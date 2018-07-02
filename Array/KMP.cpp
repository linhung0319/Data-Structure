#include <iostream>
#include <string>
#include <vector>
using namespace std;

void kmp(const string text, const string pattern, vector<int> &result)
{
  int *prefix = new int[pattern.length()];
  int j = -1;
  prefix[0] = j;
  for (int i = 1 ; i < pattern.length() ; i++)
  {
    while ( j > -1 && (pattern[i] != pattern[j + 1]) )
      j = prefix[j];

    if (pattern[i] == pattern[j + 1]) j++;

    prefix[i] = j;
  }

  j = -1;
  for (int i = 0 ; i < text.length() ; i++)
  {
    while ( j > -1 && (text[i] != pattern[j + 1]) )
      j = prefix[j];

    if (text[i] == pattern[j + 1]) j++;

    if ( j == (pattern.length() - 1) ) result.push_back(i - pattern.length() + 1);
  }
}

int main()
{
  string text = "abcdabcdabce";
  string pattern = "abcda";
  vector<int> result;
  kmp(text, pattern, result);
  for (vector<int>::iterator it = result.begin() ; it != result.end() ; it++)
  {
    cout << *it << " ";
  }
}
