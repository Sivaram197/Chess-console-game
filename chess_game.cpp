  #include <iostream>
  #include <string>
  #include <vector>
  
  using namespace std;
  
  // Constants
  const int BOARD_SIZE = 8;
  
  // Piece types
  enum PieceType {
      EMPTY,
      PAWN,
      KNIGHT,
      BISHOP,
      ROOK,
      QUEEN,
      KING
  };
  
  // Player colors
  enum PlayerColor {
      WHITE,
      BLACK
  };
  
  // Chess piece
  struct ChessPiece {
      PieceType type;
      PlayerColor color;
  };
  
  // Chess board
  vector<vector<ChessPiece>> board;
  
  // Initialize the board with pieces in their starting positions
  void init_board() {
      board = {
          { {ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK},
            {KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK} },
          { {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK},
            {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK} },
          { {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
            {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK} },
          { {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
            {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK} },
          { {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
            {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK} },
          { {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
            {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK} },
          { {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE},
            {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE} },
          { {ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE},
            {KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE} }
      };
  }
  
  // Print the board
  void print_board() {
      for (int i = BOARD_SIZE - 1; i >= 0; i--) {
          cout << i + 1 << " ";
          for (int j = 0; j < BOARD_SIZE; j++) {
              if (board[i][j].type == EMPTY) {
                  cout << ".";
              } else if (board[i][j].color == WHITE) {
                  switch (board[i][j].type) {
                      case PAWN:   cout << "P"; break;
                      case KNIGHT: cout << "N"; break;
                      case BISHOP: cout << "B"; break;
                      case ROOK:   cout << "R"; break;
                      case QUEEN:  cout << "Q"; break;
                      case KING:   cout << "K"; break;
                  }
              } else {
                  switch (board[i][j].type) {
                      case PAWN:   cout << "p"; break;
                      case KNIGHT: cout << "n"; break;
                      case BISHOP: cout << "b"; break;
                      case ROOK:   cout << "r"; break;
                      case QUEEN: cout << "q"; break;
                      case KING: cout << "k"; break;
  }
  }
  cout << " ";
  }
  cout << endl;
  }
  cout << " a b c d e f g h" << endl;
  }
  
  // Convert a position string like "e4" to coordinates on the board
  bool pos_to_coords(string pos, int &row, int &col) {
  if (pos.length() != 2) {
  return false;
  }
  col = pos[0] - 'a';
  row = pos[1] - '1';
  if (col < 0 || col >= BOARD_SIZE || row < 0 || row >= BOARD_SIZE) {
  return false;
  }
  return true;
  }
  
  // Move a piece from one position to another
  bool move_piece(string from, string to) {
  int from_row, from_col, to_row, to_col;
  if (!pos_to_coords(from, from_row, from_col) || !pos_to_coords(to, to_row, to_col)) {
  return false;
  }
  ChessPiece piece = board[from_row][from_col];
  if (piece.type == EMPTY) {
  return false;
  }
  if (board[to_row][to_col].type != EMPTY && board[to_row][to_col].color == piece.color) {
  return false;
  }
  // TODO: Check if the move is legal for the piece
  board[from_row][from_col] = {EMPTY, WHITE};
  board[to_row][to_col] = piece;
  return true;
  }
  
  int main() {
  init_board();
  print_board();
  while (true) {
      cout << "Enter move: ";
      string input;
      getline(cin, input);
      if (input == "quit") {
          break;
      }
      if (input.length() != 4) {
          cout << "Invalid input" << endl;
          continue;
      }
      if (!move_piece(input.substr(0, 2), input.substr(2))) {
          cout << "Invalid move" << endl;
          continue;
      }
      print_board();
  }
  
  return 0;
  }
