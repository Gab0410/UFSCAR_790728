% livro(nome(‘C completo e total’), autor(‘Schildt’), pal_chave([linguagemc, programacao,
% computacao])).
% Exemplo de estrutura

% Criar cinco estruturas desse tipo, pal_chave pode ter entre 3 e 6 valores a)

% 1
livro(nome("C completo e total"), autor("Schildt"), pal_chave([linguagemc, programacao,
computacao])).

% 2
livro(nome("Prolog for dummies"), autor("Gabriel"), pal_chave([linguagempl, programacao,
computacao,ia])).

% 3
livro(nome("Luna e seus amigos"), autor("Claudia"), pal_chave([cachorro,shitzu,mae,animal,mamifero])).

% 4
livro(nome("Os conflitos da Ucrania"), autor("Putin"), pal_chave([guerra,sangue,russia,ucrania,morte,armas])).

% 5
livro(nome("Como o clutch do MW influencia a sociedade atual"), autor("Katraka"), pal_chave([vavas,mw,vivo_keyd,clutch,ucrania])).


% Consultas b)

% livro(nome("C completo e total"),autor(X),_).
% livro(nome(Y),autor("Claudia"),_).
% livro(nome("Como o clutch do MW influencia a sociedade atual"),_,pal_chave(L)).
% livro(nome(Nome),autor(Autor),pal_chave(L)), pertence(ucrania,L).

% Regras

pertence(X,[X|Y]).
pertence(X,[Z|Y]):- pertence(X,Y).

% c)

busca_livro(Lista,Nome,Autor):- livro(nome(Nome),autor(Autor),pal_chave(Pal_chave)), tem_palavra(Pal_chave,Lista).

tem_palavra([X|Y],Lista):- pertence(X,Lista), !.
tem_palavra([X|Y],Lista):- pertence(Y,Lista).
