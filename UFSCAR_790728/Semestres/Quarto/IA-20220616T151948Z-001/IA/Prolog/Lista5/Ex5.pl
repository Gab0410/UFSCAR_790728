% Lista tem numero par ou numero impar de elementos( A linguagem tem o predicado length, mas não pode ser usado aqui)

% Regras
comprimento([],0):-!.

comprimento([X|L],N):- comprimento(L,N1),N is N1+1.

n_par(L):- comprimento(L,N), N mod 2 =:= 0.

n_impar(L):- comprimento(L,N), N mod 2 =\= 0.


