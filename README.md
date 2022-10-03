# tetris_C
tetris in C / Aug 2022

### main()

콘솔에 보이는 디스플레이로 사용할 사각형 요소가 아스키 기준 문자 2개로 인식되어  
전체 그래픽은 1칸에 char 2개씩 할당되어 있는 30 X 30 3차원 배열로 설정.  
30 X 30에서 실제 테트리스의 벽 역할을 할 범위를 Col1 ~ Col2, Row1 ~ Row2로 한정.

block_coors(테트리스 element)도 메모리 할당  

blocktype, spinvalue는 element의 종류와 회전 방향. 랜덤 생성.  

GetCoor(block_coors, blocktype, spinvalue)는 블록의 종류와 스핀 방향을 받아 블록의 좌표를 생성(모양과 스핀만 나타낸다)  

location[0]과 location[1]로 블록이 실제 그래픽 위에서 나타날 위치를 조정한다.  

Add_block(graphic, blockcoors, location) 은 그래픽에 블록을 올려놓는다  
(아직 그래픽에 반영되지는 않았고, 전산적으로만 그 자리에 블록이 존재)  

show_graphic을 하면 비로소 Add_block에서 그래픽 위에 올려놓은 블록이 콘솔에 보인다.  
(나중에 누적 점수도 보이게 추가했다.)  

kbhit()을 통해 키보드에서 화살표 좌, 우, 위, 아래, 그리고 스페이스바가 눌렸을 때의 반응을 설정한다.  
왼쪽 화살표 : 좌로 1칸 이동  
오른쪽 화살표 : 우로 1칸 이동  
위쪽 화살표 : 스핀 방향 변경  
아래쪽 화살표 : 아래로 1칸 이동  
스페이스바 : 블록을 아래로 떨어뜨림 (벽이나 다른 블록에 닿을 때까지)  

그리고 키보드가 눌리지 않아도 일정 시간 간격으로 블록이 한 칸씩 아래로 떨어지게 설정.  

왼쪽 화살표가 눌렸을 때의 코드를 살펴보자.  
```c
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
                        
```
Del_block 으로 원래 있던 블록을 지움  
Move_block 을 통해 위치 값을 아래로 한 칸 수정  
Check_boundary 로 방금 생성한 블록이 벽이나 기존에 존재하는 블록과 겹치지 않는지 확인  
* 겹치지 않는다면  
Add_block 으로 블록을 생성하고  
system("cls")는 이 테트리스가 터미널에서 돌아가기 때문에 한 번 지워줌  
show_graphic 으로 Add-block에서 생서안 블록을 그래픽에 보여준다  
* 겹친다면  
위치 조정한 것을 다시 원상복귀  
Add_block 으로 블록을 생성하고  
system("cls")는 이 테트리스가 터미널에서 돌아가기 때문에 한 번 지워줌  
show_graphic 으로 Add-block에서 생서안 블록을 그래픽에 보여준다  

같은 방식으로 오른쪽 화살표, 아래쪽 화살표가 작동한다.  

위쪽 화살표는 Spin_block 이라는 함수를 통해 스핀 값을 변경하고, 이후는 비슷하다.

스페이스바는 Drop_Block 이라는 함수를 통해 Check_boundary 가 TRUE 인 범위에서 계속 좌표를 아래로 내린다.  
더 이상 아래로 이동할 수 없을 때 cls 처리하고 그래픽을 보여준다.  


```c
if (((end = clock())-start) > 1000){
            start = end;
```
일정 시간마다, Check_boundary 가 TRUE 인 범위에서 Move_block(location, DOWN) 을 시행한다.  
만약 바닥 또는 블록에 닿아서 더 이상 내려갈 수 없을 때, 그래픽을 제시하고 새로운 블록을 생성한다.  
새로운 블록으로 다시 일련의 과정이 반복되는데, 새로운 블록을 놓을 곳이 없을 때까지 블록이 쌓이면 game over 를 제시하고 게임이 끝난다.  

