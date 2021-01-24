main:-   
   writeln('Number of items? '),
   read(N),
   length(L, N),
   maplist(read, L),	
   mergesort(L, S). 

mergesort([L],[L]):-!.
mergesort([L,B|R],S):-
	split([L, B|R], A1, A2),
	mergesort(A1, S1),
	mergesort(A2, S2),

	format('Sorted list: ~w~n', merge(S1, S2, S)).
	
split([],[],[]).
split([L], [L],[]).
split([L, B|R], [L|Ra], [B|Rb]) :-
	split(R, Ra, Rb).
	
merge(L, [], L).
merge([], B, B).
merge([L|Ra], [B|Rb], [L|M]) :-
	L=< B, merge(Ra, [B|Rb], M).
merge([B|Ra], [L|Rb], [L|M]) :-
	L < A, merge([A|Ra], Rb, M). 
  