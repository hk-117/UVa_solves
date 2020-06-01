#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct team{
    string name;
    int pt=0, jitche=0, harche=0, doro=0, diche=0, khaiche=0;
    void setinp(int a, int b){
        if(a > b)   jitche++, pt += 3;
        else if(a < b)  harche++;
        else    doro++, pt++;
        diche += a, khaiche += b;
    }
    bool operator<(const team& b){
    	if(pt == b.pt){
    	    if(diche-khaiche == b.diche-b.khaiche){
    	        if(diche == b.diche){
    	            return strcasecmp(name.c_str(), b.name.c_str()) < 0;
    	        }
    	        else
    	            return diche > b.diche;
    	    }
    	    else
        	    return diche-khaiche > b.diche-b.khaiche;
    	}
    	else
    	    return pt > b.pt;
	}
};
void prnt(team &dm,int played,int rnk,bool same){
    if(same){
        if(played==0){
            printf("    %15s %3d %3d %3d %3d %3d %6s\n",dm.name.c_str(),dm.pt,played,dm.diche,dm.khaiche,(dm.diche-dm.khaiche),"N/A");
        }
        else{
            double percent=((double)dm.pt/((double)played*3.0))*100.0;
            printf("    %15s %3d %3d %3d %3d %3d %6.2f\n",dm.name.c_str(),dm.pt,played,dm.diche,dm.khaiche,(dm.diche-dm.khaiche),percent);
        }
    }
    else{
        if(played==0){
            printf("%2d. %15s %3d %3d %3d %3d %3d %6s\n",rnk,dm.name.c_str(),dm.pt,played,dm.diche,dm.khaiche,(dm.diche-dm.khaiche),"N/A");
        }
        else{
            double percent=((double)dm.pt/((double)played*3.0))*100.0;
            printf("%2d. %15s %3d %3d %3d %3d %3d %6.2f\n",rnk,dm.name.c_str(),dm.pt,played,dm.diche,dm.khaiche,(dm.diche-dm.khaiche),percent);
        }
    }
}
int main() {
    int T,G,cs=0;
    string name, buf;
    while(cin>>T>>G,T||G){
        if(cs++)
            cout<<endl;
        team A[T];
        map<string,int> R;
        R(i,0,T,1){
            cin>>A[i].name;
            R[A[i].name]=i;
        }
        getchar();
        R(i,0,G,1){
            getline(cin,buf);
            char name1[50], name2[50];
            int num1, num2;
            sscanf(buf.c_str(),"%s %d - %d %s", name1, &num1, &num2, name2);
            A[R[name1]].setinp(num1, num2);
            A[R[name2]].setinp(num2, num1);
        }
        sort(A, A+T);
        int rnk=1,actual_rnk=1;
        prnt(A[0],A[0].jitche+A[0].harche+A[0].doro,rnk,false);
        R(i,1,T,1){
            actual_rnk++;
            if(A[i-1].pt==A[i].pt && (A[i-1].diche -A[i-1].khaiche)==(A[i].diche -A[i].khaiche) && A[i-1].diche==A[i].diche){
                rnk=rnk;
                prnt(A[i],A[i].jitche+A[i].harche+A[i].doro,rnk,true);
            }
            else{
                rnk=actual_rnk;
                prnt(A[i],A[i].jitche+A[i].harche+A[i].doro,rnk,false);
            }
            
        }
    }
}

