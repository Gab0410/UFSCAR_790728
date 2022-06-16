%Base de conhecimento

problema(preparador_fisico):- preparo_fisico(ruim).
problema(equipe_tecnica) :- atritos(constantes), situacao_psicologica(ruim).
problema(time) :-preparo_fisico(bom), situacao_de_gols(ruim).
problema(insatisfacao_finaceira):- atritos(constantes), salarios(atrasados).
 
atritos(constantes):- jogador(X), tecnico(Y), discute(X,Y), !.
atritos(constantes):- jogador(X), jogador(Y), discute(X,Y).

situacao_psicologica(ruim) :- jogador(X), suspenso(X), !.
situacao_psicologica(ruim) :- jogador(X), cortado(X).

suspenso(X) :- cartao_vermelho(X).
suspenso(nenhum).

preparo_fisico(ruim):- jogador(X), lento(X).
preparo_fisico(ruim):- jogador(X), lesao(X), !.
 

situacao_de_gols(ruim):- gols_sofridos(X), gols_feitos(Y), maior(X,Y), !.



jogador(cleiton).
jogador(henrique).
lento(henrique).

tecnico(andre).
salarios(atrasados).

discute(cleiton,andre).

cortado(cleiton).

cartao_vermelho(nenhum).
lesao(nenhum).
gols_feitos(nenhum).
gols_sofridos(nenhum).
maior(nenhum,nenhum).

%preparador_fisico, equipe_tecnica, insatisfacao_finaceira