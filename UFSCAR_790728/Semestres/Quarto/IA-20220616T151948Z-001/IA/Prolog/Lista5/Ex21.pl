

%Ligações entre os arcos

arco(0,1).
arco(0,4).
arco(0,3).
arco(1,2).
arco(1,5).
arco(1,4).
arco(2,0).
arco(2,3).
arco(2,4).
arco(2,1).
arco(3,1).
arco(3,0).
arco(3,4).
arco(4,1).
arco(4,5).
arco(4,2).
arco(4,3).
arco(5,1).
arco(5,0).
arco(6,7).
arco(7,0).

caminho(X,Y):- arco(X,Y).
caminho(X,Y):- arco(X,Z), caminho(Z,Y).