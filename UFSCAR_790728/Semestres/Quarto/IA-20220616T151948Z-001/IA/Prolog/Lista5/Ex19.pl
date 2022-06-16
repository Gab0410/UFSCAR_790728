%substituir(L,E1,E2,K)

substituir([],_,_,[]):- !.

substituir(L,E1,_,L):- not(member(E1,L)), !.

substituir(L,E1,E1,L):- !.

substituir([E1|Y],E1,E2,[E2|Z]):- substituir(Y,E1,E2,Z), !.

substituir([E|Y],E1,E2,[E|Z]):- substituir(Y,E1,E2,Z).
 