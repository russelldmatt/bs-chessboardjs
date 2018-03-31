Js.log("Hello, BuckleScript and Reason!");

Js.log("foo");

type board;

[@bs.module "chessboardjs"]
external chessboard : string => board = "ChessBoard";

chessboard("board");
