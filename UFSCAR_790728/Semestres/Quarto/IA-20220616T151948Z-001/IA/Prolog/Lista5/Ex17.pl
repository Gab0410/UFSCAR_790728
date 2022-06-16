encontra_atomo(X,[X]):- !.
encontra_atomo(X,[X|_]):-!.
encontra_atomo(X,[Y|_]):- is_list(Y),encontra_atomo(X,Y),!.
encontra_atomo(X,[_|Z]):- encontra_atomo(X,Z).