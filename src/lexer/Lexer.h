/*
 * Lexer.h
 *
 *  Created on: 15/04/2015
 *      Author: aluno
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <iostream>
#include <fstream>
#include "Token.h"

using namespace std;

namespace lexer {

class Lexer {
private:
	fstream* file;
	char peek;
	static int line;
	char nextChar();
	bool isWhitespace(char c);
public:
	Lexer(fstream& file);
	static int getLine();
	virtual ~Lexer();
	Token* nextToken();
};

} /* namespace lexer */
#endif /* LEXER_H_ */
