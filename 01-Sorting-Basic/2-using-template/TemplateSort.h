#pragma once
// Created by LnW on 2020/02/21
#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	int score;

	bool operator<(const Student &otherStudent) {
		// ʵ�ַ�����ͬ����ĸ�Ⱥ�˳�����
		return score != otherStudent.score ? score > otherStudent.score:name < otherStudent.name;
	}
	friend ostream& operator<<(ostream &os, const Student &student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};