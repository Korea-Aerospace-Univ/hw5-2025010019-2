#include <stdio.h>

int main(void)
{
    int n=0;            //금액 
    int a, b, c;      // A, B, C 각각 구매할 수 있는 개수 초기화는 for문에서 
    bool found = false;         // 경우의 수가 있을 때 켜준다  
    
    scanf("%d", &n);        // 금액을 입력받는다 
    
    //(n= 900*a + 750*2*b + 200*c) (a,b,c>=1) (c!>=a, b) 세 조건을 만족시켜야 함 
    
    for (a=1; (a*900)<=n; a++){         //a부터 오름차순으로 조건을 만족시키게 더해간다. 
        for (b=2; (a*900 + b*750)<=n; b+=2){
            for (c=1; (a*900 + b*750 + c*200)<=n; c++){
                if((900*a+750*b+200*c)==n) {        //c까지 더해가며 n과 값이 같아진다면 
                    if(c<a || c<b){                 //c상품의 수량 전제를 추가하고 
                    printf("%d %d %d\n", a, b, c);  //출력한다. 
                    found = true;                   //발견했음을 true로 켜주고 마지막에 none가 출력 되지 않게 한다. 
                    }
                }                                   //만약 n 과 값이 같다는 if를 만족시키지 못한다면 c 부터 더해가며 다시 조건을 반복한다 
            }
        }

    }
    if (found==false) printf("none\n");             //하나도 발견 못 할시엔 bool형 상태가 false이므로 none 출력한다. 
    
    return 0;
}
