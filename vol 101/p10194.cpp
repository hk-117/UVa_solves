#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct team{
    string name;
    int pt=0, win=0, lose=0, tie=0, score=0, invscore=0;
    void setinp(int a, int b){
        if(a > b)   win++, pt += 3;
        else if(a < b)  lose++;
        else    tie++, pt++;
        score += a, invscore += b;
    }
    bool operator<(const team& b) {
    	if(pt != b.pt)    return pt > b.pt;
    	if(win != b.win)  return win > b.win;
    	if(score-invscore != b.score-b.invscore)
    	    return score-invscore > b.score-b.invscore;
    	if(score != b.score)
    	    return score > b.score;
    	if(win+lose+tie != b.win+b.lose+b.tie)
    	    return win+lose+tie < b.win+b.lose+b.tie;
    	return strcasecmp(name.c_str(), b.name.c_str()) < 0;
	}
};
int main() {
    scanf("%*d ");
    int n, m, cases = 0;
    string name, buf;
    while(getline(cin,name)){
        scanf("%d", &n);
        getchar();
        map<string, int> R;
        if(cases++) cout<<"\n";
        cout<<name<<"\n";
        team A[50];
        R(i,0,n,1){
            getline(cin,A[i].name);
            R[A[i].name] = i;
        }
        scanf("%d", &m);
        getchar();
        while(m--) {
            getline(cin,buf);
            char name1[50], name2[50];
            int num1, num2;
            sscanf(buf.c_str(),"%[^#]#%d@%d#%[^\n]", name1, &num1, &num2, name2);
            A[R[name1]].setinp(num1, num2);
            A[R[name2]].setinp(num2, num1);
        }
        sort(A, A+n);
        R(i,0,n,1){
            cout<< i+1 <<") "<< A[i].name <<" "<<A[i].pt<<"p, "<<A[i].win+A[i].lose+A[i].tie<<"g ("<<A[i].win<<"-"<<A[i].tie<<"-"<<A[i].lose<<"), "<<A[i].score-A[i].invscore<<"gd ("<<A[i].score<<"-"<<A[i].invscore<<")"<<endl;
        }
    }
    return 0;
}

