soma1([],0):- !.

soma1([X|Y], S) :- soma1(Y, S1), S is S1+X.

 % Programa 2

soma2([],0):- !.

soma2([X|Y], S) :- soma2(Y, S), S is S+X.