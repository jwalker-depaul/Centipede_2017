#ifndef _AwesomeFont
#define _AwesomeFont

#include "SpriteSheet.h"

class AwesomeFont : public SpriteSheet
{
public:
	AwesomeFont();

	AwesomeFont(const AwesomeFont&) = delete;
	AwesomeFont& operator=(const AwesomeFont&) = delete;
	virtual ~AwesomeFont() = default;

private:
	virtual int CharToIndex(char& c);
};


#endif _AwesomeFont