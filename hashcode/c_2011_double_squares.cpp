#include<bits/stdc++.h>
#define INPUT_FILE "input_2011_double_squares.txt"
#define OUTPUT_FILE "output_2011_double_squares.txt"
using namespace std;

int ds(int x){
	int c=0;
	int l=sqrt(x);
	for(int i=0;i<=l;i++){
		int s=x-i*i;
		int sr=sqrt(s);
		if((s==sr*sr) && (i<=sr)){ 
			c++;
		}		
	}
	return c;
}


int main(){
	int n;
	vector<int> arr;	
	ifstream infile(INPUT_FILE);
	ofstream outfile(OUTPUT_FILE);

	infile>>n;
	for(int i=0;i<n;i++){
		int a;
		infile>>a;
		arr.push_back(a);
	}

	for(int i=0;i<n;i++){
		outfile<<"Case #"<<i<<": "<<ds(arr[i])<<endl;
	}
	return 0;
}


