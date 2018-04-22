type board;

type position;

type fen = string;

type color = string;

type orientation = color;

type square = string;

type piece = string;

/* or slow/fast */
type speed = int;

type cfg = {
  .
  "draggable": Js.nullable(bool), /* false */
  "dropOffBoard": Js.nullable(string), /* 'snapback' */
  "position": Js.nullable(string), /* n/a */
  "onChange": Js.nullable((position, position) => unit),
  "onDragStart": Js.nullable((square, piece, position, orientation) => bool),
  "onDragMove":
    Js.nullable(
      (square, square, square, piece, position, orientation) => unit,
    ),
  "onDrop":
    Js.nullable(
      (square, square, piece, position, position, orientation) => unit,
    ),
  /* CR mrussell:  */
  /* "onMouseoutSquare":  */
  /* "onMouseoverSquare" */
  /* "onMoveEnd" */
  /* "onSnapbackEnd" */
  /* "onSnapEnd" */
  "orientation": Js.nullable(color),
  "showNotation": Js.nullable(bool),
  "sparePieces": Js.nullable(bool),
  /* "showErrors" */
  "pieceTheme": Js.nullable(string), /* or function */
  "appearSpeed": Js.nullable(speed),
  "moveSpeed": Js.nullable(speed),
  "snapbackSpeed": Js.nullable(speed),
  "snapSpeed": Js.nullable(speed),
  "trashSpeed": Js.nullable(speed),
};

/* module Config = { */
/*   type dropOffBoard = */
/*     | Snapback */
/*     | Trash; */
/*   type draggable = option(dropOffBoard); */
/*   type positionObject; */
/*   type position = */
/*     | Start */
/*     | Fen(string) */
/*     | Position(positionObject); */
/*   type onChange = (old:positionObject, new_:positionObject) => unit; */
/*   type onDragStart = (old:positionObject, new_:positionObject) => unit; */
/*   type t = { */
/*     draggable, */
/*     position : option(position); */
/*     onChange : option(onChange); */
/*   }; */
/* }; */
/* let cfg: cfg = [%raw */
/*   {| */
     /* { */
     /*   draggable: true, */
     /*   pieceTheme: '../node_modules/chessboardjs/www/img/chesspieces/wikipedia/{piece}.png', */
     /*   position: 'start' */
     /* } */
     /* |} */
/* ]; */
let cfg: cfg = {
  "appearSpeed": Js.Nullable.null,
  "draggable": Js.Nullable.return(true),
  "dropOffBoard": Js.Nullable.null,
  "moveSpeed": Js.Nullable.null,
  "onChange":
    Js.Nullable.return((from, to_) => {
      Js.log(from);
      Js.log(to_);
      Js.log({j|from: $(from) to: $(to_)|j});
    }),
  "onDragStart":
    Js.Nullable.return((square, piece, position, boardOrientation) => {
      Js.log("on drag start");
      Js.log(piece);
      piece.[0] === 'w';
    }),
  "onDragMove": Js.Nullable.null,
  "onDrop":
    Js.Nullable.return(
      (from_square, to_square, piece, from_pos, to_pos, color) => {
      Js.log(from_square);
      Js.log(to_square);
      Js.log(piece);
      Js.log(from_pos);
      Js.log(to_pos);
      Js.log(color);
    }),
  "orientation": Js.Nullable.null,
  "pieceTheme": Js.Nullable.null,
  /* Js.Nullable.return( */
  /*   "../node_modules/chessboardjs/www/img/chesspieces/wikipedia/{piece}.png", */
  /* ), */
  "position": Js.Nullable.return("start"),
  "showNotation": Js.Nullable.null,
  "snapSpeed": Js.Nullable.null,
  "snapbackSpeed": Js.Nullable.null,
  "sparePieces": Js.Nullable.null,
  "trashSpeed": Js.Nullable.null,
};

Js.log(cfg##draggable);

[@bs.module] external chessboard : (string, cfg) => board = "chessboardjs";

chessboard("board1", cfg);

chessboard("board2", cfg);
