#include "struktura.h
#include "funkcijos.h"

double mediana (vector<int> X)
{
  int a, b;
  sort(X.begin(), X.end());
  if (X.size()%2==0)
  {
    a=X.size()/2;
    b=X.size()/2-1;
    return (X[a]+X[b])*1.0/2;
  }
  else
  {
    a=X.size()/2;
    return X[a];
  }
}

double vidurkis (const vector<int> A)
{
  int visi=0;
  for(int i=0; i<A.size(); i++)
  {
    visi+=A[i];
  }
  return visi*1.0/A.size();
}

bool rusiavimasV(const duomenys &a, const duomenys &b)
{
    return a.v < b.v;
}

bool rusiavimasP(const duomenys &a, const duomenys &b)
{
    return a.p < b.p;
}
