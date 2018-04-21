schedule([marriage(1,_,_),
          marriage(2,_,_),
          marriage(3,_,_),
          marriage(4,_,_),
          marriage(5,_,_)]).

solution(S) :- schedule(S),
               member(marriage(1,anne,_) ,S), 
               member(marriage(W,_,wally) ,S), 
               member(marriage(3,_,stan) ,S),
               member(marriage(5,_,rob) ,S),
               member(marriage(I,ida,_) ,S), I=\=5, W=\=1,
               member(marriage(V,fran,vern) ,S),
               member(marriage(E,eve,_) ,S), V=:=E+1,
               member(marriage(_,_,paul) ,S),
               member(marriage(_,cathy,_) ,S).
