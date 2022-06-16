% Intersecção

inter3(L1,L2,L3,L):- inter(L1,L2, Linter), inter(Linter,L3,L).

inter([],_,[]):- !.
inter([X|Cauda],Y,[X|Z]):- member(X,Y), inter(Cauda,Y,Z), !.
inter([_|Cauda],Y,Z):- inter(Cauda,Y,Z).