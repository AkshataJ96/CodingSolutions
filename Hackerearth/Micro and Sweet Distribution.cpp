/*
if row even 
   sx,sy == 1,1 or row,1 , flag = 100
   sx,sy == 1,c or r,c , flag = 200
else
    sx,sy == 1,1 or r,c , flag = 300
   sx,sy == 1,c or r,1 , flag = 400

*/
#include<iostream>

int main() {
    
    //int seats[1001][1001];
    int iter, sx, sy, dx, dy, row, chair;
    std::cin >> iter;
    for(int i = 0; i < iter; i++)
    {
        std::cin >> row >> chair;
        int seats[row][chair];

        std::cin >> sx >> sy >> dx >> dy;

        if(sx == 1 && sy == 1){
            if(dx % 2 == 1){
                if(dy == chair)
                    if(dx == row)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Back" << std::endl;
                else
                    std::cout << "Right" << std::endl;
            }
            else{
                if(dy == 1)
                    if(dx == row)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Back" << std::endl;
                else
                    std::cout << "Left" << std::endl;
            }
        }

        if(sx == 1 && sy == chair){
            if(dx % 2 == 1){
                if(dy == 1)
                    if(dx == row)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Back" << std::endl;
                else
                    std::cout << "Left" << std::endl;
            }
            else{
                if(dy == chair)
                    if(dx == row)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Back" << std::endl;
                else
                    std::cout << "Right" << std::endl;
            }
        }

        if(sx == row && sy == 1){
            if((row - dx + 1) % 2 == 1){
                if(dy == chair)
                    if(dx == 1)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Front" << std::endl;
                else
                    std::cout << "Right" << std::endl;
            }
            else{
                if(dy == 1)
                    if(dx == 1)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Front" << std::endl;
                else
                    std::cout << "Left" << std::endl;
            }
        }

        if(sx == row && sy == chair){
            if((row - dx + 1) % 2 == 1){
                if(dy == 1)
                    if(dx == 1)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Front" << std::endl;
                else
                    std::cout << "Left" << std::endl;
            }
            else{
                if(dy == chair)
                    if(dx == 1)
                        std::cout << "Over" << std::endl;
                    else
                        std::cout << "Front" << std::endl;
                else
                    std::cout << "Right" << std::endl;
            }
        }
    }

    return 0;

}