/*
여러분은 기존 오프라인에서 리테일 사업으로 유명한 신선식품 업체에 입사한 개발자 입니다.

최근 디지털 트랜스포메이션 이슈에 따라 기존 오프라인으로 운영하던 리테일 사업을 온라인으로 전환하게 되었습니다.

여러분에게는 기존 오프라인에서 일어나던 일들을 온라인 쇼핑몰로 전환하는 임무를 진행하게 됩니다.

성공적으로 첫 임무를 완수하여 팀장님의 신임을 얻고 성취감도 느껴보세요!

  

이제 입사한지 얼마 되지 않았기 때문에 간단한 재고 관리 프로그램 개발의 일부를 맡게 되었습니다.

주문이 들어왔을 때 재고량을 적절하게 관리하지 못 하면 재고가 없는 물품의 주문이 추가로 일어날 수 있습니다. 그러면 고객의 불만이 발생할 수 있기 때문에 재고량을 관리가 필요합니다. 또 이렇게 관리한 데이터를 바탕으로 미래의 재고량 수급에 참고 할 수 있을 것입니다.

 

주문이 들어왔을 때 특정 물품의 재고량을 하나 줄이고 매출액을 더하는 일을 하게 됩니다.

 

기존에 수박의 재고량은 5개였습니다.

이번에 들어온 주문은 수박 3건이며, 해당 물품의 가격은 10000원 입니다.

재고량을 차감해주고 매출액을 구하는 프로그램을 만들어 주세요.

 

또 매출액에서 부가세를 구해주세요. 부가세는 물품가격의 10% 입니다.

매출액은 물품의 가격과 부가세를 합산한 가격으로 구합니다.

 

재고량과 매출액을 구하고 다음의 문구를 출력하도록 프로그램을 구현합니다.

(수업 내용을 바탕으로 C언어로 구현하며, 변수명은 자유롭게 지정합니다.)

 

주문건수 : 0 건

기존 재고량 : 0개

남은 재고량 : 0개

매출액(부가세포함) : 000원
*/

#include <stdio.h>

const int PRICE = 10000;
const float TAX = 1.1;

int main(void)
{
    int order_count = 3,
        prev_inventory = 5,
        cur_inventory  = prev_inventory - order_count,
        total_sales = order_count * PRICE * TAX;

    printf("주문건수 : %i 건\n", order_count);
    printf("기존 재고량 : %i 개\n", prev_inventory);
    printf("남은 재고량 : %i 개\n", cur_inventory);
    printf("매출액(부가세포함) : %i 원\n", total_sales);
    
    return 0;
}
