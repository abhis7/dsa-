#include <iostream>
using namespace std;

bool isPresent(int arr[][3], int target, int i, int j)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    // takiing input
    //  for (int i=0; i<2; i++){
    //      for (int j=0; j<3; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // print
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //linear search in 2d array 
    int target;
    cout << "enter target element" << endl;
    cin >> target;

   if(isPresent(arr ,target ,2,3)){
    cout<<"found"<<endl;
   } 
   else{
    cout<<"not found"<<endl;
   }
}