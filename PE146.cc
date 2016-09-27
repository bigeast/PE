/*
 *
Total[Sqrt[
  Select[Map[#^2 &, Range[150 10^6]], 
   PrimeQ[# + 1] && PrimeQ[# + 3] && ! PrimeQ[# + 5] && 
     PrimeQ[# + 7] && PrimeQ[# + 9] && ! PrimeQ[# + 11] && 
     PrimeQ[# + 13] && ! PrimeQ[# + 15] && ! PrimeQ[# + 17] && ! 
      PrimeQ[# + 19] && ! PrimeQ[# + 21] && ! PrimeQ[# + 23] && ! 
      PrimeQ[# + 25] && PrimeQ[# + 27] &
   ]]]
 * 676333270
 * About ten minutes?
 * /
