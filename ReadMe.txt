Brian Gauch
CSE 332
3/8/2013
Lab 3

I compiled my code every few minutes to check for errors, rather than getting a zillon errors at the end.

The program seems to behave as intended.
I ignore invalid tokens.
My test cases are included (deck1.txt, ... deck4.txt).
My only minor concerns are that it does not correctly deal with a straight like Ah 2d 3s 4h 5h, and it treats 5 of a kind like high card.  Since 5 of a kind is not possible in a normal deck im not sure what correct behavior is here. We were not told to worry about ace-low straights (which would be a pain).

At first I assumed my Hand class was supposed to be a poker hand, but later put all the poker related things in Poker.cpp.

Sample output:

i = 0
Hand{
rank = 2, suit = S
rank = 5, suit = C
rank = 6, suit = C
rank = 10, suit = H
rank = J, suit = D
}
hands.size = 1
i = 1
Hand{
rank = 4, suit = C
rank = 10, suit = C
rank = Q, suit = C
rank = Q, suit = H
rank = A, suit = C
}
hands.size = 2
i = 2
Hand{
rank = 10, suit = D
rank = 10, suit = S
rank = J, suit = H
rank = J, suit = S
rank = K, suit = C
}
hands.size = 3
i = 3
Hand{
rank = 4, suit = H
rank = 6, suit = D
rank = 8, suit = S
rank = J, suit = C
rank = K, suit = H
}
hands.size = 4
i = 4
Hand{
rank = 2, suit = D
rank = 8, suit = C
rank = 8, suit = H
rank = Q, suit = S
rank = A, suit = D
}
hands.size = 5
i = 5
Hand{
rank = 4, suit = S
rank = 5, suit = H
rank = 7, suit = C
rank = Q, suit = D
rank = K, suit = S
}
hands.size = 6
i = 6
Hand{
rank = 3, suit = D
rank = 3, suit = S
rank = 4, suit = D
rank = 9, suit = H
rank = A, suit = S
}
hands.size = 7
i = 7
Hand{
rank = 2, suit = C
rank = 5, suit = S
rank = 7, suit = S
rank = 9, suit = D
rank = 9, suit = S
}
hands.size = 8
i = 8
Hand{
rank = 3, suit = H
rank = 6, suit = H
rank = 6, suit = S
rank = 9, suit = C
rank = K, suit = D
}
hands.size = 9

----------AFTER SORTING---------

Hand{
rank = 2, suit = C
rank = 5, suit = S
rank = 7, suit = S
rank = 9, suit = D
rank = 9, suit = S
}
Hand{
rank = 2, suit = S
rank = 5, suit = C
rank = 6, suit = C
rank = 10, suit = H
rank = J, suit = D
}
Hand{
rank = 3, suit = H
rank = 6, suit = H
rank = 6, suit = S
rank = 9, suit = C
rank = K, suit = D
}
Hand{
rank = 4, suit = H
rank = 6, suit = D
rank = 8, suit = S
rank = J, suit = C
rank = K, suit = H
}
Hand{
rank = 10, suit = D
rank = 10, suit = S
rank = J, suit = H
rank = J, suit = S
rank = K, suit = C
}
Hand{
rank = 4, suit = S
rank = 5, suit = H
rank = 7, suit = C
rank = Q, suit = D
rank = K, suit = S
}
Hand{
rank = 3, suit = D
rank = 3, suit = S
rank = 4, suit = D
rank = 9, suit = H
rank = A, suit = S
}
Hand{
rank = 2, suit = D
rank = 8, suit = C
rank = 8, suit = H
rank = Q, suit = S
rank = A, suit = D
}
Hand{
rank = 4, suit = C
rank = 10, suit = C
rank = Q, suit = C
rank = Q, suit = H
rank = A, suit = C
}

---------AFTER POKER SORTING----------

Hand{
rank = 2, suit = S
rank = 5, suit = C
rank = 6, suit = C
rank = 10, suit = H
rank = J, suit = D
}
Hand{
rank = 4, suit = H
rank = 6, suit = D
rank = 8, suit = S
rank = J, suit = C
rank = K, suit = H
}
Hand{
rank = 4, suit = S
rank = 5, suit = H
rank = 7, suit = C
rank = Q, suit = D
rank = K, suit = S
}
Hand{
rank = 3, suit = D
rank = 3, suit = S
rank = 4, suit = D
rank = 9, suit = H
rank = A, suit = S
}
Hand{
rank = 3, suit = H
rank = 6, suit = H
rank = 6, suit = S
rank = 9, suit = C
rank = K, suit = D
}
Hand{
rank = 2, suit = D
rank = 8, suit = C
rank = 8, suit = H
rank = Q, suit = S
rank = A, suit = D
}
Hand{
rank = 2, suit = C
rank = 5, suit = S
rank = 7, suit = S
rank = 9, suit = D
rank = 9, suit = S
}
Hand{
rank = 4, suit = C
rank = 10, suit = C
rank = Q, suit = C
rank = Q, suit = H
rank = A, suit = C
}
Hand{
rank = 10, suit = D
rank = 10, suit = S
rank = J, suit = H
rank = J, suit = S
rank = K, suit = C
}
Type anything and hit enter to quit


