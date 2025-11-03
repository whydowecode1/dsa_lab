//upper triangular matrix

#include<iostream>
using namespace std;
int main()
{
   int n;
    cout<<"enter the number of elements :\n";
    cin>>n;
    int arr[(n*(n+1))/2];
    cout<<"enter the elements :\n";
    for(int i=0;i<(n*(n+1))/2;i++)
    {
        cin>>arr[i];
    } 
    cout<<"2d array representation :\n";
    int ar[n][n];
    int s=0;
    for(int i=0;i<n;i++)
    {
        
     
        for(int j=0;j<n;j++)
        {
        
            
            if(j>=i)
            {
                ar[i][j]=arr[s];
                cout<<ar[i][j]<<" ";
                s++;
            }
            else
            {
                ar[i][j]=0;
                cout<<ar[i][j]<<" ";
            
            }
            
        }
        
        cout<<endl;
    }
    return 0;
}