//------------------------------------------------------------------------------
// example105.cpp
//
// a script to multiply the polinomials for assignment 10.5
// (X^0Y^0 + X^1Y^1 + ... + X^25Y^25)
// (X^0Y^0 + X^2Y^1 + ... + X^24Y^12)
// (X^0Y^0 + X^5Y^1 + ... + X^25Y^5)
// (X^0Y^0 + X^10Y^1 + X^20Y^2)
// (X^0Y^0 + X^20Y^1)
// 
// *In order to run the script a C++ compiler (like g++) is required
// *To compile the script use the command in terminal:
//    g++ -o run example105.cpp
// *To run the script use the command in terminal:
//    ./run
//
//  The program prints all terms of the resulting polynomial and the computed
//  result for assignemnt 10.5
//
// Author:
//          Gabriel Muresan
//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <utility>
#include  <map>

using namespace std;

map<pair<int,int>,int> polynomial;
map<pair<int,int>,int> polynomial2;
map<pair<int,int>,int> polynomial5;
map<pair<int,int>,int> polynomial10;
map<pair<int,int>,int> polynomial20;

/*

(x+1)(x+1)
x(x+1) + (x+1)
x^2 + x + x + 1
x^2 + 2x + 1

(x^2 + 2x + 1)(x+1)
x(x^2 + 2x + 1) + (x^2 + 2x + 1)
x^3 + 2x^2 + x + x^2 + 2x + 1;

(1 + xy + x^2y^2)



*/
int main()
{

  for (int i=0; i<=25; i++)
  {
    pair<int,int> term;
    term.first = i;
    term.second = i;
    polynomial.insert(make_pair(term, 1));
/*
    polynomial2.insert(make_pair(term, 1));
    polynomial5.insert(make_pair(term, 1));
    polynomial10.insert(make_pair(term, 1));
    polynomial20.insert(make_pair(term, 1));
*/

  }

  for (int i=0; i<=12; i++)
  {
    pair<int,int> term;
    term.first = 2*i;
    term.second = i;

    for(auto it = polynomial.begin(); it != polynomial.end(); it++)
    {
      auto pol_term = it->first;
      int f_exp = term.first + pol_term.first;
      int s_exp = term.second + pol_term.second;

      pair<int,int> n_term;
      n_term.first=f_exp;
      n_term.second=s_exp;

      if(polynomial2.find(n_term)==polynomial2.end())
      {
        pair<int,int> term2;
        term2.first = f_exp;
        term2.second = s_exp;
        polynomial2.insert(make_pair(term2, it->second));
      }
      else
      {
        polynomial2[n_term]+=it->second;
      }

    }
  }


  for (int i=0; i<=5; i++)
  {
    pair<int,int> term;
    term.first = 5*i;
    term.second = i;

    for(auto it = polynomial2.begin(); it != polynomial2.end(); it++)
    {
      auto pol_term = it->first;
      int f_exp = term.first + pol_term.first;
      int s_exp = term.second + pol_term.second;

      pair<int,int> n_term;
      n_term.first=f_exp;
      n_term.second=s_exp;

      if(polynomial5.find(n_term)==polynomial5.end())
      {
        pair<int,int> term2;
        term2.first = f_exp;
        term2.second = s_exp;
        polynomial5.insert(make_pair(term2, it->second));
      }
      else
      {
        polynomial5[n_term]+=it->second;
      }

    }
  }


  for (int i=0; i<=2; i++)
  {
    pair<int,int> term;
    term.first = 10*i;
    term.second = i;

    for(auto it = polynomial5.begin(); it != polynomial5.end(); it++)
    {
      auto pol_term = it->first;
      int f_exp = term.first + pol_term.first;
      int s_exp = term.second + pol_term.second;

      pair<int,int> n_term;
      n_term.first=f_exp;
      n_term.second=s_exp;

      if(polynomial10.find(n_term)==polynomial10.end())
      {
        pair<int,int> term2;
        term2.first = f_exp;
        term2.second = s_exp;
        polynomial10.insert(make_pair(term2, it->second));
      }
      else
      {
        polynomial10[n_term]+=it->second;
      }

    }
  }

  for (int i=0; i<=1; i++)
  {
    pair<int,int> term;
    term.first = 20*i;
    term.second = i;

    for(auto it = polynomial10.begin(); it != polynomial10.end(); it++)
    {
      auto pol_term = it->first;
      int f_exp = term.first + pol_term.first;
      int s_exp = term.second + pol_term.second;

      pair<int,int> n_term;
      n_term.first=f_exp;
      n_term.second=s_exp;

      if(polynomial20.find(n_term)==polynomial20.end())
      {
        pair<int,int> term2;
        term2.first = f_exp;
        term2.second = s_exp;
        polynomial20.insert(make_pair(term2, it->second));
      }
      else
      {
        polynomial20[n_term]+=it->second;
      }

    }
  }



  for(auto it = polynomial20.begin(); it != polynomial20.end(); it++)
  {
    cout<<it->second<<"x^"<<(it->first).first<<"y^"<<(it->first).second<<"\n";
  }


  cout<<"\nNumber of ways to get 25 cents with 7 coins: "<<polynomial20[make_pair(25,7)]<<"\n\n";

  int sum = 0;
  for(int i=1; i<=7; i++)
  {
    cout<<polynomial20[make_pair(25,i)]<<"x^"<<25<<"y^"<<i<<"\n";
    sum+=polynomial20[make_pair(25,i)];
  }

  cout<<"\nNumber of ways to get 25 cents with at most 7 coins: "<<sum<<'\n';


}

