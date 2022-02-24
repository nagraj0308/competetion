#include<bits/stdc++.h>
#define INPUT_FILE "input_2021_Xs_and_Os.txt"
#define OUTPUT_FILE "output_2021_Xs_and_Os.txt"
using namespace std;

string result(vector<vector<char>> mat){
	char O='O',D='.',X='X';
	int d=mat.size();
	string res="";

	vector<int> dir(d,0);
	vector<bool> col(d,true);
	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++){
			if(mat[i][j]==O){
				dir[i]=d+1;
				col[j]=false;
				break;
			}else if(mat[i][j]==D){
				dir[i]++;
			}
		}
	}

	vector<int> dic(d,0);
	for(int i=0;i<d;i++){
		if(col[i]){
		for(int j=0;j<d;j++){
			if(mat[j][i]==O){
				dic[i]=d+1;
				break;
			}else if(mat[j][i]==D){
				dic[i]++;
			}
		}}else{dic[i]=d+1;}
	}
	int min_dots1=d+1;
	int time1=0;
	for(int i=0;i<d;i++){
		if(dir[i]==min_dots1){
			time1++;
		}else if(dir[i]<min_dots1){
			time1=1;
			min_dots1=dir[i];
		}
	}
	
	int min_dots2=d+1;
	int time2=0;
	for(int i=0;i<d;i++){
		if(dic[i]==min_dots2){
			time2++;
		}else if(dic[i]<min_dots2){
			time2=1;
			min_dots2=dic[i];
		}
	}
	

	if(min_dots1<min_dots2){
		res = to_string(min_dots1)+" "+to_string(time1);
	}else if(min_dots1>min_dots2){
		res = to_string(min_dots2)+" "+to_string(time2);
	}else{
		if(min_dots1==d+1){ 
			res="Impossible";
		}else{
			if(min_dots1==1){
				for(int i=0;i<d;i++){
					if(dir[i]==dic[i]&&dir[i]==1&&mat[i][i]==D)time2--;
				}
			
			}
			res = to_string(min_dots1)+" "+to_string(time1+time2);
		}
	}
	return res;
}

int main(){
	int n;
	vector<int> arr;
	vector<vector<vector<char>>> vol;	
	ifstream infile(INPUT_FILE);
	ofstream outfile(OUTPUT_FILE);

	infile>>n;
	for(int i=0;i<n;i++){
		int d;
		infile>>d;
		vector<vector<char>> mat;
		for(int i=0;i<d;i++){
			string str;
			vector<char> line;
			infile>>str;			
			for(char c:str){
				line.push_back(c);
			}
			mat.push_back(line);
		}
		arr.push_back(d);	
		vol.push_back(mat);
	}

	for(int i=0;i<n;i++){
		cout<<"Case #"<<i+1<<": "<<result(vol[i])<<endl;
	}
	return 0;
}


