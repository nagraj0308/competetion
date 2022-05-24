#include<bits/stdc++.h>
using namespace std;

#define ll long long

class project{
    public:
    string name;
    ll D;
    ll S;
    ll B;
    ll R;
};

class contributors{
    public:
    string name;
    ll numberofskills;
    vector<pair<string,ll>> vect;
};

int anExpert(string name,vector<pair<string,vector<pair<string,ll>> > > &arr,int compare){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].second.size();j++){
            if(arr[i].second[j].first==name && arr[i].second[j].second>=compare)
                // cout<<arr[i].second[j].first<<' '<<arr[i].second[j].second<<'\n';
                return 1;
        }
    }
    return 0;
}

int main(){
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");

    ll c;//Number of contributors
    ll p;//number of projects

    in>>c>>p;

    vector<pair<string,vector<pair<string,ll>> > > arr;
    for(int i=0;i<c;i++){
        string temp;
        in>>temp;
        ll n;
        in>>n;
        vector<pair<string,ll> > tt;
        for(int j=0;j<n;j++){
            string surf;
            in>>surf;
            ll ass;
            in>>ass;
            tt.push_back({surf,ass});
        }
        arr.push_back({temp,tt});
    }

    vector<vector<pair<string,ll> > > matrix;

    vector<project> v(p);
    for(int i=0;i<p;i++){
        in>>v[i].name>>v[i].D>>v[i].S>>v[i].B;
        in>>v[i].R;
        vector<pair<string,ll>> temp(v[i].R);
        for(int j=0;j<v[i].R;j++){
            in>>temp[j].first>>temp[j].second;
        }
        // v[i].vect=temp;
        matrix.push_back(temp);
    }
    vector<pair<ll,vector<string> > > anscollector;
    for(int i=0;i<matrix.size();i++){
        int cnt=0;
        vector<string> hel;unordered_map<string,int> used;
        for(int j=0;j<matrix[i].size();j++){
            
            bool flag=0;int mi=INT_MAX;
            for(int k=0;k<arr.size();k++){
               for(int l=0;l<arr[k].second.size();l++){
                 
                   if(matrix[i][j].first==arr[k].second[l].first && matrix[i][j].second<=arr[k].second[l].second && used.find(arr[k].first)==used.end()){
                    //    cout<<arr[k].second[l].first<<' '<<matrix[i][j].first<<' '<<matrix[i][j].second<<' '<<arr[k].second[l].second<<'\n';
                        int u=arr[k].second[l].second;
                        if(u<mi){
                            
                        }
                       cnt++;
                       flag=1;
                       used[arr[k].first]++;
                       hel.push_back(arr[k].first);
                       break;
                   }
                //    else if(matrix[i][j].first==arr[k].second[l].first && matrix[i][j].second==(arr[k].second[l].second+1) && anExpert(matrix[i][j].first,arr,matrix[i][j].second) && used.find(arr[k].first)==used.end()){
                //         cnt++;
                //         flag=1;
                //         used[arr[k].first]++;
                //         hel.push_back(arr[k].first);
                //         arr[k].second[l].second+=1;
                //         break;
                //    }  //Misinterpreted

               }
                if(flag)
                    break;
            }
        }
        if(cnt==matrix[i].size()){
            anscollector.push_back({i,hel});
        }
    }

    out<<anscollector.size()<<'\n';

    for(auto x:anscollector){
        out<<v[x.first].name<<'\n';
        // set<string> gg;
        for(auto y:x.second){
            out<<y<<' ';
        }
        // for(auto y:gg)
            // out<<y<<' ';
        out<<'\n';
    }
    return 0;
}