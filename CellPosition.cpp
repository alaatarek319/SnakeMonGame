#include "CellPosition.h"
#include "UI_Info.h"
#include<cmath>
CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10) {
		hCell = h;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if ((vCell >= 0 && vCell <= 8) && (hCell >= 0 && hCell <= 10)) {
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	if (!cellPosition.IsValidCell())
		return -1;

		int position;
	position = 89 - (11 * cellPosition.vCell) + cellPosition.hCell;
	return position;   // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	if (cellNum < 1 || cellNum>99)
		return position;

	/// TODO: Implement this function as described in the .h file

	position.SetHCell((cellNum - 1) % 11);
	position.SetVCell(ceil(8 - (cellNum - 1) / 11));

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file

	int* finalresult = new int;
	*finalresult = 89 - (11 * vCell) + hCell + addedNum;
	if (*finalresult <= 99)
	{
		SetVCell((ceil(8 - (*finalresult - 1) / 11)));
		SetHCell(((*finalresult - 1) % 11));
	}
	else
	{
		SetVCell(0);
		SetHCell(10);
	}
	delete finalresult;

	// Note: this function updates the data members (vCell and hCell) of the calling object

}