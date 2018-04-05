type board;

type cfg;

let cfg: cfg = [%raw
  {|
{
  draggable: true,
  pieceTheme: '../node_modules/chessboardjs/www/img/chesspieces/wikipedia/{piece}.png',
  position: 'start'
}
|}
];

[@bs.module] external chessboard : (string, cfg) => board = "chessboardjs";

chessboard("board1", cfg);

chessboard("board2", cfg);
