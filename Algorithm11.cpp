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
};
void insertion_sort(Wniosek** wnioski, int size)
{
    //sortowanie przez wstawianie
    for(int i = 1; i < size; i++){
        Wniosek* temp = wnioski[i];
        int j = i - 1;
        while(j >= 0 && Wniosek::comp(*temp, *wnioski[j])){
            wnioski[j + 1] = wnioski[j];
            j--;
        }
        wnioski[j + 1] = temp;
    }
}
Wniosek* medianFinder(Wniosek** wnioski, int size){
    if(size < 10){
        insertion_sort(wnioski, size);
        return wnioski[size / 2];
    }
    int counter = 0;
    int numOfArrays = ceil(size / 5.0);
    Wniosek **median = new Wniosek*[numOfArrays];
    Wniosek* m;
    Wniosek **temp = new Wniosek*[5];
    for (int i = 0; i < numOfArrays - 1; i+=5){
        for(int j = 0; j < 5; j++){
            temp[j] = wnioski[i + j];
        }
        insertion_sort(temp, 5);
        median[counter] = temp[2];
        counter++;
    }
    for(int j = (numOfArrays-1)*5; j < size; j++){ // laczna długość policzonych - (size) długość która została
        temp[j - (numOfArrays-1)*5] = wnioski[j];
    }
    insertion_sort(temp, size - (numOfArrays - 1) * 5);
    median[counter] = temp[(size - (numOfArrays - 1) * 5) / 2];
    counter++;
    m = medianFinder(median, counter);
    return m;
}
Wniosek* MagicFive(Wniosek** wnioski, int size, int element, Wniosek* median){
    if(size < 10){
        insertion_sort(wnioski, size);
        return wnioski[element];
    }
    int c_size = 0;
    int b_size = 0;
    int d_size = 0;
    Wniosek **B = new Wniosek*[size];
    Wniosek **D = new Wniosek*[size];
    for (int i = 0; i < size; i++)
    {
        if(Wniosek::comp(*wnioski[i], *median)){
            B[b_size] = wnioski[i];
            b_size++;
        }
        else if(Wniosek::comp(*median, *wnioski[i])){
            D[d_size] = wnioski[i];
            d_size++;
        }
        else{
            c_size++; //wystarczy znac ilosc el.
        }
    }
    if(element < b_size){//zwroc element-ty el. listy B
        delete[] D;
        return MagicFive(B, b_size, element, medianFinder(B, b_size));
    }
    else if(element >= b_size + c_size){
        delete[] B;
       return MagicFive(D, d_size, element - b_size - c_size, medianFinder(D, d_size));
    }
    else{
        delete[] D;
        delete[] B;
        return median;
    }
}
int main()
{
    int n=0; //liczba uczestnkow
    int k=0; //wylosowana przez system
    Wniosek* median;
    Wniosek* winner;
    std::cin >> n >> k;
    Wniosek** wnioski = new Wniosek*[n];
    for(int i = 0; i < n; i++){
        wnioski[i]=new Wniosek;
        std::cin >> wnioski[i]->imie >> wnioski[i]->nazwisko >> wnioski[i]->id;
    }
    median = medianFinder(wnioski, n);
    winner = MagicFive(wnioski, n, k, median);
    std::cout << winner->imie << " " << winner->nazwisko << " " << winner->id;
    return 0;
}