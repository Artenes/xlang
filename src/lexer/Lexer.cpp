/*
 * Lexer.cpp
 *
 *  Created on: 15/04/2015
 *      Author: Artenes
 */

#include "Lexer.h"
#include "Token.h"

namespace lexer {

int Lexer::line = 1;

Lexer::Lexer(fstream& file) {
	this->file = &file;
	this->peek = ' ';
}

bool Lexer::isIdentifierStart(char c) {
	return (isalpha(c) || c == '_');
}

bool Lexer::isIdentifierPart(char c) {
	return (isIdentifierStart(c) || isdigit(c));
}

void Lexer::reserve(Token* w){
	keywords.insert(KeyWordsPair(w->getLexeme(), w));
}

int Lexer::getLine(){
	return line;
}

char Lexer::nextChar(){
	peek = file->get();
	return peek;
}

bool Lexer::isWhitespace(char c){
	switch (c) {
	case ' ': case '\t': case '\n': return true;
	default: return false;
	}
}

Token* Lexer::nextToken(){
	while (isWhitespace(peek)) {
		if (peek == '\n') line++;
		nextChar();
	}
	switch (peek) {
	//ASSIGN, EQUAL
	case '=':
		nextChar();
		if (peek == '=') {
			nextChar();
			return Token::TOKEN_EQUAL;
		} else
			return Token::TOKEN_ASSIGN;
		//NE, LNOT
	case '!':
		nextChar();
		if (peek == '=') {
			nextChar();
			return Token::TOKEN_NE;
		} else
			return Token::TOKEN_LNOT;
		//GT, GE
	case '>':
		nextChar();
		if (peek == '=') {
			nextChar();
			return Token::TOKEN_GE;
		} else
			return Token::TOKEN_GT;
		//LT, LE
	case '<':
		nextChar();
		if (peek == '=') {
			nextChar();
			return Token::TOKEN_LE;
		} else
			return Token::TOKEN_LT;
		//LAND
	case '&':
		nextChar();
		if (peek == '&') {
			nextChar();
			return Token::TOKEN_LAND;
		}
		//LOR
	case '|':
		nextChar();
		if (peek == '|') {
			nextChar();
			return Token::TOKEN_LOR;
		}
		//MINUS
	case '-':
		nextChar();
		return Token::TOKEN_MINUS;
		//PLUS
	case '+':
		nextChar();
		return Token::TOKEN_PLUS;
		//STAR
	case '*':
		nextChar();
		return Token::TOKEN_STAR;
		//SLASH
	case '/':
		nextChar();
		return Token::TOKEN_SLASH;
		//LBRACK
	case '[':
		nextChar();
		return Token::TOKEN_LBRACK;
		//LCURLY
	case '{':
		nextChar();
		return Token::TOKEN_LCURLY;
		//LPAREN
	case '(':
		nextChar();
		return Token::TOKEN_LPAREN;
		//RBRACK
	case ']':
		nextChar();
		return Token::TOKEN_RBRACK;
		//RCURLY
	case '}':
		nextChar();
		return Token::TOKEN_RCURLY;
		//RPAREN
	case ')':
		nextChar();
		return Token::TOKEN_RPAREN;
		//SEMI
	case ';':
		nextChar();
		return Token::TOKEN_SEMI;
	case -1:
		return Token::TOKEN_EOF;
	default:
		if (isIdentifierStart(peek)) {
			stringstream ss;
			do {
				ss << peek;
				nextChar();
			} while (isIdentifierPart(peek));
			string s = ss.str();
			return new Token(Token::IDENTIFIER, s);
		}
	}
	nextChar();
	return new Token(Token::UNKNOW);
}



Lexer::~Lexer() {

}

} /* namespace lexer */
