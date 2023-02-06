#include<iostream>
#include<bits/stdc++.h>
class Wniosek{
public:
    std::string imie;
    std::string nazwisko;;
    unsigned int id;
    //własny komparator
    static bool comp(Wniosek &a, Wniosek &b){
        if(a.id == b.id){
            if(a.nazwisko == b.nazwisko){
                return a.imie < b.imie;
            }
            return a.nazwisko < b.nazwisko;
        }
        return a.id < b.id;
    }
    static bool comp2(Wniosek* a, Wniosek* b){
        return comp(*a, *b);
    }
};
Wniosek *medianFinder(Wniosek **wnioski, int size) {
    if (size < 10) {
        std::sort(wnioski, wnioski + size, Wniosek::comp2);
        return wnioski[size / 2];
    }
    int numOfArrays = ceil(size / 5.0);
    for (int i = 0; i < numOfArrays; i++) {
        if (i == numOfArrays - 1) {
            medianFinder(wnioski + (i * 5), size % 5);
            std::swap(wnioski[i],wnioski[(i*5) + (size % 5) / 2]);  // teraz wrzucamy mediany
            // na poczatek
        } else {
            medianFinder(wnioski + i * 5, 5);
            std::swap(wnioski[i],wnioski[(i*5) + 2]);  // teraz wrzucamy mediany na poczatek jeśli środek będzie 3 el.
        }
    }
    return medianFinder(wnioski, numOfArrays); // i tutaj zliczamy juz mediane median
}
Wniosek* MagicFive(Wniosek** wnioski, int size, int element, Wniosek* median){
    if(size < 10){
        std::sort(wnioski, wnioski + size, Wniosek::comp2);
        return wnioski[element];
    }
    int b_size = 0;
    int d_size = 0;
    int d = size - 1;
    for (int i = 0; i <= d; i++)
    {
        if(Wniosek::comp(*wnioski[i], *median)){
            std::swap(wnioski[b_size], wnioski[i]);
            b_size++;
        }
        else if(Wniosek::comp(*median, *wnioski[i])){
            std::swap(wnioski[d], wnioski[i]);
            i--; // musimy zmniejszyc poniewaz moze byc el. mniejszy od mediany
            d--;
            d_size++;
        }
    }
    if(element < b_size){
        return MagicFive(wnioski, b_size, element, medianFinder(wnioski, b_size));
    }
    else if(element >= b_size + 1){
        return MagicFive(wnioski + b_size + 1, d_size, element - b_size - 1, medianFinder(wnioski + b_size + 1, d_size)); // zamiast tablicy D
    }
    else{
        return median;
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n=0; //liczba uczestnkow
    int k=0; //wylosowana przez system
    Wniosek* median;
    Wniosek* winner;
    std::cin >> n >> k;
    Wniosek** wnioski = new Wniosek*[n];
    Wniosek* arr = new Wniosek[n];
    for(int i = 0; i < n; i++){
        //wnioski[i] = new Wniosek; //jedno oddzielne wywolanie alokacji pamieci
        wnioski[i] = arr + i; //optymalizacja z wnioski = new Wniosek[i]
        std::cin >> wnioski[i]->imie >> wnioski[i]->nazwisko >> wnioski[i]->id;
    }
    median = medianFinder(wnioski, n);
    winner = MagicFive(wnioski, n, k, median);
    std::cout << winner->imie << " " << winner->nazwisko << " " << winner->id;
    delete[] arr;
    delete[] wnioski;
    return 0;
}