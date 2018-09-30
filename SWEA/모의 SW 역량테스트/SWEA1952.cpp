#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;
int price[4];//1일 1달 3달 1년
int plan[12];
int min_price;
void go(int now_price, int month) {
	if (month >= 12) {
		min_price = min(min_price, now_price);
		return;
	}
	//이용권쓸거없으면 바로다음달로 
	if (plan[month] == 0) {
		go(now_price, month + 1);
	}
	int money;
	//1일권 쓰는경우
	money = plan[month] * price[0];
	go(now_price + money, month + 1);
	//1달권 쓰는 경우
	money = price[1];
	go(now_price + money, month + 1);
	//3달권 쓰는경우
	money = price[2];
	go(now_price + money, month + 3);
	//1년권 쓰는 경우
	money = price[3];
	go(now_price + money, month + 12);
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++) {
		min_price = 987654321;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &price[i]);
		}
		for (int i = 0; i < 12; i++) {
			scanf("%d", &plan[i]);
		}
		go(0, 0);
		printf("#%d %d\n", t_case, min_price);
	}
	return 0;
}