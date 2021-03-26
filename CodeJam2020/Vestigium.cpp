#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool sortfunc (long int i,long int j) { return (i<j); }

int main(){
    
    int tstcase, n;
    vector<vector<int>> mat, crmat;
    
    cin >> tstcase;
    
    int c = 1;
    while(c <= tstcase){
    
    cin >> n;

    int x, trace = 0;
    vector<int> init;
    for(int i = 0; i < n; i++){
        for(int j=0; j < n; j++){
          cin >> x;
          init.push_back(x);
          if(i == j)
            trace = trace + x;
        }
        mat.push_back(init);
        init.clear();
    }
    cout << "mat" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;

    int row = 0; int col = 0, cnt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt = count(mat[i].begin(), mat[i].end(), mat[i][j]);
            if(cnt > 1)
                ++row;

            init.push_back(mat[j][i]);
        }
        crmat.push_back(init);
        init.clear();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt = count(crmat[i].begin(), crmat[i].end(), crmat[i][j]);
            if(cnt > 1)
                ++col;
        }
    }

    cout << "crmat" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << crmat[i][j];
        }
        cout << endl;
    }
    cout << endl;

    cout << "Case #" << c << ": " << trace << " " << row << " " << col;
	c++;
    mat.clear(); crmat.clear();
    }
    return 0;
}