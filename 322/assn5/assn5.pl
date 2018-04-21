coasterList([coaster(8,_,_,_),
             coaster(9,_,_,_),
             coaster(10,_,_,_),
             coaster(11,_,_,_),
             coaster(12,_,_,_)]).

solution(S) :- coasterList(S),
/* The coaster with a thrilling outside top hat has exactly 1 more inversion
   than the flying coaster.
   The flying coaster has more inversions than at least one other ride. */
               member(coaster(_,flapdoodle,_,_), S),
               member(coaster(_,stinger,_,_), S), 
               member(coaster(_,_,_,insideraventurn), S),
               member(coaster(_,_,_,cobraroll), S),
               member(coaster(Top,_,_,outsidetophat), S),
               member(coaster(Fly,_,flying,_), S), 
               Top =:= Fly + 1, Fly =\= 8,

/* The roller coaster with the most inversions doesn't have a cobra roll.
   The roller coaster with the most inversions isn't the Stinger. */
               member(coaster(12,NST,_,NCO), S),
               NST\==stinger, NCO\==cobraroll,

/* The suspended coaster has exactly 1 more inversion than the Screaminator.
   The Screaminator doesn't have 11 inversions. */
               member(coaster(Sus,_,suspended,_), S),
               member(coaster(Scream,screaminator,_,_), S),
               Sus =:= Scream + 1, Scream =\= 11, 

/* Neither the pipeline coaster nor the one with a zero-G roll has 8 inversions.
   (This also implies that the pipeline coaster does not have a zero-G element. */
               member(coaster(Pipe,_,pipeline,NZG), S),
               Pipe=\=8,
               member(coaster(Zerog,_,_,zerogroll), S),
               Zerog=\=8, NZG\==zerogroll,

/* The Plunger has exactly 1 more inversion than the fourth-dimension coaster. */
               member(coaster(Plunge,theplunger,_,_), S), /* CORRECT */
               member(coaster(Fourth,_,fourthdimension,_), S),
               Plunge =:= Fourth + 1,
/* The stand-up roller coaster isn't Flapdoodle */
               member(coaster(Stand,NFLP,standup,_), S),
               NFLP\==flapdoodle,
              
/* Whistle Stop has exactly 1 inversion less than the stand-up roller coaster. */
               member(coaster(Bowtie,_,_,bowtie), S),
               member(coaster(Whistle,whistlestop,_,_), S),
               Whistle =:= Stand - 1,

/* Whistle Stop has exactly 1 inversion more than the ride with a bow-tie
   maneuver. */
               Whistle =:= Bowtie + 1. 
               
