problema([],[]):- !.

problema([X|Y], Z) :- resolve(X,W), problema(Y,K), append(K,W,Z).

resolve(X,[X]).