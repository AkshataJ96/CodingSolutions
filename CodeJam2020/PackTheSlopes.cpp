#include<iostream>
#include<algorithm>
#include<vector>
#include <utility>

using namespace std;

int n;
vector<int> adj[100000];
//int ms[100000][100000], cost[100000][100000];

bool sortdes (pair<int, int> i,pair<int, int> j) { return (i.first > j.first); }
//bool sortdes (long int i,long int j) { return (i>j); }

void traverse(int i, int avail, int **ms, int **cost, int &cnt, int &tc){
    if(avail <= 0 || adj[i].size() == 0)
        return;
    vector<pair<int, int>> fm, fc;
    for(int j = 0; j < adj[i].size(); j++){
        fm.push_back(make_pair(ms[i][adj[i].at(j)], adj[i].at(j)));
        fc.push_back(make_pair(cost[i][adj[i].at(j)], adj[i].at(j)));
    }
    int current = avail;
    int coord = 0;
    sort(fm.begin(), fm.end(), sortdes);
    sort(fc.begin(), fc.end());
    for(int j = 0; j < fm.size(); j++){
        //avail = ms[i][adj[i].at(j)];
        if(current >= fm[j].first){
            if(((j+1) != fm.size())){
                if((fm[j].first == fm[j+1].first)){
                    if(fc[j] < fc[j+1]){
                        tc = tc + cost[i][adj[i].at(j)]*fm[j].first;
                        coord = fm[j].first;
                        if((adj[fc[j].second].size() != 0) && fm[j].first > 0)
                            traverse(fc[j].second, fm[j].first, ms, cost, cnt, tc);
                        else
                            cnt = cnt + fm[j].first;                        
                    }else
                    {
                        
                        tc = tc + cost[i][adj[i].at(j+1)]* fm[j+1].first;
                        coord = fm[j+1].first;
                        if((adj[fc[j+1].second].size() != 0) && fm[j+1].first > 0)
                            traverse(fc[j+1].second, fm[j+1].first, ms, cost, cnt, tc);
                        else
                            cnt = cnt + fm[j].first;  
                        
                    }
                    
                }else{
                        
                        tc = tc + cost[i][adj[i].at(j)]*fm[j].first;
                        coord = fm[j].first;
                        if((adj[fc[j].second].size() != 0) && fm[j].first > 0)
                            traverse(fc[j].second, fm[j].first, ms, cost, cnt, tc);
                        else
                            cnt = cnt + fm[j].first;  
                        
                    }
                }else{
                
                tc += cost[i][adj[i].at(j)]*fm[j].first;
                coord = fm[j].first;
                if((adj[fm[j].second].size() != 0) && fm[j].first > 0)
                    traverse(fm[j].second, fm[j].first, ms, cost, cnt, tc);
                else
                    cnt = cnt + fm[j].first;
                
            }
            current = current - coord;
        }
    }
}

int main(){
    
    int tstcase;
    cin >> tstcase;
    
    int c = 1;
    while(c <= tstcase){
        
        cin >> n;
        
        int** ms = new int*[n];
        int** cost = new int*[n];
        

        for(int i = 1; i <= n; i++){
                ms[i] = new int[n];
                cost[i] = new int[n];
        }
        
        memset(ms, 0, sizeof(ms));
        memset(cost, 0, sizeof(cost));

        int x, y, z,w;
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            cin >> z >> w;
            ms[x][y] = z;
            cost[x][y] = w;
        }
        
        int avail =0, tc = 0, cnt = 0;
        //int iniAvail; //x= 1;
        //for(int i = 1; i <= n; i++){
        //    vis[i] = 1;
            int i = 1;
            for(int x= 0; x < n; x++){
                //iniAvail  = () ? adj[i].at(x) : -1;
                if((!adj[i].empty()) && (x <= adj[i].size())){
                    cnt = cnt + ms[i][adj[i].at(x)];
                    tc = tc + cost[i][adj[i].at(x)]*ms[i][adj[i].at(x)];
                    traverse(adj[i].at(x), ms[i][adj[i].at(x)], ms, cost, cnt, tc);
                }
            }
        //}
        cout << "Case #" << c << ": " << cnt << " " << tc << endl;
        c++;
    }
    return 0;
}
