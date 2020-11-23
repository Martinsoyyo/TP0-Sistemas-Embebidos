#include "parseador.h"

bool parseador::process_line()
{
	string STR;
	float NUM;

	while (std::getline(cin, STR) && (NUM = atof(STR.c_str()))) {
		if (NUM) m_numbers.Add(NUM);
		else break;
	}


	float  AUX = 0;
	if (STR == c_commands[0]) { //SUM
		m_result = 0;
		while(m_numbers.Get(AUX)) m_result += AUX;
		return true;
	}
	else if (STR == c_commands[1]) { //MULT
		m_result = 1;
		while (m_numbers.Get(AUX)) m_result *= AUX;
		return true;
	}
	return false;
};

void parseador::show_result() {
	cout << "Resultado:" << m_result << endl;
};