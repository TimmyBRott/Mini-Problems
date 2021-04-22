#include <stdio.h>
#include <math.h>

int main()
{
    FILE* f;
    f = fopen( "input.txt", "r" );

    int x = 0, y = 0;
    int dir = 0; // 0 - north, 1 - east, 2 - south, 3 - west
    char c; int dist, found = 0;
    int path[300][2], k = 1;
    path[0][0] = x; path[0][1] = y;

    while( fscanf( f, "%c%d, ", &c, &dist ) == 2 && !found )
    {
        //printf( "%c%u  %d  %d\n", c, dist, x, y );
        if( c == 'R' ) dir++;
        else if( c == 'L' ) dir--;

        if( dir < 0 ) dir = 3;
        if( dir > 3 ) dir = 0;

        if( dir == 0 ) x -= dist;
        if( dir == 1 ) y += dist;
        if( dir == 2 ) x += dist;
        if( dir == 3 ) y -= dist;

        for( int i = 0; i < k-1; i++ )
        {
            if( x == path[k-1][0] )
            {
                if( path[i][1] == path[i+1][1] )
                {
                    if( ( ( path[i][0] < x && x < path[i+1][0] ) || ( path[i][0] > x && x > path[i+1][0] ) ) &&
                        ( ( path[k-1][1] < path[i][1] && path[i][1] < y ) || ( path[k-1][1] > path[i][1] && path[i][1] > y ) ) )
                        {
                            found = 1;
                            y = path[i][1]; 
                            //printf( "----------------%d %d\n", x, path[i][1] );
                            break;
                        }
                }
            }
            else if( y == path[k-1][1] )
            {
                if( path[i][0] == path[i+1][0] )
                {
                    if( ( ( path[i][1] < y && y < path[i+1][1] ) || ( path[i][1] > y && y > path[i+1][1] ) ) &&
                        ( ( path[k-1][0] < path[i][0] && path[i][0] < x ) || ( path[k-1][0] > path[i][0] && path[i][0] > x ) ) )
                        {
                            found = 1;
                            x = path[i][0];
                            //printf( "----------------%d %d\n", path[i][0], y );
                            break;
                        }
                }
            }
        }
        path[k][0] = x; path[k][1] = y; k++;
    }

    printf( "X: %d\nY: %d\nTotal: %d\n", x, y, abs(x) + abs(y) );

    return 0;
}