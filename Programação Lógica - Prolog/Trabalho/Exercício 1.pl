% Letra A

progenitor(jose, joao).
progenitor(jose, ana).
progenitor(jose, jessica).
progenitor(jose, lucas).
progenitor(maria, joao).
progenitor(maria, ana).
progenitor(maria, jessica).
progenitor(maria, lucas).
progenitor(joao, mario).
progenitor(helena, carlos).
progenitor(mario,carlos).
progenitor(ana, helena).
progenitor(ana, joana).
progenitor(joana, antonio).
progenitor(joana, juares).
progenitor(jessica, heloisa).
progenitor(lucas, fagundes).
progenitor(lucas, marcia).
progenitor(lucas, julio).
progenitor(marcia, luciano).
progenitor(marcia, rodrigo).

% Letra B

sexo(jose, masculino).
sexo(joao, masculino).
sexo(mario, masculino).
sexo(lucas, masculino).
sexo(carlos, masculino).
sexo(antonio, masculino).
sexo(juares, masculino).
sexo(fagundes, masculino).
sexo(julio, masculino).
sexo(luciano, masculino).
sexo(rodrigo, masculino).
sexo(marcia, feminino).
sexo(maria, feminino).
sexo(ana, feminino).
sexo(jessica, feminino).
sexo(helena, feminino).
sexo(joana, feminino).
sexo(heloisa, feminino).

mae(maria, joao).
mae(maria, ana).
mae(maria, jessica).
mae(maria, lucas).
mae(ana, helena).
mae(ana, joana).
mae(joana, antonio).
mae(joana, juares).
mae(jessica, heloisa).

pai(jose, joao).
pai(jose, ana).
pai(jose, jessica).
pai(jose, lucas).
pai(joao, mario).
pai(lucas, fagundes).
pai(lucas, marcia).
pai(lucas, julio).
pai(marcia, luciano).
pai(marcia, rodrigo).

irma(X, Y) :- sexo(X, feminino), sexo(Y, feminino), X \= Y, (mae(Z, X), mae(Z, Y));(pai(W, X), pai(W, Y)).
irmao(X, Y) :- sexo(X, masculino), sexo(Y, masculino), X \= Y, (mae(Z, X), mae(Z, Y));(pai(W, X), pai(W, Y)).
irmaos(X,Y) :- irma(X,Y); irmao(X,Y).

descendente(X, Y) :- progenitor(Y, X).
descendente(X, Y) :- progenitor(Y, Z), descendente(X, Z).

avoo(X, Y) :- mae(X, Z), progenitor(Z, Y).
avo(X, Y) :- pai(X, Z), progenitor(Z, Y).
avos(X, Y) :- avoo(X,Y); avo(X,Y).
tio(X, Y) :- irmao(X, Z), progenitor(Z, Y).
tia(X, Y) :- irma(X, Z), progenitor(Z, Y).
tios(X,Y) :- tia(X, Y); tio(X, Y).
primo(X, Y) :- tio(Z, X), descendente(Y, Z).

% Letra C 

% 1. O João é filho do José?
filho_de_jose(joao) :- pai(jose, joao).

% 2. Quem são os filhos da Maria?
filhos_de_maria(Filho) :- mae(maria, Filho).

% 3. Quem são os primos do Mário?
primos_de_mario(Primos) :- setof(Primo, (tio(Tio, mario), progenitor(Tio, Primo)), Primos).

% 4. Quantos sobrinhos/sobrinhas com um Tio existem na família Pinheiro?
% Obs: digitie um tio específico para saber todos os seus sobrinhos, ex: quantidade_sobrinhos(lucas, Count).
quantidade_sobrinhos(Tio, Count) :- setof(Sobrinho, (tios(Tio, Sobrinho)), Sobrinhos), length(Sobrinhos, Count).

% 5. Quem são os ascendentes do Carlos?
ascendentes_de_carlos(Ascendentes) :- setof(Ascendente, descendente(carlos,Ascendente), Ascendentes).

% 6. A Helena tem irmãos? E irmãs?
tem_irmaos_helena(Irmaos) :- setof(Irmao ,irmaos(Irmao, helena), Irmaos).

% 7. Quem é avô/avó de Luciano?
avos_de_luciano(Avo) :- 
    progenitor(Avo, luciano).  
avos_de_luciano(Avo) :- 
    progenitor(Avo, Pai),  
    avos_de_luciano(Pai). 

% 8. Quem tem netos na família Pinheiro?
tem_netos(Avos) :-
  setof(Avo, Neto^avos(Avo, Neto), Avos).















