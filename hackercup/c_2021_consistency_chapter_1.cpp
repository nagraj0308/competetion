#include<bits/stdc++.h>
#define INPUT_FILE "input_2021_consistency_chapter1.txt"
#define OUTPUT_FILE "output_2021_consistency_chapter1.txt"
using namespace std;

int get_majority_vowel(string s){
	vector<int> a(26,0);
	for(int i=0;i<s.size();i++){
		a[s[i]-'A']++;
	}
	int max=0;
	for(int i=0;i<26;i++){
		if(i==0||i==4||i==8||i==14||i==20)if(a[i]>a[max])max=i;
	}
	return max;
}
int get_majority_cons(string s){
	vector<int> a(26,0);
	for(int i=0;i<s.size();i++){
		a[s[i]-'A']++;
	}
	int max=1;
	for(int i=0;i<26;i++){
		if(!(i==0||i==4||i==8||i==14||i==20))if(a[i]>a[max])max=i;
	}
	return max;
}
bool is_vowel(int i){
	return (i==0||i==4||i==8||i==14||i==20);
}

int get_cons(string s){
	int mv=get_majority_vowel(s);
	int mc=get_majority_cons(s);
	
	int min_v=0;
	for(int i=0;i<s.size();i++){
		int c=s[i]-'A';
		if(is_vowel(c)&&(c!=mv)){
			min_v+=2;
		}
		if(!is_vowel(c)){ 
			min_v++; 
		}
	}
	int min_c=0;
	for(int i=0;i<s.size();i++){
		int c=s[i]-'A';
		if((!is_vowel(c))&&(c!=mc)){
			min_c+=2;
		}
		if(is_vowel(c)){ 
			min_c++; 
		}
	}

	return min_c<min_v?min_c:min_v;
}


int main(){
	int n;
	vector<string> arr;	
	ifstream infile(INPUT_FILE);
	ofstream outfile(OUTPUT_FILE);

	infile>>n;
	for(int i=0;i<n;i++){
		string a;
		infile>>a;
		arr.push_back(a);
	}

	for(int i=0;i<n;i++){
		outfile<<"Case #"<<i+1<<": "<<get_cons(arr[i])<<endl;
	}
	return 0;
}


