/*
 * Token.h
 *
 *  Created on: 15/04/2015
 *      Author: aluno
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace lexer {

class Token {
public:
	enum Tag{
		//Operators
		ASSIGN, EQUAL, NE,
                //Comparsion
                GT, GE, LT, LE,
                //Logical
                LNOT, LAND, LOR,
                //Arithmetic
                MINUS, PLUS, STAR, SLASH,
                //Others
		TEOF, UNKNOW, LBRACK, LCURLY, LPAREN,
                RBRACK, RCURLY, RPAREN, SEMI
	};

	//Operators
        static Token *TOKEN_ASSIGN;
	static Token *TOKEN_EQUAL;
	static Token *TOKEN_NE;
        //Comparsion
        static Token *TOKEN_GT;
        static Token *TOKEN_GE;
        static Token *TOKEN_LT;
        static Token *TOKEN_LE;
        //Logical
        static Token *TOKEN_LNOT;
        static Token *TOKEN_LAND;
        static Token *TOKEN_LOR;
        //Arithmetic
        static Token *TOKEN_MINUS;
        static Token *TOKEN_PLUS;
        static Token *TOKEN_STAR;
        static Token *TOKEN_SLASH;
	//Others
	static Token *TOKEN_EOF;
        static Token *TOKEN_LBRACK;
        static Token *TOKEN_LCURLY;
        static Token *TOKEN_LPAREN;
        static Token *TOKEN_RBRACK;
        static Token *TOKEN_RCURLY;
        static Token *TOKEN_RPAREN;
        static Token *TOKEN_SEMI;

protected:
	int tag;
	string lexeme;

public:
	Token(int tag, string lexeme);
	Token(int tag);
	virtual ~Token();
	int getTag() const;
	string getLexeme() const;
	virtual string toString() const;
};

} /* namespace lexer */
#endif /* TOKEN_H_ */
