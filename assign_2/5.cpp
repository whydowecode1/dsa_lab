//diagonal
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of elements is diagonal : \n";
    cin>>n;
    int arr[n];
    cout<<"enter the diagonal elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"2d array representation :\n";
    int ar[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                ar[i][j]=arr[i];
                cout<<ar[i][j]<<" ";
            }
            else
            {
                ar[i][j]=0;
                cout<<ar[i][j]<<" ";
            }
        }
        cout << endl; 
    }
    return 0;

}