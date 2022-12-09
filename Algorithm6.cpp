#include<iostream>

using namespace std;
/*
W pierwszej linii wejścia znajduje się liczba naturalna n - liczba zespołów. W kolejnej linii znajduje się n liczb naturalnych ai, które odpowiadają liczbie dowiezionych historyjek przez i-ty zespół.

2 ≤ n ≤ 500
1 ≤ ai ≤ 106*/
/*
Na wyjściu należy wyświetlić maksymalny wynik, jaki mogą uzyskać zespoły programistów na koniec raportowania.
*/
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int max = 0;
    for(int i=0; i<n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    cout << max;
    return 0;