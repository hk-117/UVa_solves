#include<bits/stdc++.h>

using namespace std;

bool comp(pair<string ,string> &a, pair<string , string> &b){
	if(a.second<b.second)
		return true;
	else if(a.second==b.second)
		return a.first<b.first;
	else
		return false;
}
int main(){
	string book;
	vector<pair<string,string>>stock,borrowed,returned;
	while(getline(cin,book), book !="END"){
		string name,author;
		int pos;
		pos=book.find(" by ");
		name.assign(book,0,pos);
		author.assign(book,pos+4,name.size());
		stock.push_back(make_pair(name,author));
	}
	sort(stock.begin(),stock.end(),comp);
	string command;
	while(getline(cin,command),command!="END"){
		string title;
		if(command.compare(0,6,"BORROW")==0){
			title.assign(command,7,command.size());
			auto it=stock.begin();
			while(it != stock.end()){
				if( it->first == title){
					break;
				}
				it++;
			}
			borrowed.push_back(*it);
			stock.erase(it);
		}
		else if(command.compare(0,6,"RETURN")==0){
			title.assign(command,7,command.size());
			auto it=borrowed.begin();
			while(it != borrowed.end()){
				if( it->first == title){
					break;
				}
				it++;
			}
			returned.push_back(*it);
			borrowed.erase(find(borrowed.begin(),borrowed.end(),*it));
		}
		else{
			sort(returned.begin(),returned.end(),comp);
			for(auto i=returned.begin();i!=returned.end();i++){
				stock.push_back(*i);
				sort(stock.begin(),stock.end(),comp);
				auto it=find(stock.begin(),stock.end(),*i);
				if(it==stock.begin()){
					cout<<"Put "<< i->first <<" first"<<endl;
				}
				else{
					it--;
					cout<<"Put "<< i->first <<" after "<< it->first <<endl;
				}
			}
			cout<<"END"<<endl;
			returned.clear();
		}
	}
	return 0;
}