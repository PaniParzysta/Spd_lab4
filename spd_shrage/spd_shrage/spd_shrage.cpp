// spd_shrage.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
using namespace std;

int Schrage(int N, int* R, int* P, int* Q, int* X)
{
    int t = 0, cmax = 0;
    int F[100];
    for (int i = 0; i < N; i++)
    {
        F[i] = 0;
    }
    for (int n = 0; n < N; n++)
    {
        int k = 0;
        for (int i = 0; i < N; i++)
        {
            if ((R[i] <= t) && (F[i] != 2))
            {
                F[i] = 1;
                k++;
            }
        }
        if (k == 0)
        {
            t = 999999;
            for (int i = 0; i < N; i++)
            {
                if (F[i] == 0)
                {
                    t = min(t, R[i]);
                }
            }
            for (int i = 0; i < N; i++)
            {
                if ((R[i] <= t) && (F[i] != 2))
                {
                    F[i] = 1;
                }
            }

        }
        int maxQ = -1;
        for (int i = 0; i < N; i++)
        {
            if ((F[i] == 1) && (maxQ < Q[i]))
            {
                maxQ = Q[i];
                k = i;
            }
        }
        X[n] = k;
        F[k] = 2;
        t += P[k];
        cmax = max(cmax, t + Q[k]);
    }
    return cmax;
}
int main()
{
    int N, R[100], P[100], Q[100], X[100];
    string str = "data.", str1, str2;
    ifstream f("dane.txt");

    
    for (int i = 0; i <= 8; i++)
    {
        char tab_str[4];
        snprintf(tab_str, 4, "%03d", i);
        string kolejnosc(tab_str);
        str1 = str + kolejnosc + ":";
       
        while (str2 != str1)
        {
            f >> str2;
        }
        f >> N;
        for (int i = 0; i < N; i++)
        {
            f >> R[i] >> P[i] >> Q[i];
        }
        int cmax = Schrage(N, R, P, Q, X);
        cout << str1 << " "<< cmax << endl;
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
