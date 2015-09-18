#include "MyCell.h"


MyCell::MyCell()
{
	attriNum = 0;
}


MyCell::~MyCell()
{
}

bool MyCell::operator==(const MyCell&cell)
{
	if (cell.attriNum == this->attriNum && cell.attriValue == this->attriValue)
	{
		return true;
	}
	else
	{
		return false;
	}

}