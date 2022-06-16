%Nome: Gabriel Meirelles Carvalho Orlando
%RA: 790728
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

preparo_fisico(ruim):- jogador(X), lento(X), !.
preparo_fisico(ruim):- jogador(X), lesao(X).

%Para evitar warnings.
preparo_fisico(bom).

situacao_de_gols(ruim) :- gols_sofridos(X), gols_feitos(Y), X > Y, !.



% Situacao do PDF 


jogador(jorge).
cartao_vermelho(jorge).
tecnico(m1).
discute(jorge,m1).
gols_sofridos(1).
gols_feitos(2).
salarios(atrasados).

lesao(nenhum).
lento(nenhum).