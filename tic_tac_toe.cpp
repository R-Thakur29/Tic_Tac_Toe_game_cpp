#include<iostream>
#include<ctime>
#include<random>
using namespace std;

char board[10] = {' ','1','2','3','4','5','6','7','8','9'};
void computer_vs_player();
void player_vs_player();
void show_board();
void computer_choice();
void x_palyer_choice();
void o_palyer_choice();
int count_board(char sym);
char check_winner();
void reset_board();


int main() {
    cout<<"\t==================================================================="<<endl;
    cout<<"\t|                                                                 |"<<endl;
    cout<<"\t|                       TIC TAC TOE                               |"<<endl;
    cout<<"\t|                          GAME                                   |"<<endl;
    cout<<"\t|                                                                 |"<<endl;
    cout<<"\t==================================================================="<<endl;
    cout<<endl;
    char choice;
    int mode;
    lable1:
    cout<<"-----------------------------------------------------------------------------\n";
    cout<<"1. Computer VS Player. \n2. Player Vs Player."<<endl;
    cout<<"Select game mode : "<<endl;
    cout<<"==> ";
    cin>>mode;
    switch (mode)
    {
    case 1: 
            computer_vs_player();
            cout<<"\n\n1. Do you want to play again [y/n]?"<<endl;
            cout<<"==> ";
            cin>>choice;
            if(choice == 'y') {
                reset_board();
                cout<<endl<<endl;
                goto lable1;
            }    
            else
                return 0;
        break;

    case 2:        
            player_vs_player();
            Lable4:
            cout<<"\n\n1. Do you want to play again [y/n]?"<<endl;
            cout<<"==> ";
            cin>>choice;
             if(choice == 'y') {
                reset_board();
                cout<<endl<<endl;
                goto lable1;
            }
            else
                return 0;
        break;
    default: 
        cout<<"Please select valid game mode.\n";
        break;
    }
   
    return 0;
}

void computer_vs_player() {
    string player_name;
    cout<<"Enter Your name : ";
    cin>>player_name;
    while(true) {
        system("cls");
        cout<<player_name<<" [X]" <<endl;
        cout<<"Computer [O]"<<endl;
        show_board();
        if(count_board('X') == count_board('O')) {
            cout<<player_name<<"'s Turn."<<endl;
            x_palyer_choice();
        }
        else
            computer_choice();
        
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            cout<<player_name<<" [X]" <<endl;
            cout<<"Computer [O]"<<endl;
            show_board();
            cout<<endl;
            cout<<player_name<<" Won the game." <<endl;
            reset_board();
            break;
        }
        else if(winner == 'O') {
            system("cls");
            cout<<player_name<<" [X]" <<endl;
            cout<<"Computer [O]"<<endl;
            show_board();
            cout<<endl;
            cout<<"Computer Won the game." <<endl;
            reset_board();
            break;
        }
        else if(winner == 'D') {
            system("cls");
            cout<<player_name<<" [X]" <<endl;
            cout<<"Computer [O]"<<endl;
            show_board();
            cout<<endl;
            cout<<"Game is Draw....";
            reset_board();
            break;
        }
    }
}

void player_vs_player() {
    string x_player, o_player;
    cout<<"Enter first player name : ";
    cin>>x_player;
    cout<<"Enter second player name : ";
    cin>>o_player;
    while(true) {
        system("cls");
        cout<<x_player<<" [X]" <<endl;
        cout<<o_player<<" [O]" <<endl;
        show_board();
        if(count_board('X') == count_board('O')) {
            cout<<x_player<<"'s Turn."<<endl;
            x_palyer_choice();
        }
        else
            o_palyer_choice();
        
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout<<x_player<<" Won the game." <<endl;
            reset_board();
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout<<o_player<<" Won the game." <<endl;
            reset_board();
            break;
        }
        else if(winner == 'D') {
            cout<<"Game is Draw....";
            reset_board();
            break;
        }
    }

}

void show_board() {
    cout<<"\n";
    cout<<"\t"<<"      |      |      "<<endl;
    cout<<"\t"<<"   "<<board[1]<<"  |  "<<board[2]<<"   |  "<<board[3]<<endl;
    cout<<"\t"<<"______|______|______"<<endl;
    cout<<"\t"<<"      |      |      "<<endl;
    cout<<"\t"<<"   "<<board[4]<<"  |  "<<board[5]<<"   |  "<<board[6]<<endl;
    cout<<"\t"<<"______|______|______"<<endl;
    cout<<"\t"<<"      |      |      "<<endl;
    cout<<"\t"<<"   "<<board[7]<<"  |  "<<board[8]<<"   |  "<<board[9]<<endl;
    cout<<"\t"<<"      |      |      "<<endl;
    
}

void computer_choice() {
    srand(time(0));
    int choice;
    do {
        choice = rand()%10;
    }while (board[choice] == 'X' || board[choice] == 'O');
    board[choice] = 'O';

}

void x_palyer_choice() {
    while(true) {
        cout<<"Select your position (1 - 9) :";
        int choice;
        cin>>choice;
        if(choice < 1 || choice > 9) {
            cout<<"Please select the position between (1 - 9)."<<endl;
        }
        else if (board[choice] == 'X' || board[choice] == 'O') {
            cout<<"please select valid position.."<<endl;
        }
        else {
            board[choice] = 'X';
            break;
        }
    }   
}

void o_palyer_choice() {
    while(true) {
        cout<<"Select your position (1 - 9) :";
        int choice;
        cin>>choice;
        if(choice < 1 || choice > 9) {
            cout<<"Please select the position between (1 - 9).\n";
        }
        else if (board[choice] == 'X' || board[choice] == 'O') {
            cout<<"Please select valid position..\n";
        }
        else {
            board[choice] = 'O';
            break;
        }
    }   
}

int count_board(char sym) {
    int total = 0;
    for(int i=1; i<10; i++) {
        if(board[i] == sym) {
            total += 1;
        }
    }
    return total; 
}

char check_winner() {
    //checking horizontal
    if(board[1] == board[2] && board[2] == board[3])
        return board[1];
    if(board[4] == board[5] && board[5] == board[6])
        return board[4];
    if(board[7] == board[8] && board[8] == board[9])
        return board[7];
    
    //checking vertical
    if(board[1] == board[4] && board[4] == board[7])
        return board[1];
    if(board[2] == board[5] && board[5] == board[8])
        return board[2];
    if(board[3] == board[6] && board[6] == board[9])
        return board[3];

    //checking diagonally
    if(board[1] == board[5] && board[5] == board[9])
        return board[1];
    if(board[3] == board[5] && board[5] == board[7])
        return board[3];

    if(count_board('X') + count_board('O') < 9)
        return 'C';
    else 
        return 'D';
}

void reset_board() {
    char j = 49;
    for(int i=1; i<10; i++) {
        board[i] = j;
        j = j+1;
    }
}