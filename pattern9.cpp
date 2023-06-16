#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int row=1;
     int count =0;
    while(row<=n){
        int col =1;
      
      //  char ch='A'+col-1;
       
        while(col<=n){
            char ch='A'+count ;
            cout<<ch;
            col=col+1;
            count=count+1;
        }
        cout<<endl;
        row=row+1;
    }
    return 0;
}
