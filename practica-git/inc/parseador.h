#ifndef PARSEADOR_H
#define PARSEADOR_H

#include <string>
#include <iostream>
#include <locale>
using namespace std;

#include "number_type.h"
#include "queue.h"

#define MAX_ELEMENTS 10

class parseador {
private:
	queue<float, MAX_ELEMENTS> m_numbers;
	const string c_commands[2] = { "SUM","MULT" };
	float m_result;

public:
	parseador() :m_result(0) {};
	bool process_line();
	void show_result();
};

#endif
