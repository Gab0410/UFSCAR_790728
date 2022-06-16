% [1,2,3,4,5]
% [5,1,2,3,4]


shift_dir([],[]):- !.
shift_dir([X],[X]):- !.
shift_dir([X|Cauda],[Y|Z]) :- add_primeiro(X,Cauda,Z), !.

add_primeiro(X,[],[X]):- !.
add_primeiro(X, [X1|Cauda],[Y|Z]):- add_primeiro(X1,Cauda,Z),Y = X,!.

