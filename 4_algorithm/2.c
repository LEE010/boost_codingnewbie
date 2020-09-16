/*
1. 미션 제목
친구들과 최단거리에 있는 집 구하기

 

 

2. 지시문
David의 친구들은 한 거리에 모두 모여살고 있습니다. David은 이번에 친구들이 살고 있는 거리로 이사를 가기로 했는데, 친구들의 집에서 거리가 가장 가까운 집을 구해서 그곳으로 이사를 하고 싶습니다. 모두 같은 거리에 살고 있으므로 아래 그림과 같이 친구들의 집 위치를 수직선 상에 표현할 수 있고, 그 때 집은 항상 정수점 위에만 있다고 가정합니다.


이 때, David이 어느 위치에 있는 집으로 이사를 가야 모든 친구들의 집까지의 거리의 합이 최소가 될 수 있는지 생각해보고 이를 출력하는 프로그램을 작성해봅시다. 그리고 이 때 이 프로그램의 시간복잡도(Big O)가 얼마나 되는지 얘기해봅시다. 어떻게 하면 시간복잡도를 최소화할 수 있을지도 같이 생각해봅시다. 집이 있을 수 있는 위치는 한자리 정수로만 구성되며, 숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에 배열로 선언하는 것으로 가정하고, 숫자에는 중복이 있을 수 있습니다.

예)
입력값: 12345 -> 출력값: 3
입력값: 2224 -> 출력값: 2
* 2224의 경우 2에 3명이 같이 사는 것으로 보실 수 있지만 문제상 같은 위치에 여러명이 살 수 있다는 가정으로 풀어주세요^^

 


3. 핵심 개념
#거리의합이최소 #중앙값 #평균값

 

 

* 본 문제의 경우 문제를 푸는데 도움이 되는 힌트가 있습니다. 알고리즘의 경우 방법을 직접 고민해보고 찾는 것이 중요합니다. 때문에 고민을 하시다가 도저히 풀 수가 없을때 아래의 힌트를 참고해주시길 바랍니다.


-> '         ' 사이를 마우스로 블록을 하면 힌트가 나옵니다.

 '평균값과 중앙값 중에 거리의 합을 최소로 만드는 값은 어떤 것인지 먼저 생각해봅시다.'


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
#define LEN 10
#define MAX 2147483647

int ctoi(char c);
int shortest_pos(int n, int houses[]);

int main()
{
    char friends_pos[SIZE];
    int houses[SIZE], friend_num = 0, res;

    scanf("%s",friends_pos);
    friend_num = strlen(friends_pos);

    for (size_t i = 0; i < friend_num; i++)
    {
        houses[i] = ctoi(friends_pos[i]);
    }

    res = shortest_pos(friend_num, houses);
    printf("%d\n", res);

    return 0;
}

int ctoi(char c)
{
    int i = c - '0';
    return i;
}

int shortest_pos(int n, int houses[])
{
    int res = 0, min_total = MAX;    

    for (int pos = 0; pos < LEN; pos++)
    {
        int total = 0;
        
        for (size_t i = 0; i < n; i++)
        {
            total += abs(houses[i] - pos);
        }
        
        if (total < min_total)
        {
            res = pos;
            min_total = total;
        }    
    }
    return res;
}
