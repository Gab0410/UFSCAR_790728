max_lista([X],X):-!.
max_lista([X|Y],M):- max_lista(Y,N), max(X,N,M).


max(X,Y,X):- X >= Y,!.
max(_,Y,Y).