% Uniao, Intersec e Diferença entre conjuntos.

% Uniao

uniao([],Y,Y):- !.
uniao([X|Cauda],Y,[X|Z]):- not(member(X,Y)), uniao(Cauda,Y,Z),!.
uniao([_|Cauda],Y,Z):- uniao(Cauda,Y,Z).

% Intersecção
inter([],_,[]):- !.
inter([X|Cauda],Y,[X|Z]):- member(X,Y), inter(Cauda,Y,Z), !.
inter([_|Cauda],Y,Z):- inter(Cauda,Y,Z).

% Diferença

diferença([],_,[]):- !.
diferença([X|Cauda],Y,[X|Z]):- not(member(X,Y)), diferença(Cauda,Y,Z),!.
diferença([_|Cauda],Y,Z):- diferença(Cauda,Y,Z).