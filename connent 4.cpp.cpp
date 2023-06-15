#include <iostream>
#include<string>


using namespace std;

char16_t board[6][7];



char IsWinning(char16_t board[][7] , char tile)
{

   for(int i=0;i<6;i++)
  {
       for(int j=0;j<4;j++)
       {
           if(board[i][j]!=' ')
           if(board[i][j]==board[i][j+1])
            if(board[i][j+1]==board[i][j+2])
             if(board[i][j+2]==board[i][j+3])
         { cout<< "the winner is " <<tile<<endl;
         return tile;
             };
       }
  };


         for(int i=0;i<7;i++)
  {
       for(int j=0;j<3;j++)
       {
           if(board[j][i]!=' ')
         if(board[j][i]==board[j+1][i])
            if(board[j+1][i]==board[j+2][i])
            if(board[j+2][i]==board[j+3][i])
         { cout<< "the winner is "<<tile<<endl;
         return tile;
             };
       }
  }

  for(int i=0;i<4;i++)
  {
       for(int j=0;j<3;j++)
       {
            if(board[j][i]!=' ')
         if(board[j][i]==board[j+1][i+1])
            if(board[j+1][i+1]==board[j+2][i+2])
            if(board[j+2][i+2]==board[j+3][i+3])
         { cout<< "the winner is "<<tile<<endl;
         return tile;
             };
       }
  };

  for(int i=0;i<4;i++)
  {
       for(int j=5;j>2;j--)
       {
           if(board[j][i]!=' ')
         if(board[j][i]==board[j-1][i+1])
            if(board[j-1][i+1]==board[j-2][i+2])
            if(board[j-2][i+2]==board[j-3][i+3])
         { cout<< "the winner is "<<tile<<endl;
         return tile;
             };
       }
  };


};


bool Insert(char16_t board[][7],char tile,int column)
{
        for(int i=5;i>=0;i--)
        {
         if (board[i][column] == ' ')
           {  board[i][column]=char(tile);
              return 1;
           };
        };

        cout<< "please enter the column number again"<<endl;
            return 0;

};

void print()
{
    cout<<"0   1   2   3   4   5   6"<<endl;
     for(int i=0;i<6;i++)
   {
       for(int j=0;j<7;j++)
       {
           cout<<char( board[i][j]) <<"   ";
       }
       cout<<endl;
   };
};



int main()
{
for(int i=0;i<6;i++)
   {
       for(int j=0;j<7;j++)
       {
           board[i][j]=' ';
       }

   };
 do
{

   char tile='x',y;
   int column,z;

   cout<< "first player,enter number of column from 0 to 6"<<endl;
   cin>>column;
   z=Insert(board,tile,column);

   if(z == 0)
    {
      cin>>column;
      Insert(board,tile,column);
    };


   print();
   y=IsWinning(board,tile);
   if (y == tile)
    {return 0;};

    tile='o';
    cout<< "second player,enter number of column from 0 to 6"<<endl;
   cin>>column;
   z=Insert(board,tile,column);

   if(z == 0)
    {
      cin>>column;
      Insert(board,tile,column);
    };


   print();
  y=IsWinning(board,tile);


   if (y == tile)
    {return 0;};

} while(true);

}

