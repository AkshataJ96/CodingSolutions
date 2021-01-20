
#include<iostream>
#include <vector> 
#include <algorithm>

int main() {
    
    std::vector<int> matrix[1001][1001];
    int iter, x1, x2, y1, y2, c[100], max, min;
    long long int sum = 0;
    std::cin >> iter;
    for(int i = 0; i < iter; i++)
    {
        std::cin >> x1 >> y1 >> x2 >> y2 >> c[i];
        if(iter == 0){
            max = std::max({x1, y1, x2, y2});
            min = std::min({x1, y1, x2, y2});
        }
        else{
            max = std::max({x1, y1, x2, y2, max});
            min = std::min({x1, y1, x2, y2, min});
        }
        
        for(int j = x1; j <= x2; j++)
            for(int k = y1; k <= y2; k++){
                matrix[j][k].push_back(c[i]);
            }
    }

    for(int j = min; j <= max; j++){
            for(int k = min; k <= max; k++){
                if(matrix[j][k].size() > 1){
                    for (auto i = matrix[j][k].begin(); i != matrix[j][k].end(); ++i) {
                        sum += *i;
                    }
                }
            }
        
    }
    std::cout << sum ;

    return 0;

}
