#include "GeneralInfo.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


GeneralInfo::GeneralInfo(char nextBlockLetter, int score, int level, int hi_score): score(score), level(level), hi_score(hi_score), nextBlockLetter(nextBlockLetter){}

bool GeneralInfo::is_valid_block(char c) {
	if (c == 'Z' || c == 'I' || c == 'J' || c == 'L' || c == 'O' || c == 'T' || c == 'S') {
		return true;
	} 
	return false;
}

bool GeneralInfo::is_valid_level(int l) {
	if (l >= 1 && l <= 5) {
		return true;
	}
	return false;
}
 


bool GeneralInfo::is_valid_score(int s) {
	if (s >= 0) {
		return true;
	}
	return false;
}

int getScore(GeneralInfo general) {
	return general.score;
}

int getLevel(GeneralInfo general) {
	return general.level;
}

int get_hi_score(GeneralInfo general) {
	return general.hi_score;
}


char getNextBlockLetter(GeneralInfo general) {
	return general.nextBlockLetter;
}

void GeneralInfo::setScore(int s) {
	if (is_valid_score(s)) {
		score = s;
	}
	string serr = "Invalid score.";
	throw serr;
}

void GeneralInfo::setLevel(int l) {
	if (is_valid_level(l)) {
		level = l;
	}
	string lerr = "Invalid level";
	throw lerr;
}

void GeneralInfo::set_hi_score(int h) {
	if (is_valid_score(h)) {
		hi_score = h;
	}
	string herr = "Invalid score.";
	throw herr;
}

void GeneralInfo::setNextBlockLetter(char c) {
	if (is_valid_block(c)) {
		nextBlockLetter = c;
	}
	string berr = "Invalid block";
	throw berr;
}

