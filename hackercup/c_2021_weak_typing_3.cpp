#include<bits/stdc++.h>
#define INPUT_FILE "input_2021_weak_typing_3.txt"
#define OUTPUT_FILE "output_2021_weak_typing_3.txt"
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

int sub_string(string s){
	int n=s.size();
	unsigned long long int ans=0;
 	for (int i = 0; i < n; i++){
        	char temp[n - i + 1];
        	int tempindex = 0;
        	for (int j = i; j < n; j++){
            		temp[tempindex++] = s[j];
            		temp[tempindex] = '\0';
			ans+=get_no_switch(temp);
        	}
    	}
	return ans % 1000000007;
}

string make_string(string s){
	string ans="";
	int n =s.size();
	for(int i=0;i<n;i++){
		if(s[i]!='.'){
			ans=ans+s[i];
		}else{
			ans=ans+ans;
		} 
	}
	return ans;
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
		outfile<<"Case #"<<i+1<<": "<<sub_string(make_string(arr[i]))<<endl;
	}
	return 0;
}


