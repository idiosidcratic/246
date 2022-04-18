#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*---------------------------------------------------------------------------------------*/
vector<vector<int>>page;
int t;

void insert(int s,int i)
{
    vector<int>col;
    bool flag=0;
    int k;
    if(s+4>t-4*4)
    {
        cout<<"Page size exceeded"<<endl;  //when size of input + 4 bytes is greater than the maximum 'remaining size'
        return;
    }
    for(int j=0;j<page.size();j++)
    {
        if(page[j][0]>=s)
        {
        page.at(j).push_back(i);    //input without adding pages
        page[j][0]=page[j][0]-s-4;  // subtracting 4 bytes and record size
        break;
        }
        else
        {
            flag=1; //when no space left in pages
        }
    }
    if(flag==1)
    {
        col.push_back(t-4*4-s-4);
        col.push_back(i);
        page.push_back(col); //new page added along with record and 'remaining size'
    }
}

void status()
{
    if(page[0][0]==t-4*4)
    {
    cout<<0<<endl;
    return;
    }
    else{
         cout<<page.size()<<" ";   //number of pages printed
    for(int i=0;i<page.size();i++)
    {
            cout<<page[i].size()-1<<" ";  //size of each page printed. since, first place is for remaining size, therefore "-1"
    }
    cout<<endl;
    }
}

void search(int in)
{
    int i,j;
    int k1=-1;
    int k2=-1;
    for(i=0;i<page.size();i++)
    {
        for(j=1;j<page[i].size();j++)
        {
            if(page[i][j]==in)
            {
                k1=i;
                k2=j-1;  //j=0 has 'remaining size'
                break;
            }
        }
    }
    cout<<k1<<" "<<k2<<endl;   //page number and records both indexed from 0
}


int main()
{
    cin>>t;
    int k=0;
    int size,inp;
    vector<int>col;
    col.push_back(t-4*4);
    page.push_back(col);
    while(k!=4)
    {
        cin>>k;
        if(k==1)
        {
            cin>>size>>inp;
            insert(size,inp);
        }
        if(k==2)
        {
            status();
        }
        if(k==3)
        {
            cin>>inp;
            search(inp);
        }
    }
    return 0;
}
