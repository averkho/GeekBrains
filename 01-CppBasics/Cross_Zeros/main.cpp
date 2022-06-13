#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

enum TCell : char {
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_'
};

enum TProgress {
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct TCoord {
    size_t y{ 0 };
    size_t x{ 0 };
};



void clearScr(){
    //system("cls");
    std::cout << "\x1B[2J\x1B[H";
};

int32_t getRandomNum(int32_t min, int32_t max){
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min,max);
    return dis(generator);
};

#pragma pack(push,1)

struct TGame {

    TCell** ppField{ nullptr }; // our game field
    size_t SIZE{ 3 };
    TProgress progress{ IN_PROGRESS };
    TCell human,ai;
    size_t turn{ 0 }; // shift number 
    int FIGURES;


};
#pragma pack(pop)

//#####################################################################################################################

void preGame(TGame &g){

    std::cout << "Enter the size of the field (3x3), (4x4), ...." << std::endl;
    std::cin >> g.SIZE;
    std::cout << "Enter the number of figures needed to win the game" << std::endl;
    std::cin >> g.FIGURES;

   
}

void initGame(TGame &g){

    g.ppField = new TCell * [g.SIZE];

    for (size_t i=0; i<g.SIZE; ++i){

        g.ppField[i] = new TCell[g.SIZE];
    }

    for (size_t y=0; y<g.SIZE; ++y){
        
        for (size_t x=0; x<g.SIZE; ++x){

            g.ppField[y][x]=EMPTY;
        }
    }

    if (getRandomNum(0,1000)>500){

        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    } else 
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 0;
    }

};
void drawGame(const TGame &g){

    std::cout << "      ";
    for (size_t x=0; x<g.SIZE; ++x)
    {
        std::cout << x+1 << "   ";
    }

    
    std::cout << std::endl;

    for (size_t y=0; y < g.SIZE; ++y)
    {
        std::cout << " " << y + 1 << " | ";
        
        for (size_t x=0; x < g.SIZE; ++x)
        {
            std::cout << char(g.ppField[y][x]) << " | ";
        }

        std::cout << std::endl;
    }

    std::cout << " Human: " << char(g.human) << std::endl << " Computer: " << char(g.ai) << std::endl;

};

void deinitGame(TGame &g){

    for (size_t i=0; i<g.SIZE; ++i){

        delete[] g.ppField[i];
    }
    delete[] g.ppField;

};

TProgress getWon(const TGame &g){

    // Iterating over rows of matrix

    TProgress statusHuman{ IN_PROGRESS }, statusAI{ IN_PROGRESS };

    for (size_t y = 0; y < g.SIZE; ++y)
    {   
        int row=1;

        for (size_t x = 1; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == g.ppField[y][x-1]){
                ++row;
            }
            else
            {
                row = 1;
            }

            if (row == g.FIGURES)
            {   
                
                if (g.ppField[y][x - 1] == g.human) 
                {
                    statusHuman = WON_HUMAN;
                }
                                
                if (g.ppField[y][x - 1] == g.ai) 
                {
                    statusAI = WON_AI;
                }
            }

            //std::cout << std::endl;

            
        }
    }

    
    // iterating over columns of matrix

    for (size_t x = 0; x < g.SIZE; ++x)
    {
        int row = 1;

        for (size_t y = 1; y < g.SIZE; ++y)
        {
            if (g.ppField[y][x] == g.ppField[y-1][x])
            {
                ++row;
            }
            else
            {
                row = 1;
            }

            if (row == g.FIGURES)
            {                   
                if (g.ppField[y][x] == g.human)
                {
                    statusHuman = WON_HUMAN;
                } 
                
                if (g.ppField[y][x] == g.ai)
                {
                    statusAI = WON_AI;
                } 
            }
            
        }
    }

    
    // check two diagonals

    for (size_t y = 0; y < (g.SIZE-g.FIGURES+1); ++y)
    {           

        for (size_t x = 0; x < (g.SIZE-g.FIGURES+1); ++x)
        {
            int row=1;
            size_t j=y;
            size_t i=x;
            while (g.ppField[j][i] == g.ppField[j+1][i+1] && (g.ppField[j+1][i+1] != EMPTY))
            {
                ++row;
                if (row == g.FIGURES)
                {                   
                    if (g.ppField[j][i] == g.human)
                    {
                        statusHuman = WON_HUMAN;
                    } 
                    
                    if (g.ppField[j][i] == g.ai)
                    {
                        statusAI = WON_AI;
                    } 
                }
                ++j;
                ++i;
            }   
        }
    }

    for (size_t y = 0; y < (g.SIZE - g.FIGURES + 1); ++y)
    {           

        for (size_t x = g.SIZE-1; x >= g.FIGURES; --x)
        {
            int row=1;
            size_t j=y;
            size_t i=x;
            
            while (g.ppField[j][i] == g.ppField[j + 1][i - 1] && (g.ppField[j + 1][i - 1] != EMPTY))
            {
                
                ++row;
                if (row == g.FIGURES)
                {                   
                    if (g.ppField[j][i] == g.human)
                    {
                        statusHuman = WON_HUMAN;
                    } 
                    
                    if (g.ppField[j][i] == g.ai) 
                    {
                        statusAI = WON_AI;
                    } 
                }
                ++j;
                --i;
            }   
        }
    }

    if (statusHuman == WON_HUMAN && statusAI == WON_AI)
    {
        return DRAW;
    }
    else if (statusHuman == WON_HUMAN)
    {
        return WON_HUMAN;
    }
    else if (statusAI == WON_AI)
    {
        return WON_AI;
    }
    

    bool draw{true};

    for (size_t y=0; y < g.SIZE; ++y)
    {
        for (size_t x=0; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }

        if (!draw) break;
    }

    if (draw) return DRAW;

    return IN_PROGRESS;

}

TCoord getHumanCoord(const TGame &g){

    TCoord c;
    
    do{

        std::cout << " Enter X (1...3) ";
        std::cin >> c.x;
        std::cout << " Enter Y (1...3) ";
        std::cin >> c.y;
        --c.x;
        --c.y;

        if (g.ppField[c.y][c.x] != EMPTY){
            std::cout << "Sorry the cell is not empty! Please repeat!" << std::endl;
        }
        else if (c.x > g.SIZE - 1 || c.y > g.SIZE - 1)
        {
            std::cout << "Sorry you are out of field. Please repeat!" << std::endl;
        }

    } while(c.x > (g.SIZE - 1) || c.y > (g.SIZE - 1) || g.ppField[c.y][c.x] != EMPTY);

    return c;
}

TCoord getAICoord(const TGame &g){

    // pre win situation

    for (size_t y = 0; y < g.SIZE; ++y)
    {
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y, x };
                }
                g.ppField[y][x] = EMPTY;

            }
        }

    }

    // pre fail situation

    for (size_t y = 0; y < g.SIZE; ++y)
    {
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y, x };
                }
                g.ppField[y][x] = EMPTY;

            }
        }

    }


    // in the middle

    if (g.ppField[(g.SIZE - 1) / 2][(g.SIZE - 1) / 2] == EMPTY)
    {
        return {(g.SIZE - 1) / 2,(g.SIZE - 1) / 2};
    }

    TCoord buf[4];
    size_t num{ 0 };

    // checking free corners

    if (g.ppField[0][0] == EMPTY)
    {
        buf[num]={ 0, 0 };
        ++num;
    }
    if (g.ppField[g.SIZE-1][g.SIZE-1] == EMPTY)
    {
        buf[num] = { g.SIZE - 1, g.SIZE - 1 };
        ++num;
    }
    if (g.ppField[g.SIZE - 1][0] == EMPTY)
    {
        buf[num] = { g.SIZE - 1, 0 };
        ++num;
    }
    if (g.ppField[0][g.SIZE - 1] == EMPTY)
    {
        buf[num] = { 0, g.SIZE - 1 };
        ++num;
    }
    if (num>0)
    {
        const size_t index=getRandomNum(0,1000) % num;
        return buf[index];
    }

    // checking not corners

    if (g.ppField[1][0] == EMPTY)
    {
        buf[num]={ 1, 0 };
        ++num;
    }
    if (g.ppField[1][2] == EMPTY)
    {
        buf[num] = { 1, 2 };
        ++num;
    }
    if (g.ppField[0][1] == EMPTY)
    {
        buf[num] = { 0, 1 };
        ++num;
    }
    if (g.ppField[2][1] == EMPTY)
    {
        buf[num] = { 2, 1 };
        ++num;
    }
    if (num>0)
    {
        const size_t index=getRandomNum(0,1000) % num;
        return buf[index];
    }
}

void congrats(TGame &g){

    if (g.progress == WON_HUMAN)
    {
        std::cout << "Won human! =)" << std::endl;
    }
    else if (g.progress == WON_AI)
    {
        std::cout << "Won computer! =(" << std::endl;
    }
    else 
    {
        std::cout << "Draw! =/" << std::endl;
    }
};

//####################################################################################################################

int main(){

    TGame g;
    preGame(g);
    initGame(g);
    drawGame(g);
    g.progress == IN_PROGRESS;

    do{
        if (g.turn %2 ==0)
        {
            TCoord c = getHumanCoord(g); // human turn
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {
            TCoord c = getAICoord(g); // ai turn
            g.ppField[c.y][c.x] = g.ai;
        }

        clearScr();
        drawGame(g);
        ++g.turn;
        g.progress = getWon(g);

        std::cout << " progress " << g.progress << std::endl;

    } while (g.progress == IN_PROGRESS);

    congrats(g);

    deinitGame(g);

    return 0;
}