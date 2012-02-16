/*
      CS471 - Programming Languages
      Lab #3
      Author: Sussman, Evan (esussma1@binghamton.edu)
      Date: 2/16/2012

1.A) a. A relation states the way numbers can be connnected.
b. A function states that one number will completely determine another
unique number. B) Yes, The set of all functions is a subset of the set
of all relations. C) No, every relation is not neccesarily a function.
If a relation maps x -> y and there is an x such that it has two values
of y then that is a relation but not a function.

4. 1. Atoms: mia
      Variables: Butch
      Complex Term(s): loves(Butch,mia)
      Functor: loves
      Arity: 2
   2. Atoms:
      Variables: ALi
      Complex Term(s): boxer(ALi)
      Functor: boxer
      Arity: 1
   3. Atoms:
      Variables: X
      Complex Term(s): and(big(X), kahuna(X)) && big(X) && kahuna(X)
      Functor: and, big, kahuna
      Arity: 2, 1 , 1
   4. Atoms: aBoy
      Variables: X
      Complex Term(s): hide(X, big(big(aBoy))) && big(big(aBoy)) &&
      big(aBoy)
      Functor: hide, big, big
      Arity: 2, 1, 1

  B.  likes(sam,Food) :- <--rule
      indian(Food),
      mild(Food).
      likes(sam,Food) :- <--rule
      thai(Food).
      indian(curry).  <--fact
      indian(tandoori).	<--fact
      mild(tandoori). <--fact
      thai(padthai). <--fact

      4 facts
      2 rules
       head = likes
       goal is to try and match the person to the type of food they like
       eatih
      6 clauses.

*/


/*
origin(point(0,0)).
originR(point(X,Y)) :- X = 0, Y = 0.
*/


mother(mary, ann).
mother(mary, joe).
mother(sue, marY).  /* marY not the same as mary */
mother(sue,mary).

father(mike, ann).
father(mike, joe).
father(tom,mary).

grandparent(sue, ann).

male(joe).
male(mike).
male(tom).

female(mary).
female(ann).
female(sue).

parent(mother(P,C),C).
parent(father(P,C),C).



















