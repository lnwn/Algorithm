#pragma once
// Created by LnW on 2020/02/21
#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	int score;

	bool operator<(const Student &otherStudent) {
		// 实现分数相同按字母先后顺序输出
		return score != otherStudent.score ? score > otherStudent.score:name < otherStudent.name;
	}
	friend ostream& operator<<(ostream &os, const Student &student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};