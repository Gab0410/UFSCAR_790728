split([],[],[]):- !.

split([X|Cauda],[X|Y],Z):- X >= 0, split(Cauda,Y,Z), !.
split([X|Cauda],Y,[X|Z]) :- split(Cauda,Y,Z).