#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

void GetWord(FILE* fCfg, char word[]);

int main()
{
  char word[200];
  FILE *fCfg = fopen("testFile.txt", "rb");
  GetWord(fCfg, word);
  cout << word[25] << endl;
  unsigned long a = strtoul(word, NULL, 0);
  cout << a << endl;
}

void GetWord(FILE* fCfg, char word[])
{
  char c;

  do {
    c = fgetc(fCfg);
    //if ('#' == c) {
    //  // Go to next line
    //  char tmp[1024];
    //  fgets(tmp, 1024, fCfg);
    //}
  }
  while ((isspace(c) || ('#' == c)) && !feof(fCfg));

  // Read the word now
  fseek(fCfg, -1, SEEK_CUR); // Since we read one character into c.
  fscanf(fCfg, "%s", word);
}
