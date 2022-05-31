#pragma once
#include <string.h>
template<class BOARD,class MOVE>
class player
{
public:
	virtual std::string get_name() const = 0;
	virtual MOVE do_move(const BOARD& board) const = 0;
};

