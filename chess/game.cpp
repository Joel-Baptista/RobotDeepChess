#include <iostream>
#include "chess-library/include/chess.hpp"

using namespace chess;

class ChessGame {
public:
    std::string get_fen(Board board){
        return board.getFen();
    }

    Board get_board_state(std::string board){
        return Board(board);
    }
    Board get_initial_board_state(){
        return Board();
    }
    Board get_board_state(Board board){
        return board;
    }

    std::string get_next_state(std::string state, std::string action){
        Board board = this->get_board_state(state);
        Move move = uci::uciToMove(board, action);
        board.makeMove(move);
        return this->get_fen(board);
    }

    std::string get_next_state(std::string state, Move action){
        Board board = this->get_board_state(state);
        board.makeMove(action);
        return this->get_fen(board);
    } 

};


int main () {
    
    ChessGame game;
    // Board board = game.get_board_state("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Board board = game.get_initial_board_state();
    Movelist moves;
    std::string next_state;
    std::string state;

    for (int i=0; i<10000; i++){
        
        movegen::legalmoves(moves, board);
        
        next_state = game.get_next_state(game.get_fen(board), moves[0]);

        board = game.get_board_state(next_state);

        std::cout << board << "\n";
    }

    Board board2 = game.get_board_state(game.get_fen(board));

    std::cout << board2.fullMoveNumber() << "\n";

    return 0;
}