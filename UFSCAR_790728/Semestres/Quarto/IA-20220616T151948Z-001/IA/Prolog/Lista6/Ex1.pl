assiste(X):- bom(x).
assiste(X):- horario(X,nobre).
audiencia(X,alta):- assiste(X), gosta(X).
propaganda(X,cara):- programa(X), audiencia(X,alta).
propaganda(X,barata):- programa(X), horario(X,madrugada).

programa(p1).
horario(p1,nobre).
gosta(p1).
bom(nenhum). % Para fazer uma BC correta.