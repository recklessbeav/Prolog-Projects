% Beaverly Cuasi 
main :-
    writeln('Number of items? '),
    read(N),
    length(L, N),
    maplist(read, L),
    sort(L, S),
    format('Sorted list: ~w~n', [S]).