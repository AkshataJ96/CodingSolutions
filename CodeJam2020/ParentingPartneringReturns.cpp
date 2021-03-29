/*
Problem statement : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9

Solution in c++
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<assert.h>

using namespace std;
bool sortfunc (long int i,long int j) { return (i<j); }
vector<pair<int, int>> tarray(1440);
vector<char> res;

int checkforval(int s, int e){
    int val;
    for(int i = s; i < e; i++){
        if(tarray[i].first != -1 && tarray[i].second != 2)
            return tarray[i].first;
    }
    return -1;
}

bool assign(int s, int e, int val, int init){
    char f; bool x = false;
    for(int i = s; i < e; i++){
        tarray[i].first = val;
        tarray[i].second = (init == 1) ? 0 : tarray[i].second + 1;
        if(tarray[i].second > 2)
            x = true;
    }
    if(val != -1 && x == false){
        f = (val == 0) ? 'J' : 'C' ;
        res.push_back(f);
    }else if(val == -1 || x == true){
        res.clear();
    }
    return x;
}

int main(){
    
    int tstcase, n;
    vector<int> start, end;
    // vector<pair<int, int>> jvp, cvp;
    int j = 0,c = 1;
    
    cin >> tstcase;
    
    int x = 1;
    while(x <= tstcase){
    bool r = assign(0, 1440, -1, 1);
    assert(r == false);
    cin >> n;
    int y,z;
    for(int i = 0; i < n; i++){
        cin >> y >> z;
        start.push_back(y);
        end.push_back(z);
    }
    int v;
    for(int i = 0; i < n; i++){
        if(i == 0){
            r = assign(start[i], end[i], 0, 0);
        }else
        {
            v = checkforval(start[i], end[i]);
            if(v == -1)
                r = assign(start[i], end[i], 0, 0);
            else if (v == 0)
            {
                r = assign(start[i], end[i], 1, 0);
            }
            else if(v == 1){
                r = assign(start[i], end[i], 0, 0);
            }
            
        }
        if(r == true)
            break; 
    }
    cout << "Case #" << x << ": " ;
    if(!res.empty()){
        for(auto i = 0; i < res.size(); i++){
            cout << res[i];
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    start.clear(); end.clear();
	x++;
    }
    return 0;
}