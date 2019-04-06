#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    while(cin>>str){
        if(str[0]=='#') break;
        if(next_permutation(str.begin(),str.end())!=0)
            cout<<str<<endl;
        else    cout<<"No Successor"<<endl;
    }

    return 0;
}
