#include<iostream>
#include<time.h>
using namespace std;

int counter = 0;

int Partition(int arr[], int p, int r){
    int x = arr[r];
    int i = (p-1);
    
    for(int j=p; j<=r-1; j++){
        counter++;
        if(arr[j] <= x){
            i++;

            // Swap the value of arr[i] with arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // Swap the value of arr[i+1] with arr[r]
    swap(arr[i+1], arr[r]);
    return i+1;
}

int Randomized_Partition(int arr[], int p, int r){
    // Generate Random Number between p to r
    srand(time(0));
    int i = p + rand() % (r - p);

    // Swap the value of arr[i] with arr[r]
    swap(arr[i], arr[r]);
    return (Partition(arr,p,r));
}

void Randomized_Quick_Sort(int arr[], int p, int r){
    if(p < r){
        int q = Randomized_Partition(arr,p,r);
        Randomized_Quick_Sort(arr,p,(q-1));
        Randomized_Quick_Sort(arr,(q+1),r);
    }
}

int main(){
    int sorted_arr[] = {10, 20, 30, 40, 50};
    int n1 = 5;

    cout << "For Sorted Input: " << endl;

    cout << "\t\tOriginal Array: ";
    for(int i=0; i<n1; i++){
        cout << sorted_arr[i] << " ";
    }

    Randomized_Quick_Sort(sorted_arr, 0, (n1-1));

    cout << "\n\t\tSorted Array: ";
    for(int i=0; i<n1; i++){
        cout << sorted_arr[i] << " ";
    }

    cout << "\nNumber of Comparison: " << counter;

    cout << "\n\n";

    counter = 0;

    int reversed_arr[] = {50, 40, 30, 20, 10};
    int n2 = 5;

    cout << "For Reversed Input: " << endl;
    
    cout << "\t\tOriginal Array: ";
    for(int i=0; i<n2; i++){
        cout << reversed_arr[i] << " ";
    }

    Randomized_Quick_Sort(reversed_arr, 0, (n2-1));

    cout << "\n\t\tSorted Array: ";
    for(int i=0; i<n2; i++){
        cout << reversed_arr[i] << " ";
    }

    cout << "\nNumber of Comparison: " << counter;

    cout << "\n\n";

    counter = 0;

    int random_arr[] = {20, 30, 10, 50, 40};
    int n3 = 5;

    cout << "For Random Input: " << endl;
    
    cout << "\t\tOriginal Array: ";
    for(int i=0; i<n3; i++){
        cout << random_arr[i] << " ";
    }

    Randomized_Quick_Sort(random_arr, 0, (n3-1));

    cout << "\n\t\tSorted Array: ";
    for(int i=0; i<n3; i++){
        cout << random_arr[i] << " ";
    }

    cout << "\nNumber of Comparison: " << counter;

    return 0;
}