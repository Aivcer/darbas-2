#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

struct duomenys
{
    string v; // vardas
    string p; // pavarde
    vector<int> C; // namu darbu pazymiu vektorius
    int er; // egzamino rezultatas
    double visi; //visu pazymiu suma
    //double galv; // galutinis pazymys su vidurkiais
    //double galm; // galutinis pazymys su mediana
    int n; // namu darbu sk

};

double mediana (vector<int> X);
double vidurkis (vector<int> A);
bool rusiavimasV(const duomenys &a, const duomenys &b);
bool rusiavimasP(const duomenys &a, const duomenys &b);
void generavimas(int q, int k);
void nuskaitymas(int &k, vector <duomenys> &d);
void rasymas(int k, vector <duomenys> &d);
void rusiavimas(int k, vector <duomenys> &d);

#endif // FUNKCIJOS_H
