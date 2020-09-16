/* 
✔︎ 문제 1. 학점을 계산해보자!


1. 미션 제목
    학점을 계산해보자!

 

2. 지시문
    - 학생의 점수로 학점을 구하는 프로그램을 작성하시오.
    - 키보드에서 입력받은 성적 (0 ~ 100 점) 의 유효성을 체크
    - 학점은 배열을 이용하여 초기화 (아래 “학점 테이블” 참조)
    - 학점은 “학점” 과 같이 계산하는데, 반드시 “학점 테이블”을 사용하여 계산하고 학점도 “학점 테이블”의 내용을 출력
    - 성적을 입력하여 계속 학점을 구하며 특별한 문자인 “-1” 을 입력하면 프로그램을 종료

 

Table 1 - 학점


 

Table 2 - 학점 테이블


 

유효성 체크: 0 <= 성적 <= 100
    - “120” 입력 -> 성적을 올바르게 입력하세요! (0 ~ 100)

 

Figure 1 출력 결과




3. 핵심 개념
#배열 #표준입력 #표준출력 #분기문 #반복문 #break #무한반복문

 

4. 부가 설명
- 표준입출력: https://www.tutorialspoint.com/cprogramming/c_input_output.htm
- break: https://www.tutorialspoint.com/cprogramming/c_break_statement.htm

 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TABLE_ROW 2
#define NUMBER_OF_GRADES 9

const int GRADE = 0;
const int SCORE = 1;
const int CELL_WIDTH = 10;

const int SCORES[NUMBER_OF_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const char *GRADE_TABLE[TABLE_ROW][NUMBER_OF_GRADES] = 
    {
        {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"},
        {"95", "90", "85", "80", "75", "70", "65", "60", "0"}
    };

void prt_table(void);
void prt_row(char *head, const char *arr[]);
int input_to_score(char *input);
bool input_validation(char *input);
char* calc_grade(int score, const int scores[], const char *grades[]);

int main(void) 
{
    char *input = malloc(sizeof(char) * 4),
         *grade;
    int score = 0;

	printf("학점 프로그램\n종료를 원하면 \"999\" 입력\n");
    prt_table();

    while(strcmp(input,"999") != 0)
    {
        printf("성적을 입력하세요 : ");
        scanf("%s", input);

        score = input_to_score(input);

        if (score == -1)
        {
            printf("** %s 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다. **\n", input);
            continue;
        }

        grade = calc_grade(score, SCORES, GRADE_TABLE[GRADE]);
        printf("학점은 %s 입니다.\n", grade);
    }

    printf("학점 프로그램을 종료합니다.\n");

	return 0;
}

void prt_table(void)
{
    printf("[학점 테이블]\n");
    prt_row("점수", GRADE_TABLE[SCORE]);
    prt_row("학점", GRADE_TABLE[GRADE]);
}

void prt_row(char *head, const char *row[])
{
    printf("%s : ", head);
    for (size_t i = 0; i < NUMBER_OF_GRADES; i++)
    {
        printf("%-*s", CELL_WIDTH, row[i]);
    }
    printf("\n");
}

int input_to_score(char *input)
{
    int num;

    if (isdigit(*input) == false) return -1;
    
    num = atoi(input);

    return (num >= 0 && num <= 100) ? num : -1;
}

char* calc_grade(int score, const int scores[], const char *grades[])
{
    char *grade;

	for (size_t i = 0; i < NUMBER_OF_GRADES; i++) {
		if (score >= scores[i]) {
			grade = malloc(sizeof(char) * strlen(grades[i]));
			strcpy(grade, grades[i]);
			break;
		}
	}

	return grade;
}
