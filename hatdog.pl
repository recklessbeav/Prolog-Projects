main :-
    writeln('Number of items? '),
    read(N),
    length(L, N),
    maplist(read, L),
 
mergesort([L, B|R], S) :-
	split([L, B|R], L1, L2),
	mergesort(L1, S1),
	mergesort(L2, S2),
	merge(S1, S2, S).
	
split([],[],[]).
split([L], [L],[]).
split([L, B|R], [L|Ra], [B|Rb]) :-
	split(R, Ra, Rb).
	
merge(L, [], L).
merge([], B, B).
merge([L|Ra], [B|Rb], [L|M]) :-
	L=< B, merge(Ra, [B|Rb], M).
merge([L|Ra], [L|Rb], [B|M]) :-
	L > B, merge([A|Ra], Rb, M). 
  