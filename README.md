# dsa_lab
#include<iostream>
using namespace std;
int main()
{
    int n;
    
    cout<<"enter the number of elements:\n";
    cin>>n;
    int arr[n];
    cout<<"enter the element:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cout<<endl;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
    
        for(int j=0;j<n;j++)
        {
        if(i<j && arr[i]>arr[j])
        {
            count++;
        }
        }
    }
    cout<<"the number of inversions are:\n"<<count;
    return 0;
}
