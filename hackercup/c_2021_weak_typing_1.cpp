#include<bits/stdc++.h>
#define INPUT_FILE "input_2021_weak_typing_1.txt"
#define OUTPUT_FILE "output_2021_weak_typing_1.txt"
using namespace std;

int get_no_switch(string s){
	int i;
	int n=s.size();
	char x='X',f='F',o='O';
	int no=0,nx=0;

	bool ios=true;
	for(i=0;i<n;i++){
		if(s[i]==o){
			if(!ios){
				no++;
				ios=true;
			}
		}else if(s[i]==x){
			if(ios){
				no++;
				ios=false;
			}
		}	
	}
	
	bool ixs=true;
	for(i=0;i<n;i++){
		if(s[i]==x){
			if(!ixs){
				nx++;
				ixs=true;
			}
		}else if(s[i]==o){
			if(ixs){
				nx++;
				ixs=false;
			}
		}	
	}

	return no<nx?no:nx;
}


int main(){
	int n;
	vector<string> arr;		
	ifstream infile(INPUT_FILE);
	ofstream outfile(OUTPUT_FILE);

	infile>>n;
	for(int i=0;i<n;i++){
		string a;
		int k;
		infile>>k>>a;		
		arr.push_back(a);	
	}

	for(int i=0;i<n;i++){
		outfile<<"Case #"<<i+1<<": "<<get_no_switch(arr[i])<<endl;
	}
	return 0;
}


