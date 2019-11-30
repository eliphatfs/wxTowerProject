#include<iostream>
using namespace std;

int blood(int m_attack, int m_defense, int p_attack, int p_defense, 
	int m_blood,int p_blood) {
	int battleTimes = m_blood / (p_attack - m_defense);
	int loss = battleTimes * (m_attack - p_defense);
	if (loss > p_blood) {
		return -1;
	}
	else return (p_blood - loss);
}
