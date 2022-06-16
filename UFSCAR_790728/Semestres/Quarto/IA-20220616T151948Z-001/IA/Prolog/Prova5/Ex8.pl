misterio([],[]):- !.

misterio([X], [X]) :- !.

misterio([X|Y], Z) :- is_list(X), misterio(Y,W),append(W,[X],Z), !.

misterio([X|Y], Z) :- misterio(Y,W), append(W,[X],Z),!.