#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <time.h>

using namespace std;

struct duomenys
{
    string v; // vardas
    string p; // pavarde
    double *C; // namu darbu pazymiu vektorius
    double er; // egzamino rezultatas
    double vid; // vidurkis namu darbu
    double galv; // galutinis pazymys su vidurkiais
    double galm; // galutinis pazymys su mediana
    double med; // mediana
    int n; // namu darbu sk
};

int main()
{
    duomenys d[1000];
    srand( time (NULL) );
    int k=0, r=1;   // r- papildomu mokiniu irasymui,  k- mokiniu skaicius
    while( r == 1)
    {
        d[k].n = 0;
        cout << "Koks mokinio vardas?"<<endl;
        cin >> d[k].v;
        cout << "Kokia mokinio pavarde?"<<endl;
        cin >> d[k].p;
        int s;
        cout << "Jei norite namu darbu pazymius generuoti atsitiktinai irasykite 1, o jei vesite patys, rasykite 0" << endl;
        for(;;)
        {
            cin >> s;
            if( s == 1 || s == 0) break;
            else cout << "Irasykite tik 1 arba 0" << endl;
        }
        if ( s == 1)
        {
            d[k].n=rand()%10+1;
            delete[] d[k].C;
            d[k].C = new double [d[k].n+1];
            for(int j=0; j<d[k].n; j++)
                d[k].C[j]=rand()%10+1;
        }
        else if ( s == 0 )
        {
        cout << "Kokie jusu namu darbu rezultatai? Nuo 1 iki 10. Kai suvesite visus, irasykite bet koki simboli, kuris nera nuo 1 iki 10"<<endl;
        for(;;)
        {
            double *t;
            t = new double [d[k].n+1];
            cin >> t[d[k].n];
            if( t[d[k].n] > 0 && t[d[k].n] < 11 )
            {
                for(int i=0; i<d[k].n; i++)
                    t[i] = d[k].C[i];
                delete[] d[k].C;
                d[k].C = new double [d[k].n+1];
                for(int i=0; i<=d[k].n; i++)
                    d[k].C[i] = t[i];
                delete[] t;
                d[k].n++;
            }
            else if( t[d[k].n] < 1 || t[d[k].n] > 10 )
            {
                int x;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Turit vesti tik skaicius nuo 1 iki 10, ar noresit pridet kita pazymi? Jei taip, veskite 1, jei ne - 0" << endl;
                cin >> x;
                if( x == 1)
                    cout << "Veskite tik skaicius nuo 1 iki 10" << endl;
                else if( x == 0) break;
                else cout << "Ar noresit pridet kita pazymi? Jei taip, veskite 1, jei ne - 0" << endl;
            }
        }
        }
        cout << "Jei norite egzamino pazymi generuoti atsitiktinai irasykite 1, o jei vesite patys, rasykite 0" << endl;
        for(;;)
        {
            cin >> s;
            if( s == 1 || s == 0) break;
            else cout << "Irasykite tik 1 arba 0" << endl;

        }
        if ( s == 1 )
            d[k].er = rand()%10+1;
        if ( s == 0 )
        {
            cout << "Koks jusu egzamino rezultatas? Nuo 1 iki 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> d[k].er;
            while( d[k].er < 1 || d[k].er > 10 )
            {
                cout << "Veskite tik skaicius nuo 1 iki 10" << endl;
                cin >> d[k].er;
            }
        }
        for( int i=0; i<d[k].n; i++ )
            d[k].vid += d[k].C[i];
        d[k].vid = (double)d[k].vid/d[k].n;
        d[k].galv = 0.4*d[k].vid + 0.6*d[k].er;
        for (int i=0; i<d[k].n-1; i++)
        {
            for (int j=i+1; j<d[k].n; j++)
            {
                if (d[k].C[i]>d[k].C[j])
                {
                    swap(d[k].C[i], d[k].C[j]);
                }
            }
        }
        int a, b;
        if ( d[k].n % 2 == 0 )
        {
            a = d[k].n / 2;
            b = d[k].n / 2 - 1;
            d[k].med = (d[k].C[a] + d[k].C[b]) * 1.0 / 2;
        }
        else
        {
            a = d[k].n / 2;
            d[k].med = d[k].C[a];
        }
        d[k].galm = 0.4*d[k].med + 0.6*d[k].er;
        cout << "Ar norite prideti dar mokiniu? Irasykite 1, kad pridet, 0, jei tai paskutinis mokinys" << endl;
        cin >> r;
        if( r == 1)
        {
            k++;
        }
    }
    if ( r == 0)
    {
        cout << "Jei norite naudoti vidurki galutinio balo apskaiciavimui irasykite 1. Jei norite naudoti mediana irasykite 2" <<endl;
        cin >> r;
        if( r == 1)
        {
            cout << "Pavarde            Vardas          Galutinis(Vid.)" << endl;
            cout << "--------------------------------------------------" << endl;
            for( int i=0; i<=k; i++)
                cout << setw(19) << left << d[i].p << setw(16) << d[i].v << setw(5) << fixed << setprecision(2) << d[i].galv << endl;
        }
        if( r == 2)
        {
            cout << "Pavarde            Vardas          Galutinis(Med.)" << endl;
            cout << "--------------------------------------------------" << endl;
            for( int i=0; i<=k; i++)
                cout << setw(19) << left << d[i].p << setw(16) << d[i].v << setw(5) << fixed << setprecision(2) << d[i].galm << endl;
        }
    }
    return 0;
}
