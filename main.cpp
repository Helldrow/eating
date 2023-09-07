#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct GameWorld{
    int rows;
    int cols;
    int* GameArray;
    char GameElements[2] = {'*', '0'};

    GameWorld(int r){
        rows = r;

        //initialize every element on the array to the space
        initialize();
        //insert the player at a random place
        insertPlayer();
    }

    //puts empty spaces int the array
    void initialize(){
        GameArray = new int[rows];
        for(int r = 0; r < rows; r++){
            GameArray[r] = 0;
        }
    }

    void insertPlayer(){
        int PositionIndex = randomNum(0, rows - 1);
        //insert player in array which is 1
        GameArray[PositionIndex] = 1;
    }


    int randomNum(int intMin, int intMax){
        int range = intMax - intMin + 1;
        int randomNumber = rand() % range + intMin;

        return randomNumber;
    }


    void movePlayer(int MOVE_POS){
        if(MOVE_POS == 0){
            //move left
                cout << "Player Pos : " << getPlayer() << endl;
                cout << "New Player Pos : " << getPlayer() - 1 << endl;
            GameArray[getPlayer() - 1] = 1;
            GameArray[getPlayer()] = 0;
        }
        if(MOVE_POS == 1){
            //move right
                cout << "Player Pos : " << getPlayer() << endl;
                cout << "New Player Pos : " << getPlayer() + 1 << endl;
            GameArray[getPlayer() + 1] = 1;
            GameArray[getPlayer()] = 0;
        }
    }

    int getPlayer(){
        int playerPos;

        for(int r = 0; r < rows; r++){
            if(GameArray[r] == 1){
                playerPos = r;
            }
        }

        return playerPos;
    }

    //print game
    void printGame(){
        for(int counterRow = 0; counterRow < rows; counterRow++){
            //print every element in the array
            int GameElement = GameArray[counterRow];
            switch(GameElement){
            case 0:
                {
                    cout << GameElements[0] << " ";
                    break;
                }
            case 1:
                {
                    cout << GameElements[1] << " ";
                }
            }
        }
        cout << endl;
    }
};


int main()
{

    //seed random
    srand(time(0));

    //create game world
    GameWorld myGame = GameWorld(15);


    //move player
    bool blnContinue = true;
    do{
        myGame.printGame();

        cout << "A: MOVE LEFT \t D: MOVE RIGHT" << endl;
        char Move = '\0';
        cin >> Move;

        switch(Move){
        case 'a':
        case 'A':
            {
                myGame.movePlayer(0);
                break;
            }
        case 'd':
        case 'D':
            {
                myGame.movePlayer(1);
                break;
            }
        }

    }while(blnContinue);




    return 0;
}
