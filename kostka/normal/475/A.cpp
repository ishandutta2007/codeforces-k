#include "bits/stdc++.h"

using namespace std;

string bus[] = {"+------------------------+", "|#.#.#.#.#.#.#.#.#.#.#.|D|)", "|#.#.#.#.#.#.#.#.#.#.#.|.|", "|#.......................|", "|#.#.#.#.#.#.#.#.#.#.#.|.|)", "+------------------------+"};

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<26; i++)
    for(int j=0; j<6; j++)
      if(n && bus[j][i]=='#')
      {
        bus[j][i] = 'O';
        n--;
      }
  for(int i=0; i<6; i++)
  {
    cout << bus[i];
    if(i<5)
       cout << "\n";
  }
}