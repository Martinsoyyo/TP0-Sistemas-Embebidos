#include "main.h"
#include "parseador.h"


int main()
{
	while (true) {
		parseador PARSER;
		if (PARSER.process_line())	PARSER.show_result();
		else cout << "Error." << endl;
	}

	return 0;
}
