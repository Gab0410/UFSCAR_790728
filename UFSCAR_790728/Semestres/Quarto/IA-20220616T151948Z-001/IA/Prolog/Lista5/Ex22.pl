arco(a,b).
arco(b,c). 

caminho(X,Y):- arco(X,Y).
caminho(X,Y):- arco(X,Z), caminho(Z,Y).