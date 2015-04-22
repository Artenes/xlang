/*
 * Lexer.h
 *
 *  Created on: 15/04/2015
 *      Author: Artenes
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <iostream>
#include <fstream>
#include <map>
#include "Token.h"

using namespace std;

namespace lexer {

class Lexer {

	typedef pair<string, Token*> KeyWordsPair;

private:
	fstream* file;
	char peek;
	static int line;
	map<string, Token*> keywords;
	char nextChar();
	bool isWhitespace(char c);
	bool isIdentifierStart(char c);
	bool isIdentifierPart(char c);
	void reserve(Token *w);
public:
	Lexer(fstream& file);
	static int getLine();
	virtual ~Lexer();
	Token* nextToken();
};

} /* namespace lexer */
#endif /* LEXER_H_ */
