#include <stdio.h>

/////////part 1

// int main()
// {
//     FILE* f;
//     f = fopen( "input.txt", "r" );

//     int x = 1, y = 1;
//     char c;

//     while( fscanf( f, "%c", &c ) == 1 )
//     {
//         if( c == 'U' && x > 0 ) x--;
//         if( c == 'R' && y < 2 ) y++;
//         if( c == 'D' && x < 2 ) x++;
//         if( c == 'L' && y > 0 ) y--;

//         if( c == '\n' )
//         printf( "%d", x*3 + y+1 );
//     }
//     printf( "%d", x*3 + y+1 );

//     return 0;
// }

//////////part 2

int main()
{ 
    FILE* f;
    f = fopen( "input.txt", "r" );

    char v[5][5];
                                  v[0][2] = '1';
                   v[1][1] = '2'; v[1][2] = '3'; v[1][3] = '4';
    v[2][0] = '5'; v[2][1] = '6'; v[2][2] = '7'; v[2][3] = '8'; v[2][4] = '9';
                   v[3][1] = 'A'; v[3][2] = 'B'; v[3][3] = 'C';
                                  v[4][2] = 'D';

    char c;
    int x = 2, y = 0;

    while( fscanf( f, "%c", &c ) == 1 )
    {
       // printf( "%c", v[x][y] );
        // if( c == 'U' && ( 2 <= x-1 + y && x-1 + y <= 6 ) && ( -2 <= x-1 - y && x-1 - y <= 2 ) ) x--;
        // if( c == 'R' && ( 2 <= x + y+1 && x + y+1 <= 6 ) && ( -2 <= x - y+1 && x - y+1 <= 2 ) ) y++;
        // if( c == 'D' && ( 2 <= x+1 + y && x+1 + y <= 6 ) && ( -2 <= x+1 - y && x+1 - y <= 2 ) ) x--;
        // if( c == 'L' && ( 2 <= x + y-1 && x + y-1 <= 6 ) && ( -2 <= x - y-1 && x - y-1 <= 2 ) ) y++;

        if( c == 'U' )
        {
            x--;
            if( !( 2 <= x+y && x+y <= 6 && -2 <= x-y && x-y <= 2 ) ) x++;
        }
        if( c == 'R' )
        {
            y++;
            if( !( 2 <= x+y && x+y <= 6 && -2 <= x-y && x-y <= 2 ) ) y--;
        }
        if( c == 'D' )
        {
            x++;
            if( !( 2 <= x+y && x+y <= 6 && -2 <= x-y && x-y <= 2 ) ) x--;
        }
        if( c == 'L' )
        {
            y--;
            if( !( 2 <= x+y && x+y <= 6 && -2 <= x-y && x-y <= 2 ) ) y++;
        }

        if( c == '\n' )
        {
            printf( "  %c  ", v[x][y] );
        }
    }

    printf( "  %c  ", v[x][y] );
    return 0;
}