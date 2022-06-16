insere_em_ordem(E,[],[E]):-!.

insere_em_ordem(E,[X|Y],[E,X|Y]):- E =< X,!.

insere_em_ordem(E,[X|Y],[X|Z]):- insere_em_ordem(E,Y,Z),!.