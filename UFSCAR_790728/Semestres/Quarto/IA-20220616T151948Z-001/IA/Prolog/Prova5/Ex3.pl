transforma([], []) :- !.

transforma([X|Y], [X|Z]) :- X>=0, transforma(Y,Z),!.

transforma([_|Y], Z) :- transforma(Y,Z).