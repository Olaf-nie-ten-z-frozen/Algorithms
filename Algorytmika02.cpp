#include<iostream>

using namespace std;

void insertionSort(unsigned int* heights, string* names, int n){
    int i, key_heights, j;
    string key_names;
    for (i = 1; i < n; i++)
    { 
        key_heights = heights[i]; 
        key_names = names[i];
        j = i - 1; 

        while (j >= 0 && heights[j] > key_heights)
        { 
            heights[j + 1] = heights[j]; 
            names[j + 1] = names[j];
            j = j - 1; 
        } 
        heights[j + 1] = key_heights;; 
        names[j + 1] = key_names;
    } 
    for (int i = 0; i < n; i++)
    {
        if(heights[i]!=0){
        cout << names[i] << "-" << heights[i] << endl;
        }
    }
    
} 
  
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    unsigned int tests; //number of test cases
    unsigned int mountains; //number of mountains
    unsigned int *heights; // array of heights
    unsigned int *heights2;
    string* names; // array of heights
    string* names2;
    string a;
    unsigned int b;
    cin >> tests;
    for(int i=0;i<tests;i++)
    {
        //cout<<"Enter the number of mountains: ";
        cin>>mountains;
        heights = new unsigned int[mountains];
        names = new string[mountains];
        heights2 = new unsigned int[mountains];
        names2 = new string[mountains];
        int powerOfTwoCounter = 0;
        int powerOfOneCounter = 0;
        for(int j=0;j<mountains;j++)
        {
            //cout<<"Enter the height of the mountain: ";
            cin >> a;
            cin >> b;
            if (b > 0 && ((b & (b - 1)) == 0)){
                heights2[j - powerOfOneCounter] = b;
                names2[j - powerOfOneCounter] = a;
                powerOfTwoCounter++;
            }
            else{
                heights[j - powerOfTwoCounter] = b;
                names[j - powerOfTwoCounter] = a;
                powerOfOneCounter++;
            }
            cin.ignore();
            cin.clear();
        }
        if(mountains>1){
            if(powerOfTwoCounter > 0){
                insertionSort(heights2, names2, mountains-powerOfOneCounter);
            }
            if(powerOfOneCounter > 0){
                insertionSort(heights, names, mountains-powerOfTwoCounter);
        }
        }
        else
        {
            cout << names[0] << "-" << heights[0] << "\n";
        }
    }
    return 0;
}