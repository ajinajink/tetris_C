
#define Col1 9
#define Col2 20
#define Row1 3
#define Row2 25
#define LEFT_MOVE 0
#define RIGHT_MOVE 1
#define DOWN    2
#define ROTATION 3
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void nums_to_arr(int** p, int a, int  b, int  c, int  d, int  e, int  f, int  g, int  h)
{
	p[0][0] = a;
	p[0][1] = b;
	p[1][0] = c;
	p[1][1] = d;
	p[2][0] = e;
	p[2][1] = f;
	p[3][0] = g;
	p[3][1] = h;
	return;
}
void show_graphic(char ***p, int *points){
    int i, j ; 
    for ( i = 0 ; i < 30 ; i++){
        for ( j = 0 ; j < 30 ; j++){
            printf("%s",p[i][j]);
        }
        printf("\n");
    }   
    printf("points : %d", *points);
}
void GetCoor(int **p, int blocktype, int spinvalue){
    switch(blocktype){
        case 0:
            switch(spinvalue){
                case 0:
                    nums_to_arr(p,-1,0,0,0,1,0,2,0);
                    break;
                case 1:
                    nums_to_arr(p, 0,-1,0,0,0,1,0,2);
                    break;
                case 2:
                    nums_to_arr(p, -1, 0, 0, 0, 1, 0, 2, 0);
                    break;
                case 3:
                    nums_to_arr(p, 0, -1, 0, 0, 0, 1, 0, 2);
                    break;
                default:
                    break;
            }
            break;
        case 1:
            switch(spinvalue){
                case 0:
                    nums_to_arr(p, -1, -1, 0, -1, 0,0, 0, 1);
                    break;
                case 1:
                    nums_to_arr(p,-1,0,0,0,1,0,1,-1);
                    break;
                case 2:
                    nums_to_arr(p,0,-1,0,0,0,1,1,1);
                    break;
                case 3:
                    nums_to_arr(p, -1,0,-1,1,0,0,1,0);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch(spinvalue){
                case 0:
                    nums_to_arr(p, 0, -1, 0, 0, 0, 1, -1, 1);
                    break;
                case 1:
                    nums_to_arr(p, -1,-1,-1,0,0,0,1,0);
                    break;
                case 2:
                    nums_to_arr(p, 1,-1,0,-1,0,0,0,1);
                    break;
                case 3:
                    nums_to_arr(p,-1,0,0,0,1,0,1,1);
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch(spinvalue){
                case 0:
                    nums_to_arr(p,-1,0,0,0,0,1,1,1);
                    break;
                case 1:
                    nums_to_arr(p, 0,-1,0,0,-1,0,-1,1);
                    break;
                case 2:
                    nums_to_arr(p, -1, 0, 0, 0, 0, 1, 1, 1);
                    break;
                case 3:
                    nums_to_arr(p, 0, -1, 0, 0, -1, 0, -1, 1);
                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch(spinvalue){
                case 0:
                    nums_to_arr(p, 0,0,0,1,-1,1,1,0);
                    break;
                case 1:
                    nums_to_arr(p, -1,-1,-1,0,0,0,0,1);
                    break;
                case 2:
                    nums_to_arr(p, 0, 0, 0, 1, -1, 1, 1, 0);
                    break;
                case 3:
                    nums_to_arr(p, -1, -1, -1, 0, 0, 0, 0, 1);
                    break;
                default:
                    break;
            }
            break;
        case 5:  
            switch(spinvalue){
                case 0:
                    nums_to_arr(p, 0,0,0,1,1,0,1,1);
                    break;
                case 1:
                    nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
                    break;
                case 2:
                    nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
                    break;
                case 3:
                    nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
                    break;
                default:
                    break;
            }   
            break;
        case 6:
            switch(spinvalue){
                case 0:
                    nums_to_arr(p, 0,0,0,1,0,-1,-1,0);
                    break;
                case 1:
                    nums_to_arr(p, -1, 0, 0, 0, 0, 1, 1, 0);
                    break;
                case 2:
                    nums_to_arr(p, 0, -1, 0, 0, 0, 1, 1, 0);
                    break;
                case 3:
                    nums_to_arr(p, 0, -1, 0, 0, 1, 0, -1, 0);
                    break;
                default:
                    break;
            }  
            break; 
        default:
            break ;
    }
}
void Add_block(char ***p, int **block_coors, int location[2]) {
    int tempx, tempy, i  ;
    for (i = 0 ; i < 4 ; i ++){

        tempx = location[0] + block_coors[i][0] ;
        tempy = location[1] + block_coors[i][1] ;

        p[tempx][tempy]="¢Ì" ;
        
    }
}
void Del_block(char ***p, int **block_coors, int location[2]) {
    int tempx, tempy, i ;
    for (i = 0 ; i < 4 ; i ++){

        tempx = location[0] + block_coors[i][0] ;
        tempy = location[1] + block_coors[i][1] ;

        p[tempx][tempy]="  " ;
    }
}
void Move_block(int *location, int direction ) {
    if ( direction == LEFT_MOVE ){
        location[1]-- ;
    }
    else if ( direction == RIGHT_MOVE){
        location[1]++ ;
    }
    else if ( direction == DOWN){
        location[0] ++ ;
    }
}
int Check_boundary(char ***p, int **block_coors, int location[2]){
     int tempx, tempy, i ;
    for (i = 0 ; i < 4 ; i ++){

        tempx = location[0] + block_coors[i][0] ;
        tempy = location[1] + block_coors[i][1] ;

        if (p[tempx][tempy] != "  "){
            return FALSE ;
        }
    } 
    return TRUE ;
}
void Spin_block(int *ps) {
    
    *ps = (*ps + 1) % 4;
    
}
void New_block(char ***p, int *pb, int *ps, int **block_coors, int location[2]) {
    srand(time(NULL));
    *pb = rand() % 7;
    *ps = rand() % 4;

    GetCoor(block_coors, *pb, *ps);

    location[0] = 4 ; location[1] = 14 ;  
}
void Check_line(char ***p, int **block_coors, int location[2], int *points) {
    int i, j, k, count;
    
    for ( i = (Row2 - 1); i > Row1; i--)
    {
        count = 0;
        for ( j = (Col1 + 1); j < Col2; j++)  // if whole line is erased, count == 0
        {
            if (p[i][j] == "  ") {
                count ++; 
            }
        }
        if (count == 0) {  
            for (j = (Col1 + 1); j < Col2; j++){ // erase line
                p[i][j] = "  ";
            }
            for (k = i; k > Row1; k--){  // bring down blocks
                for (j = (Col1 + 1); j < Col2; j++) {
                    p[k][j] = p[k-1][j];
                }
            }
            for (j = (Col1 + 1); j < Col2; j++){ // add blank top row
                p[Row1][j] = "  ";
            }
            *points += 1000;
            i++;
        }
    }
}
int Drop_Block(char ***p, int **block_coors, int location[2], int *points) {
    Del_block(p, block_coors, location);
    Move_block(location, DOWN);
    if (Check_boundary(p, block_coors, location) == TRUE) {
        Add_block(p, block_coors, location);
    }
    else {
        location[0]--;
        Add_block(p, block_coors, location);
        return FALSE;
    }
    return TRUE;
}

void main()
{
    int i, j, ch ; 
    int blocktype, spinvalue ;
    char ***graphic ;
    int **block_coors;
    int location[2], location_next[2] ;
    clock_t start, end ; 
    int points = 0;

    graphic = (char ***)malloc(sizeof(char **)*30) ;

    for ( i = 0 ; i < 30 ; i ++){
        graphic[i] = (char **)malloc(sizeof(char *)*30) ;
        for ( j = 0 ; j < 30; j++){
			if(i == Row2 && j >= Col1 && j <= Col2 ) graphic[i][j] = "¢Ì";
			else if (j==Col1 && i >= Row1 && i <= Row2) graphic[i][j] = "¢Ì";
			else if (j == Col2 && i >= Row1 && i <= Row2) graphic[i][j] = "¢Ì";
			else graphic[i][j] = "  ";
        }
    }

    block_coors = (int **)malloc(sizeof(int *)*4) ;
    for ( i = 0 ; i < 4 ; i++){
        block_coors[i] = malloc(sizeof(int)*2) ;
    }

	srand(time(NULL));
	blocktype = rand() % 7;
	spinvalue = rand() % 4;

    GetCoor(block_coors, blocktype, spinvalue);



    location[0] = 4 ; location[1] = 14 ;

    Add_block(graphic, block_coors, location);
    show_graphic(graphic, &points) ;



    int res;
    start = clock() ;

    while(1){
       if(kbhit()){
            ch = getch();
            if (ch == 224) {
                // direction key is pressed
                ch = getch() ;
                switch(ch){
                    case 75 : // left
                        Del_block(graphic, block_coors, location);
                        Move_block(location, LEFT_MOVE) ;
                        res = Check_boundary(graphic, block_coors, location);
                        if (res == TRUE){
                            
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                        } 
                        else {
                            Move_block(location, RIGHT_MOVE);
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                            break;
                        }
                        break ; 
                    case 77 : //right
                        Del_block(graphic, block_coors, location);
                        Move_block(location, RIGHT_MOVE) ;
                        res = Check_boundary(graphic, block_coors, location);
                        if (res == TRUE){
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                        }
                        else {
                            Move_block(location, LEFT_MOVE);
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                            break;
                        }
                        break ;
                    case 72 : // up (Rotation Function)
                        Del_block(graphic, block_coors, location);
                        Spin_block(&spinvalue) ;
                        GetCoor(block_coors, blocktype, spinvalue);
                        res = Check_boundary(graphic, block_coors, location);
                        if (res == TRUE){
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                        }
                        else {
                            spinvalue = (spinvalue + 3) % 4;
                            GetCoor(block_coors, blocktype, spinvalue);
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                            break;
                        }
                        break ;
                    case 80 : // down (drop)
                        Del_block(graphic, block_coors, location);
                        Move_block(location, DOWN);
                        res = Check_boundary(graphic, block_coors, location);
                        if (res == TRUE){
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                        }
                        else {
                            location[0]--;;
                            Add_block(graphic, block_coors, location);
                            system("cls");
                            show_graphic(graphic, &points);
                            break;
                        }

                        break ;
                    default:
                        break ;
                }
            }
            if (ch == 32) {  // spacebar pressed
                while (Drop_Block(graphic, block_coors, location, &points) == TRUE) {
                    continue;
                };
                system("cls");
                show_graphic(graphic, &points);
            }
        }
        if (((end = clock())-start) > 1000){
            start = end;
            Del_block(graphic, block_coors, location);
            Move_block(location, DOWN);
            res = Check_boundary(graphic, block_coors, location);
            if (res == TRUE){
                Add_block(graphic, block_coors, location);
                system("cls");
                show_graphic(graphic, &points);
            }
            else {
                location[0]--;;
                Add_block(graphic, block_coors, location);
                system("cls");
                show_graphic(graphic, &points);
                Check_line(graphic, block_coors, location, &points);
                New_block(graphic, &blocktype, &spinvalue, block_coors, location);
                if (Check_boundary(graphic, block_coors, location) == TRUE){
                    Add_block(graphic, block_coors, location);
                }
                else {
                    printf("\ngame over");
                    break;
                }
                
            }
        }
    }        
}