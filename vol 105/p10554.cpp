#include<bits/stdc++.h>
using namespace std;
vector<string> Nutrient(5);
int rate[]={9,4,4,4,7};
void calNutrient(double *tmpFat,double *tmpTot){
    double prcnt=0,calories=0,olcal,fat;
    int unit=0;
    for(int i=0;i<5;i++){
        int lpos=Nutrient[i].size()-1;
        int quantity= atoi(Nutrient[i].c_str());
        if(Nutrient[i][lpos]=='g'){
            calories+= (quantity*rate[i]);
            if(i==0){
                fat=quantity*9;
            }

        }
        else if(Nutrient[i][lpos]=='C'){
            calories+=quantity;
            if(i==0){
                fat=quantity;
            }
        }
        else{
            prcnt+=quantity;
            if(i==0){
                unit=1;
            }
        }
    }
    olcal=calories;
    for(int i=0;i<5;i++){
        int lpos=Nutrient[i].size()-1;
        int quantity= atoi(Nutrient[i].c_str());
        if(Nutrient[i][lpos]=='%'){
            calories += (olcal*quantity)/(100-prcnt);
            if(i==0){
                fat=(olcal*quantity)/(100-prcnt);
            }
        }
    }
    *tmpFat=fat;
    *tmpTot=calories;
}
int main(){
    string line;
    while(getline(cin,line),line!="-"){
        double fatCal=0.0,totCal=0.0,tmpFat,tmpTot;
        stringstream ss(line);
        for(int i=0;i<5;i++){
            ss>>Nutrient[i];
        }
        calNutrient(&tmpFat,&tmpTot);
        fatCal+=tmpFat;
        totCal+=tmpTot;
        while(getline(cin,line),line!="-"){
            stringstream ns(line);
            for(int i=0;i<5;i++){
                ns>>Nutrient[i];
            }
            calNutrient(&tmpFat,&tmpTot);
            fatCal+=tmpFat;
            totCal+=tmpTot;
        }
        cout<< round((fatCal*100.0)/totCal) <<"%\n";
    }
}
