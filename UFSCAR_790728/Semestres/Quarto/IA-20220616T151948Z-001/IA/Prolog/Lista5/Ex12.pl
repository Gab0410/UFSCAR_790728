entre(N1,N2,L):- N1 =<N2, entre1(N1, N2, L).
entre1(N,N,[N]):-!.
entre1(N1,N2,[N1|X]):- Nnovo is N1+1, entre1(Nnovo,N2,X).