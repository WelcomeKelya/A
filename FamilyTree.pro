% Family Tree Facts

male(john).
male(mike).
male(tom).
male(paul).

female(lisa).
female(anna).
female(susan).
female(mary).

parent(john, mike).
parent(john, anna).
parent(lisa, mike).
parent(lisa, anna).

parent(mike, susan).
parent(mike, tom).
parent(mary, susan).
parent(mary, tom).

parent(paul, john).

% Rules

father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).

grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
grandfather(X, Y) :- male(X), grandparent(X, Y).
grandmother(X, Y) :- female(X), grandparent(X, Y).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).

uncle(X, Y) :- brother(X, Z), parent(Z, Y).
aunt(X, Y) :- sister(X, Z), parent(Z, Y).
