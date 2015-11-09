#ifndef HTMLWRITER_H
#define HTMLWRITER_H

#include "DocWriter.h"

class HTMLWriter : public DocWriter{
public:
	HTMLWriter();
	HTMLWriter(const string& fileNae, const string& content);
	~HTMLWriter();

	void Write();

	void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;
};

#endif