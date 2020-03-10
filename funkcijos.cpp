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

double vidurkis (vector<int> A)
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

void generavimas(int q, int k)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);
    auto start = std::chrono::high_resolution_clock::now();
    ofstream fq( "stud" + to_string(k) + ".txt" );
    fq << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
    for (int i=0; i<q; i++)
        fq << setw(5) << left << ( "ND" + to_string(i+1) );
    fq << setw(5) << left << "Egz." << endl;
    for (int i=0; i<k; i++)
    {
        fq << setw(20) << left << ( "Vardas" + to_string(i+1) ) << setw(20) << ( "Pavarde" + to_string(i+1) );
        for (int j=0; j<q; j++)
            fq << setw(5) << left  << dist(mt);
        fq << setw(5) << left << dist(mt) << endl;
    }
    fq.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << k << " elementu generavimas uztruko: "<< diff.count() << " s\n";
}

void nuskaitymas(int &k, vector <duomenys> &d)
{
    auto start = std::chrono::high_resolution_clock::now();
    ifstream in( "stud" + to_string(k) + ".txt" );
    in.ignore(INT_MAX,'\n');
    d.reserve(10000000);
    double h;
    k=0;
    while( !in.eof() )
    {
        d.push_back(duomenys());
        d[k].n = 0;
        in >> d[k].v;
        in >> d[k].p;
        while ( !in.fail() )
        {
            in >> h;
            if( h > 0 && h < 11 )
            {
                d[k].C.push_back(h);
                d[k].n++;
            }
            if (in.eof()) break;
        }
        d[k].n--;
        d[k].er = d[k].C.back();
        d[k].C.pop_back();
        k++;
        if (in.eof())
        {
            in.ignore();
            break;
        }
        in.clear();
    }
    d.shrink_to_fit();
    in.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << k << " elementu nuskaitymas uztruko: "<< diff.count() << " s\n";
}

void rasymas(int k, vector <duomenys> d)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream out1("Nuskriaustukai" + to_string(k) + ".txt");
    ofstream out2("Protuoliai" + to_string(k) + ".txt");
    out1 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << left << "Galutinis" << endl;
    out2 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << left << "Galutinis" << endl;
    for( int i=0; i<k; i++)
    {
        if( 0.4* vidurkis(d[i].C) + 0.6*d[i].er < 5 ) out1 << setw(20) << left << d[i].v << setw(20) << d[i].p << setw(10) << fixed << setprecision(2) << 0.4* vidurkis(d[i].C) + 0.6*d[i].er << endl;
        if( 0.4* vidurkis(d[i].C) + 0.6*d[i].er >= 5 ) out2 << setw(20) << left << d[i].v << setw(20) << d[i].p << setw(10) << fixed << setprecision(2) << 0.4* vidurkis(d[i].C) + 0.6*d[i].er << endl;
    }
    out1.close();
    out2.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << k << " elementu rasymas uztruko: "<< diff.count() << " s\n";
}
