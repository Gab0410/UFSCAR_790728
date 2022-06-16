misterio([],[]):- !.
misterio([X|Y], Z) :- resolve(X,W), misterio(Y,K), append(K,W,Z).
resolve(X,[X]).