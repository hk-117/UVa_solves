#include<bits/stdc++.h>
using namespace std;
int hashVal[150];
map<string,bool> X;
map<string,string> Y;
vector<string> Z;
void hashFunc(){
    char T[8][5]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    int i,j,len;
    for(i=0;i<8;i++){
        len=strlen(T[i]);
        for(j=0;j<len;j++){
            hashVal[T[i][j]]=i+2;
            hashVal[tolower(T[i][j])]=i+2;
        }
    }
}
void printSol(string line){
    if(X.find(line) != X.end())
        cout<<line<<"\n";
    else{
        int soln=0;
        for(int i=0;i<Z.size();i++){
            if(Z[i].find(line)==0){
                if(soln)
                    cout<<" ";
                cout<< Y[Z[i]];
                soln++;
            }
        }
        if(!soln)
            cout<<"0";
        cout<<"\n";
    }
}
int main(){
    string line;
    hashFunc();
    while(getline(cin,line)){
        if(isdigit(line[0]))
            break;
        string hs,fname,lname,ext;
        stringstream ss(line);
        ss>>fname>>lname>>ext;
        hs+= hashVal[fname[0]]+'0';
        for(int i=0;i<lname.size();i++)
            hs+= hashVal[lname[i]]+'0';
        hs+='|';
        X[ext]=true;
        Y[hs+ext]=ext;
        Z.push_back(hs+ext);
    }
    printSol(line);
    while(getline(cin,line)){
        printSol(line);
    }
}
