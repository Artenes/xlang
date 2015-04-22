/*
 * Token.cpp
 *
 *  Created on: 15/04/2015
 *      Author: aluno
 */

#include "Token.h"

namespace lexer {

//Operators
Token *Token::TOKEN_ASSIGN = new Token(ASSIGN, "=");
Token *Token::TOKEN_EQUAL  = new Token(EQUAL, "==");
Token *Token::TOKEN_NE     = new Token(NE, "!=");
//Comparsion
Token *Token::TOKEN_GT = new Token(GT, ">");
Token *Token::TOKEN_GE = new Token(GE, ">="); 
Token *Token::TOKEN_LT = new Token(LT, "<");
Token *Token::TOKEN_LE = new Token(LE, "<=");
//Logical
Token *Token::TOKEN_LNOT = new Token(LNOT, "!");
Token *Token::TOKEN_LAND = new Token(LAND, "&&");
Token *Token::TOKEN_LOR = new Token(LOR, "||");
//Arithmetic
Token *Token::TOKEN_MINUS = new Token(MINUS, "-");
Token *Token::TOKEN_PLUS = new Token(PLUS, "+");
Token *Token::TOKEN_STAR = new Token(STAR, "*");
Token *Token::TOKEN_SLASH = new Token(SLASH, "/");
//Others
Token *Token::TOKEN_EOF = new Token(TEOF, "EOF");
Token *Token::TOKEN_LBRACK = new Token(LBRACK, "[");
Token *Token::TOKEN_LCURLY = new Token(LCURLY, "{");
Token *Token::TOKEN_LPAREN = new Token(LPAREN, "(");
Token *Token::TOKEN_RBRACK = new Token(RBRACK, "]");
Token *Token::TOKEN_RCURLY = new Token(RCURLY, "}");
Token *Token::TOKEN_RPAREN = new Token(RPAREN, ")");
Token *Token::TOKEN_SEMI = new Token(SEMI, ";");


Token::Token(int tag, string lexeme) {
	this->tag = tag;
	this->lexeme = lexeme;
}

Token::Token(int tag) {
	this->tag = tag;
	this->lexeme = "";
}

int Token::getTag() const {
	return tag;
}

string Token::getLexeme() const {
	return lexeme;
}

string Token::toString() const {
	stringstream ss;
	ss << lexeme;
	return ss.str();
}

Token::~Token() {
	// TODO Auto-generated destructor stub
}

} /* namespace lexer */
