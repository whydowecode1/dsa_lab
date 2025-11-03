//triagonal
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of elements :\n";
    cin>>n;
    int arr[3*n-2];
    cout<<"enter the elements :\n";
    for(int i=0;i<(3*n-2);i++)
    {
        cin>>arr[i];
    }

cout<<"2d array representation: \n";
int ar[n][n];
int k=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(i-j==-1||i-j==0||i-j==1)
        {
            ar[i][j]=arr[k++];
            cout<<ar[i][j]<<" ";
        }
        else
        {
            ar[i][j]=0;
            cout<<ar[i][j]<<" ";
        }
        
    }
    cout<<endl;
}
}

