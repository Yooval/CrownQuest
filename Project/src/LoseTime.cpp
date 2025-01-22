#include "LoseTime.h"
#include "Board.h"

void LoseTime::action(Board& board) {
	board.setTimeGift(-30);
}
