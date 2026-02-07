#include<iostream>
using namespace std;

char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int i,j;

void print()
{
    cout<<"Player 1 plays first (X)"<<endl;
    cout<<"Player 2 plays second (O)"<<endl<<endl;
    cout<<"    |    |    "<<endl;
    cout<<"  "<<arr[0][0]<<" | "<<arr[0][1]<<"  | "<<arr[0][2]<<" "<<endl;
    cout<<"____|____|____"<<endl;
    cout<<"    |    |    "<<endl;
    cout<<"  "<<arr[1][0]<<" | "<<arr[1][1]<<"  | "<<arr[1][2]<<" "<<endl;
    cout<<"____|____|____"<<endl;
    cout<<"    |    |    "<<endl;
    cout<<"  "<<arr[2][0]<<" | "<<arr[2][1]<<"  | "<<arr[2][2]<<" "<<endl;
    cout<<"    |    |    "<<endl<<endl;
}

char check()
{
    for(i=0;i<3;i++)
        if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2])
            return arr[i][0];
    for(i=0;i<3;i++)
        if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i])
            return arr[0][i];
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2])
        return arr[0][0];
    if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
        return arr[0][2];
    
    return ' ';
}

bool call(int player)
{
    int a,b;
    char sign;
    if(player == 1)
        sign = 'X';
    else
        sign = 'O';
    while(true)
    {
        cout<<"Player "<<player<<" ("<<sign<<"): Enter the row (0-2) and column (0-2) number: ";
        cin>>a>>b;
        
        if(a<0 || a>2 || b<0 || b>2)
        {
            cout<<"Invalid position! Please enter values between 0 and 2."<<endl;
            continue;
        }
        
        if(arr[a][b]=='X' || arr[a][b]=='O')
        {
            cout<<"Position already occupied! Try again."<<endl;
            continue;
        }
        
        arr[a][b] = sign;
        break;
    }
    
    print();
    
    char winner = check();
    if(winner != ' ')
    {
        cout<<"Player "<<(winner=='X'?1:2)<<" wins!"<<endl;
        return true;
    }
    
    return false;
}

int main()
{
    int moves = 0;
    bool gameWon = false;
    
    print();
    
    for(moves=0; moves<9; moves++)
    {
        gameWon = call(moves%2 + 1);
        if(gameWon) break;
    }
    
    if(!gameWon && moves == 9)
        cout<<"It's a draw!"<<endl;
    
    return 0;
}