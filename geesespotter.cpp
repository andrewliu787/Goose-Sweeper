//SUBMISSION PAGE

#include <iostream>
#include "geesespotter_lib.h"


char *createBoard(std::size_t xdim, std::size_t ydim);
void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim);
void hideBoard(char *board, std::size_t xdim, std::size_t ydim);
void cleanBoard(char *board);
void printBoard(char* board, std::size_t xdim, std::size_t ydim);
int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);
bool isGameWon(char *board, std::size_t xdim, std::size_t ydim);


char *createBoard(std::size_t xdim, std::size_t ydim){

	char *board  = new char[xdim * ydim];

	for(std::size_t i{0}; i < xdim*ydim; ++i){
		board[i] = 0x00;
	}

	return board;

}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim){
	//corners
	const char geese = 0x09;

	for(std::size_t i{0}; i < ydim; i++){
		for(std::size_t k{0}; k < xdim; k++){
			int counter = 0;
			//corners
			if(board[k + xdim*i] != geese){

			if((k + xdim*i) == (0 + ydim*0)){

				if(board[(k+1) + xdim*i] == geese){
					++counter;
				}
				if(board[k + xdim*(i+1)] == geese){
					++counter;
				}
				if(board[(k+1) + xdim*(i+1)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;

				continue;

			}

			if((k + xdim*i) == ((xdim-1) + ydim*0)){
				if(board[(k-1) + xdim*i] == geese){
					++counter;
				}
				if(board[(k) + xdim*(i+1)] == geese){
					++counter;
				}
				if(board[(k-1) + xdim*(i+1)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;
				continue;
			}

			if((k + xdim*i) == ((ydim-1)*xdim)){
				if(board[k + xdim*(i-1)] == geese){
					++counter;
				}
				if(board[(k+1) + xdim*i] == geese){
					++counter;
				}
				if(board[(k+1) + xdim*(i-1)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;
				continue;
			}

			if((k + xdim*i) == (ydim*xdim - 1)){
				if(board[k + xdim*(i-1)] == geese){
					++counter;
				}
				if(board[(k-1) + xdim*(i-1)] == geese){
					++counter;
				}
				if(board[(k-1) + xdim*(i)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;
				continue;
			}

			//edges

			//top
			if((i == 0) && ((k + xdim*i) != (0 + ydim*0) || (k + xdim*i) != ((xdim-1) + ydim*0))){
				if(board[(k-1) + xdim*i] == geese){
					++counter;
				}

				if(board[(k+1) + xdim*i] == geese){
					++counter;
				}

				if(board[(k-1) + xdim*(i+1)] == geese){
					++counter;
				}

				if(board[k + xdim*(i+1)] == geese){
					++counter;
				}

				if(board[(k+1) + xdim*(i+1)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;
				continue;
			}

			//left
			if((k==0) && ((k + xdim*i) != (0 + ydim*0) ||  (k + xdim*i) != ((ydim-1)*xdim))){
				if(board[(k+1) + xdim*(i-1)] == geese){
					++counter;
				}

				if(board[k + xdim*(i-1)] == geese){
					++counter;
				}

				if(board[(k+1) + xdim*i] == geese){
					++counter;
				}

				if(board[k + xdim*(i+1)] == geese){
					++counter;
				}

				if(board[(k+1) + xdim*(i+1)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;
				continue;
			}

			//right
			if(k == (xdim - 1) && ((k + xdim*i) != ((xdim-1) + ydim*0) || (k + xdim*i) != (ydim*xdim - 1))){
				if(board[(k-1) + xdim*i] == geese){
					++counter;
				}

				if(board[(k-1) + xdim*(i-1)] == geese){
					++counter;
				}

				if(board[k + xdim*(i-1)] == geese){
					++counter;
				}

				if(board[k + xdim*(i+1)] == geese){
					++counter;
				}

				if(board[(k-1) + xdim*(i+1)] == geese){
					++counter;
				}


				board[k + xdim*i] = counter;
				continue;
			}
			//bottom
			if(i == (ydim -1) && ((k + xdim*i) != ((xdim-1) + ydim*0) || (k + xdim*i) != (ydim*xdim - 1))){
				if(board[(k-1) + xdim*i] == geese){
					++counter;
				}

				if(board[(k+1) + xdim*i] == geese){
					++counter;
				}

				if(board[(k-1) + xdim*(i-1)] == geese){
					++counter;
				}

				if(board[k + xdim*(i-1)] == geese){
					++counter;
				}

				if(board[(k+1) + xdim*(i-1)] == geese){
					++counter;
				}

				board[k + xdim*i] = counter;
				continue;
			}
			//else...
			if(board[k + xdim*(i-1)] == geese){
				++counter;
			}

			if(board[(k-1) + xdim*(i-1)] == geese){
				++counter;
			}

			if(board[(k+1) + xdim*(i-1)] == geese){
				++counter;
			}

			if(board[(k-1) + xdim*i] == geese){
				++counter;
			}

			if(board[(k+1) + xdim*i] == geese){
				++counter;
			}

			if(board[k + xdim*(i+1)] == geese){
				++counter;
			}
			if(board[(k-1) + xdim*(i+1)] == geese){
				++counter;
			}
			if(board[(k+1) + xdim*(i+1)] == geese){
				++counter;
			}
			board[k + xdim*i] = counter;

		}
		}
	}

}


void hideBoard(char *board, std::size_t xdim, std::size_t ydim){
	for(std::size_t i{0}; i < ydim; i++){
		for(std::size_t k{0}; k < xdim; k++){
			board[k + xdim*i] |= hiddenBit();

	}
}
}

void cleanBoard(char *board){
	delete[] board;
	board = nullptr;
}

void printBoard(char* board, std::size_t xdim, std::size_t ydim){
	char hidden{'*'};
	char marked{'M'};

	for(std::size_t i{0}; i < ydim; i++){
		for(std::size_t k{0}; k < xdim; k++){
			if((board[k+xdim*i] & markedBit()) == markedBit()){
				std::cout << marked;
			}else if((board[k+xdim*i] & hiddenBit()) == hiddenBit()){
				std::cout << hidden;
			}else{
				std::cout << (int) board[k+xdim*i];
			}
		}
		std::cout << std::endl;
	}

}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	const char geese = 0x09;
	const char blank = 0x00;
	if((board[xloc + xdim*yloc] & (markedBit())) == (markedBit())){
		//if marked

			return 1;

	}else if((board[xloc + xdim*yloc] & hiddenBit()) == hiddenBit()){
		// if hidden
		board[xloc + xdim*yloc] &= valueMask();

		if(board[xloc + xdim*yloc] == blank){
			if(board[xloc + xdim*yloc] != geese){
				//corners
			if((xloc + xdim*yloc) == (0 + ydim*0)){
				if((board[xloc + xdim*yloc + 1] & markedBit()) != markedBit()){
					board[xloc + xdim*yloc + 1] &= valueMask();
				}
				if((board[xloc + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc+1)] &= valueMask();
				}
				if((board[(xloc+1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*(yloc+1)] &= valueMask();
				}

				return 0;

			}

			if((xloc + xdim*yloc) == ((xdim-1) + ydim*0)){
				if((board[(xloc-1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*yloc] &= valueMask();
				}
				if((board[xloc + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc+1)] &= valueMask();
				}
				if((board[(xloc-1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc+1)] &= valueMask();
				}

				return 0;
			}

			if((xloc + xdim*yloc) == ((ydim-1)*xdim)){
				if((board[xloc + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc-1)] &= valueMask();
				}
				if((board[(xloc+1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*yloc] &= valueMask();
				}
				if((board[(xloc+1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*(yloc-1)] &= valueMask();
				}

				return 0;
			}

			if((xloc + xdim*yloc) == (ydim*xdim - 1)){
				if((board[xloc + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc-1)] &= valueMask();
				}
				if((board[(xloc-1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc-1)] &= valueMask();
				}
				if((board[(xloc-1) + xdim*(yloc)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc)] &= valueMask();
				}

				return 0;
			}

			//edges

			//top
			if((yloc == 0) && ((xloc + xdim*yloc) != (0 + ydim*0) || (xloc + xdim*yloc) != ((xdim-1) + ydim*0))){
				if((board[(xloc-1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*yloc] &= valueMask();
				}

				if((board[(xloc+1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*yloc] &= valueMask();
				}

				if((board[(xloc-1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc+1)] &= valueMask();
				}

				if((board[xloc + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc+1)] &= valueMask();
				}

				if((board[(xloc+1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*(yloc+1)] &= valueMask();
				}

				return 0;
			}

			//left
			if((xloc==0) && ((xloc + xdim*yloc) != (0 + ydim*0) ||  (xloc + xdim*yloc) != ((ydim-1)*xdim))){
				if((board[(xloc+1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*(yloc-1)] &= valueMask();
				}

				if((board[xloc + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc-1)] &= valueMask();
				}

				if((board[(xloc+1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*yloc] &= valueMask();
				}

				if((board[xloc + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc+1)] &= valueMask();
				}

				if((board[(xloc+1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*(yloc+1)] &= valueMask();
				}

				return 0;

			}

			//right
			if(xloc == (xdim - 1) && ((xloc + xdim*yloc) != ((xdim-1) + ydim*0) || (xloc + xdim*yloc) != (ydim*xdim - 1))){
				if((board[(xloc-1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*yloc] &= valueMask();
				}

				if((board[(xloc-1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc-1)] &= valueMask();
				}

				if((board[xloc + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc-1)] &= valueMask();
				}

				if((board[xloc + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc+1)] &= valueMask();
				}

				if((board[(xloc-1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc+1)] &= valueMask();
				}

				return 0;
			}
			//bottom
			if(yloc == (ydim -1) && ((xloc + xdim*yloc) != ((xdim-1) + ydim*0) || (xloc + xdim*yloc) != (ydim*xdim - 1))){
				if((board[(xloc-1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*yloc] &= valueMask();
				}

				if((board[(xloc+1) + xdim*yloc] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*yloc] &= valueMask();
				}

				if((board[(xloc-1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[(xloc-1) + xdim*(yloc-1)] &= valueMask();
				}

				if((board[xloc + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[xloc + xdim*(yloc-1)] &= valueMask();
				}

				if((board[(xloc+1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
					board[(xloc+1) + xdim*(yloc-1)] &= valueMask();
				}

				return 0;
			}

			//else...
			if((board[xloc + xdim*(yloc-1)] & markedBit()) != markedBit()){
				board[xloc + xdim*(yloc-1)] &= valueMask();
			}

			if((board[(xloc-1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
				board[(xloc-1) + xdim*(yloc-1)] &= valueMask();
			}

			if((board[(xloc+1) + xdim*(yloc-1)] & markedBit()) != markedBit()){
				board[(xloc+1) + xdim*(yloc-1)] &= valueMask();
			}

			if((board[(xloc-1) + xdim*yloc] & markedBit()) != markedBit()){
				board[(xloc-1) + xdim*yloc] &= valueMask();
			}

			if((board[(xloc+1) + xdim*yloc] & markedBit()) != markedBit()){
				board[(xloc+1) + xdim*yloc] &= valueMask();
			}

			if((board[xloc + xdim*(yloc+1)] & markedBit()) != markedBit()){
				board[xloc + xdim*(yloc+1)] &= valueMask();
			}
			if((board[(xloc-1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
				board[(xloc-1) + xdim*(yloc+1)] &= valueMask();
			}
			if((board[(xloc+1) + xdim*(yloc+1)] & markedBit()) != markedBit()){
				board[(xloc+1) + xdim*(yloc+1)] &= valueMask();
			}
			return 0;

		}

		}

		if(board[xloc + xdim*yloc] == geese ){
			return 9;
		}
	}else{

		return 2;
	}

	return 0;
}

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	if((board[xloc + xdim*yloc] & markedBit()) == markedBit()){
		board[xloc + xdim*yloc] &= valueMask();
		board[xloc + xdim*yloc] |= hiddenBit();
	}else if((board[xloc + xdim*yloc] & hiddenBit()) == hiddenBit()){
		board[xloc + xdim*yloc] |= markedBit();
	}else{
		return 2;
	}

	return 0;
}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim){
	std::size_t counter{0};
	std::size_t g_counter{0};
	const char hidden_goose{0x29};
	const char marked_goose{0x39};
	for(std::size_t i{0}; i < ydim; i++){
		for(std::size_t k{0}; k < xdim; k++){

		if(!(board[k+xdim*i] == hidden_goose || board[k+xdim*i] == marked_goose)){
			if( (board[k+xdim*i] & markedBit()) != markedBit() && (board[k+xdim*i ] & hiddenBit()) != hiddenBit() )
			++counter;
		}else{
			++g_counter;
		}

	}
	}

	//comment out section below if you want insta win for all geese
	if(g_counter == 0 && counter >= 1){
		//cleanBoard(board);
		return true;
	}

	if((xdim*ydim) - g_counter == counter){
		//cleanBoard(board);
		return true;
	}

	return false;
	}





