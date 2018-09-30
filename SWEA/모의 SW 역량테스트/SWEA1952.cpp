#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;
int price[4];//1�� 1�� 3�� 1��
int plan[12];
int min_price;
void go(int now_price, int month) {
	if (month >= 12) {
		min_price = min(min_price, now_price);
		return;
	}
	//�̿�Ǿ��ž����� �ٷδ����޷� 
	if (plan[month] == 0) {
		go(now_price, month + 1);
	}
	int money;
	//1�ϱ� ���°��
	money = plan[month] * price[0];
	go(now_price + money, month + 1);
	//1�ޱ� ���� ���
	money = price[1];
	go(now_price + money, month + 1);
	//3�ޱ� ���°��
	money = price[2];
	go(now_price + money, month + 3);
	//1��� ���� ���
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