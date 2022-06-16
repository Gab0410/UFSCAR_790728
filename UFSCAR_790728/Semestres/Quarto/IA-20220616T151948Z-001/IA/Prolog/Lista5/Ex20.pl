
consecutivos(A1,A2,[A1,A2|Cauda]):- !.
consecutivos(A1,A2,[A|Cauda]):- consecutivos(A1,A2,Cauda), !.