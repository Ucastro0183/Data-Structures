/*
 * Scanner.h
 *
 *  Created on: Jun 27, 2014
 *      Author: ucastro
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
using namespace std;

class Scanner {
public:
	Scanner();
	virtual ~Scanner();

	// Sets the string to be scanned
	void setInput(string str);

	string nextToken();
	bool hasMoreTokens();

	enum spaceOptionT { PreserveSpaces, IgnoreSpaces };

	void setSpaceOption(spaceOptionT option);
	spaceOptionT getSpaceOption();

	string toString();

private:
	spaceOptionT spaceOp;

};
#endif /* SCANNER_H_ */
