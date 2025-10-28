#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    int max = -99999999999;
    int maxInd = 0;
    int min = 99999999999;
    int minInd = 0;

    cout << "Enter " << n << " elements:"<< endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
         max = arr[i];
         maxInd = i;
        }

        if (arr[i] < min) {
         min = arr[i];
         minInd = i;
        }
    }

    if(maxInd != minInd) {
    cout << "Minimum value of the array is " << minInd + 1 << "th element which is " << min << endl;
    cout << "Maximum value of the array is " << maxInd + 1 << "th element which is " << max << endl;
    } else {
    cout << "There is no Maximum or Minimum in the array as there are all same elements";
    }


    return 0;
}
