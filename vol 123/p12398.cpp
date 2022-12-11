#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define Z(it,seq,i) for(auto it=seq.begin();it !=seq.end();it +=i)
using namespace std;
void change(vector< vector<int> > &grid,int row, int col){
   if(row==0 && col==0){
       grid[0][0]=(grid[0][0]+1)%10;
       grid[0][1]=(grid[0][1]+1)%10;
       grid[1][0]=(grid[1][0]+1)%10;
   }
   else if(row ==0 && col ==1){
       grid[0][1]=(grid[0][1]+1)%10;
       grid[0][0]=(grid[0][0]+1)%10;
       grid[1][1]=(grid[1][1]+1)%10;
       grid[0][2]=(grid[0][2]+1)%10;
   }
   else if(row ==0 && col ==2){
       grid[0][2]=(grid[0][2]+1)%10;
       grid[0][1]=(grid[0][1]+1)%10;
       grid[1][2]=(grid[1][2]+1)%10;
   }
   else if(row ==1 && col ==0){
       grid[1][0]=(grid[1][0]+1)%10;
       grid[0][0]=(grid[0][0]+1)%10;
       grid[1][1]=(grid[1][1]+1)%10;
       grid[2][0]=(grid[2][0]+1)%10;
   }
   else if(row ==1 && col ==1){
       grid[1][1]=(grid[1][1]+1)%10;
       grid[0][1]=(grid[0][1]+1)%10;
       grid[1][0]=(grid[1][0]+1)%10;
       grid[1][2]=(grid[1][2]+1)%10;
       grid[2][1]=(grid[2][1]+1)%10;
   }
   else if(row ==1 && col ==2){
       grid[1][2]=(grid[1][2]+1)%10;
       grid[0][2]=(grid[0][2]+1)%10;
       grid[1][1]=(grid[1][1]+1)%10;
       grid[2][2]=(grid[2][2]+1)%10;
   }
   else if(row ==2 && col ==0){
       grid[2][0]=(grid[2][0]+1)%10;
       grid[1][0]=(grid[1][0]+1)%10;
       grid[2][1]=(grid[2][1]+1)%10;
   }
   else if(row ==2 && col ==1){
       grid[2][1]=(grid[2][1]+1)%10;
       grid[2][0]=(grid[2][0]+1)%10;
       grid[1][1]=(grid[1][1]+1)%10;
       grid[2][2]=(grid[2][2]+1)%10;
   }
   else{
       grid[2][2]=(grid[2][2]+1)%10;
       grid[2][1]=(grid[2][1]+1)%10;
       grid[1][2]=(grid[1][2]+1)%10;
   }
}
int main(){
    string sequences;
    int cs=0;
    while(getline(cin,sequences)){
        cs++;
        reverse(sequences.begin(),sequences.end());
        vector< vector<int> > grid(3,vector<int>(3));
        Z(it,sequences,1){
            int total_pos = *it - 'a' + 1;
            int row= total_pos/3,col=total_pos %3;
            if(col==0){
                row -= 1;
                col = 2;
            }
            else{
                col -= 1;
            }
            change(grid,row,col);
        }
        cout<<"Case #"<<cs<<":\n";
        R(i,0,3,1){
            R(j,0,3,1){
                cout<< grid[i][j];
                if(j != 2)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
}
