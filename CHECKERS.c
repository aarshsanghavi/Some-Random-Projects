#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
#define float long double
#define in2(x,y);  long long x,y; cin>>x>>y;
#define in3(x,y,z);  long long x,y,z; cin>>x>>y>>z;
#define fi(a,n) for(int i=a;i<n;i++)
#define fj(a,n) for(int j=a;j<n;j++)
#define fk(a,n) for(int k=a;k<n;k++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#include <stdio.h>

#define BOARD_SIZE 10
#define timee 100

int n1=0,n2=0;
int att=0;

void swapi(char board[][BOARD_SIZE],int i1,int j1,int i2,int j2)
{
    char temp;
    temp=board[i1][j1];
    board[i1][j1]=board[i2][j2];
    board[i2][j2]=temp;
}
void move(char coord[2],char board[][BOARD_SIZE],int n)
{
    int ser=0;
    char w[]="0123456789";
    int row,col;
    fi(0,10)
    {
        if(coord[0]==w[i])

        {
            row=i;
        }
        if(coord[1]==w[i])
        {
            col=i;
        }
    }
    printf("You can move your piece to:\n");
    if(n==1)
    {
        if(board[row+1][col+1]=='-')
        {
            ser++;
            printf("%d.) %d%d      " ,ser, row+1,col+1);
        }
        if(board[row+1][col-1]=='-')
        {
            ser++;
            printf("%d.) %d%d \n" , ser,row+1,col-1);
        }
        char ch[2];
        printf("Choose where do you want to move your piece \n");
        scanf("%s" , &ch);
        int x,y;
        fi(0,10)
        {
            if(ch[0]==w[i])
            {
                x=i;
            }
            if(ch[1]==w[i])
            {
                y=i;
            }
        }
            swapi(board,row,col,x,y);
    }
    if(n==2)
    {
        if(board[row-1][col-1]=='-')
        {
            printf("%d.) %d%d      " ,ser, row-1,col-1);
        }
        if(board[row-1][col+1]=='-')
        {
            printf("%d.) %d%d \n" ,ser, row-1,col+1);
        }
        char ch[2];
        printf("Choose where do you want to move your piece \n");
        scanf("%s" , &ch);
        int x,y;
        fi(0,10)
        {
            if(ch[0]==w[i])
            {
                x=i;
            }
            if(ch[1]==w[i])
            {
                y=i;
            }
        }
            swapi(board,row,col,x,y);
    }

}
void attack(char coord[2],char board[][BOARD_SIZE],int n)
{
    char w[]="0123456789";
    int row,col;
    fi(0,10)
    {
        if(coord[0]==w[i])
        {
            row=i;
        }
        if(coord[1]==w[i])
        {
            col=i;
        }
    }
    printf("ATTACK! \n");
    if(n==1)
    {
        if(board[row+1][col+1]=='o')
        {
            swapi(board,row,col,row+2,col+2);
            board[row+1][col+1]='-';
        }
        else if(board[row+1][col-1]=='o')
        {
            swapi(board,row,col,row+2,col-2);
            board[row+1][col-1]='-';
        }
    }
    if(n==2)
    {
        if(board[row-1][col-1]=='x')
        {
            swapi(board,row,col,row-2,col-2);
            board[row-1][col-1]='-';
        }
        else if(board[row-1][col+1]=='x')
        {
            swapi(board,row,col,row-2,col+2);
            board[row-1][col+1]='-';
        }
    }

}

void check_for_attack(char board[][BOARD_SIZE],int n)
{
    if(n==1)
    {
        fi(1,9)
        {
            fj(1,9)
            {
                if(board[i][j]=='x')
                {
                    if(board[i+1][j+1]=='o'||board[i+1][j+1]=='O')
                    {
                        if(board[i+2][j+2]=='-')
                        {
                            printf("%d%d can attack %d%d\n" ,i,j,i+1,j+1);
                            att=1;
                        }
                    }
                    if(board[i+1][j-1]=='o'||board[i+1][j-1]=='O')
                    {
                        if(board[i+2][j-2]=='-')
                        {
                            printf("%d%d can attack %d%d\n" ,i,j,i+1,j-1);
                            att=1;
                        }
                    }
                }
            }
        }
    }
    if(n==2)
    {
        fi(1,9)
        {
            fj(1,9)
            {
                if(board[i][j]=='o')
                {
                    if(board[i-1][j-1]=='x'||board[i-1][j-1]=='X')
                    {
                        if(board[i-2][j-2]=='-')
                        {
                            printf("%d%d can attack %d%d\n" ,i,j,i-1,j-1);
                            att=1;
                        }
                    }
                    if(board[i-1][j+1]=='x'||board[i-1][j+1]=='X')
                    {
                        if(board[i-2][j+2]=='-')
                        {
                            printf("%d%d can attack %d%d\n" ,i,j,i-1,j+1);
                            att=1;
                        }
                    }
                }
            }
        }
    }

}
void count(char board[][BOARD_SIZE])
{
    n1=0;n2=0;
    fi(0,8)
    {
        fj(0,8)
        {
            if(board[i][j]=='x'||board[i][j]=='X')
            {
                n1++;
            }
            if(board[i][j]=='o'||board[i][j]=='O')
            {
                n2++;
            }
        }
    }
}
void printBoard(char board[][BOARD_SIZE])
{
    int i, j;

    printf("  ");
    for (i = 1; i < BOARD_SIZE-1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 1; i < BOARD_SIZE-1; i++)
    {
        printf("%d ", i);
        for (j = 1; j < BOARD_SIZE-1; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    char p1[1],p2[1];
    // Initialize the board
    fi(0,BOARD_SIZE)
    {
        fj(0,BOARD_SIZE)
        {
            board[i][j]='*';
        }
    }
    for (i = 1; i < BOARD_SIZE-1; i++) {
        for (j = 1; j < BOARD_SIZE-1; j++) {
            // Populate board with empty spaces
            board[i][j] = '-';
        }
    }

    // Set initial positions for pieces
    for (i = 1; i < BOARD_SIZE-1; i += 2) {
        board[1][i+1] = 'x'; // 'x' represents black pieces
        board[2][i] = 'x';
        board[3][i+1] = 'x';
        board[6][i] = 'o'; // 'o' represents white pieces
        board[7][i+1] = 'o';
        board[8][i] = 'o';
    }

    // Print the board
    printBoard(board);


    //GAME//
    int m=0;
    time_t start_time , end_time;
    double p1_time=0.0 , p2_time=0.0;
    double elapsed_time;
    while(p1_time<timee && p2_time<timee)
    {
        att=0;
        count(board);
        if(n1==0)
        {
            printf("Player 2 wins! \n");
            break;
        }
        if(n2==0)
        {
            printf("Player 1 wins! \n");
            break;
        }
        if(m%2==0)
        {
            //Player 1 turn:
            printf("Player 1's turn \n");
            char coord[2];
            att=0;
            check_for_attack(board,1);

            start_time = time(NULL);
            //choose
            scanf(" %c", &coord[0]);
            scanf(" %c", &coord[1]);
            if(att!=0)
            {
                attack(coord,board,1);
            }
            else
            {
                move(coord,board,1);
            }

            end_time=time(NULL);
            elapsed_time=difftime(end_time , start_time);
            p1_time=p1_time+elapsed_time;
            printBoard(board);
            printf("The time elapsed for Player 1 is:- %lf ", p1_time);
            m++;
            printf("\n");
        }
        if(m%2==1)
        {
            //player 2 turn
             printf("Player 2's turn \n");
            char coord[2];
            att=0;
            check_for_attack(board,2);

            start_time = time(NULL);
            //choose
            scanf(" %c", &coord[0]);
            scanf(" %c", &coord[1]);
            if(att!=0)
            {
                attack(coord,board,2);
            }
            else
            {
             move(coord,board,2);
            }
            end_time=time(NULL);
            elapsed_time=difftime(end_time , start_time);
            p2_time=p2_time+elapsed_time;
            printBoard(board);
            printf("The time elapsed for Player 2 is:- %lf ", p2_time);
            m++;
            printf("\n");
        }
    }
    if(p1_time>timee)
    {
        printf("Player 2 has won by time \n");
    }
    else if(p2_time>timee)
    {
        printf("Player 1 has won by time \n");
    }
    return 0;
}
