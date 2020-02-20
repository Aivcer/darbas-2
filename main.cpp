#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    srand( time (NULL) );
    int n[100], k=0, r=1;   // r- papildomu mokiniu irasymui,  k- mokiniu skaicius,  n- namu darbu skaicius
    string v[100], p[100];
    double er[100], vid[100], galv[100], galm[100], med[100];
    double h;
    while( r == 1)
    {
        n[k] = 0;
        cout << "Koks jusu vardas?"<<endl;
        cin >> v[k];
        cout << "Kokia jusu pavarde?"<<endl;
        cin >> p[k];
        vector<int> C;
        int s;
        cout << "Jei norite namu darbu pazymius generuoti atsitiktinai irasykite 1, o jei vesite patys, rasykite 0" << endl;
        cin >> s;
        if ( s == 1)
        {
            n[k]=rand()%10+1;
            for (int j=0; j<n[k]; j++)
            {
                C.push_back(rand()%10+1);
            }
        }
        else
        {
        cout << "Kokie jusu namu darbu rezultatai? Nuo 1 iki 10. Kai suvesite visus, irasykite bet koki simboli, kuris nera nuo 1 iki 10"<<endl;
        for(;;)
        {
            n[k]++;
            cin >> h;
            if( h > 0 && h < 11 )
                C.push_back(h);
            else if( h < 1 || h > 10 )
            {
                n[k]--;
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
            er[k] = rand()%10+1;
        if ( s == 0 )
        {
            cout << "Koks jusu egzamino rezultatas? Nuo 1 iki 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> er[k];
            while( er[k] < 1 || er[k] > 10 )
            {
                cout << "Veskite tik skaicius nuo 1 iki 10" << endl;
                cin >> er[k];
            }
        }
        for( int i=0; i<n[k]; i++ )
            vid[k] += C[i];
        vid[k] = (double)vid[k]/n[k];
        galv[k] = 0.4*vid[k] + 0.6*er[k];
        for (int i=0; i<n[k]-1; i++)
        {
            for (int j=i+1; j<n[k]; j++)
            {
                if (C[i]>C[j])
                {
                    swap(C[i], C[j]);
                }
            }
        }
        int a, b;
        if ( n[k] % 2 == 0 )
        {
            a = n[k] / 2;
            b = n[k] / 2 - 1;
            med[k] = (C[a] + C[b]) * 1.0 / 2;
        }
        else
        {
            a = n[k] / 2;
            med[k] = C[a];
        }
        galm[k] = 0.4*med[k] + 0.6*er[k];
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
                cout << setw(19) << left << p[i] << setw(16) << v[i] << setw(5) << fixed << setprecision(2) << galv[i] << endl;
        }
        if( r == 2)
        {
            cout << "Pavarde            Vardas          Galutinis(Med.)" << endl;
            cout << "--------------------------------------------------" << endl;
            for( int i=0; i<=k; i++)
                cout << setw(19) << left << p[i] << setw(16) << v[i] << setw(5) << fixed << setprecision(2) << galm[i] << endl;
        }
    }
    return 0;
}
