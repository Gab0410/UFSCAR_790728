

subconjunto(_,[]) :- !.

subconjunto(Set,[X|Y]):- member(X,Set), !, subconjunto(Set,Y).