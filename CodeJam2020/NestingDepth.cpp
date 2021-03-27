/*
Problem statement : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f

Solution in c++
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <cstdlib>
#include<assert.h>

using namespace std;
bool sortfunc (long int i,long int j) { return (i<j); }

int main(){
    
    int tstcase, len;
    string instr, out;
    cin >> tstcase;
    vector<char> inv;
    
    int c = 1;
    while(c <= tstcase){
    cin >> instr;

    inv.clear();
    for(int i = 0; i < instr.length(); i++){
        inv.push_back(instr[i]);
    }

    int lenv, pcnts = 0, pcnte = 0;
    vector<char> outv;
    for(auto i = 0; i < inv.size(); i++){
        outv.push_back(inv[i]);
        lenv = outv.size();
        pcnts = count(outv.begin(), outv.begin() + lenv, '(');
        pcnte = count(outv.begin(), outv.begin() + lenv, ')');
        if( (pcnts - pcnte) >(int(inv[i]) - 48)){
            //close();
            for(int j = 0; j < (pcnts - pcnte - int(inv[i]) + 48); j++){
                outv.insert(outv.begin() + lenv - 1, ')');
            }
        }
        else if( (pcnts- pcnte) < (int(inv[i]) - 48)){
            //open();
            for(int j = 0; j < (int(inv[i]) - 48 - pcnts + pcnte); j++){
                outv.insert(outv.begin() + lenv - 1, '(');
            }
        }        
    }

    
    //Include remaining close paramthesis
    lenv = outv.size();
    pcnts = count(outv.begin(), outv.end(), '(');
    pcnte = count(outv.begin(), outv.end(), ')');
    _ASSERT(pcnte <= pcnts);
    if(pcnts > pcnte)
        for(int j = 0; j < (pcnts - pcnte); j++){
            outv.insert(outv.begin() + lenv, ')');
        }

    cout << "Case #" << c << ": ";
    for(int i = 0; i < outv.size(); i++){
        cout << outv[i];
    }
    cout << endl;
    
	c++;
    }
    return 0;
}