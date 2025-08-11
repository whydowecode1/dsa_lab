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
question 7-

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
    for(int i=0;i<=n-1;i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp =arr[j];
            
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            count++;
        }
    }
    cout<<"the number of unique elements:\n"<<count;
    return 0;
}

question 2
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

    cout<<"the sorted array is:\n";
    for(int i=0;i<=n-1;i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp =arr[j];
            
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        cout<<endl;
    }

    cout<<"array after deletion of duplicate elements:\n";
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            for(int j=i;j<n-1;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
            i--;
        }
       
    
    }
     for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        cout<<endl;
    }
    return 0;
}
