c1([],0):- !.

c1([X|Y], S) :- c1(Y, S1), S is S1+1.

 % Programa 2

c2([],0):- !.

c2([X|Y], S) :- c2(Y, S), S is S+1.