//============================================================================
// Name        : xlang.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Lexer.h"

using namespace std;
using namespace lexer;

int main() {
	fstream file ("prog.xlang");
	Lexer lex(file);

	Token* t;
	do {
		t = lex.nextToken();
		cout << t->getTag() << " " << t->getLexeme() << endl;
	} while (t->getTag() != Token::TEOF);

	return 0;
}
