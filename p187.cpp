#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    map<int,string> acDetails;
    string acStr;
    while(getline(cin,acStr)){
        string aNum(acStr.begin(),acStr.begin()+3);
        string acName(acStr.begin()+3,acStr.end());
        int acNum;
        if(aNum!="000"){
            acNum= atoi(aNum.c_str());
            acDetails[acNum]=acName;
        }
        else
            break;
    }
    acDetails[999]="Out of Balance";
    string testData;
    int serialNum=0,tmpSerial;
    map<int,int>tmpDetails;
    while(getline(cin,testData)){
        stringstream ss(testData);
        string acData,amount;
        ss>>acData>>amount;
        string sl(acData.begin(),acData.begin()+3);
        string aNum(acData.begin()+3,acData.end());
        tmpSerial= atoi(sl.c_str());
        int acNum= atoi(aNum.c_str());
        if(serialNum==0){
            serialNum=tmpSerial;
        }
        if(tmpSerial != serialNum){
            if(tmpDetails[999]){
                tmpDetails[999]= -tmpDetails[999];
                printf("*** Transaction %d is out of balance ***\n",serialNum);
                for(auto it= tmpDetails.begin();it!=tmpDetails.end();it++){
                    double abal= (double)(it->second)/100.0;
                    printf("%d %-30s %10.2lf\n",it->first,acDetails[it->first].c_str(),abal);
                }
                puts("");
            }
            tmpDetails.clear();
            serialNum=tmpSerial;
            int amnt= atoi(amount.c_str());
            tmpDetails[acNum] += amnt;
            tmpDetails[999]+=amnt;
        }
        else if(sl=="000"){
            break;
        }
        else{
            int amnt= atoi(amount.c_str());
            tmpDetails[acNum]+= amnt;
            tmpDetails[999]+=amnt;
        }
    }
}
