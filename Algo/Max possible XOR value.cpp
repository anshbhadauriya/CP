Agr kabhi bhi xorr se related question hai too dekho maximum value kitni ho skti hai 
if its 10pow4 so do this:

convert 10pow4 to binary 
you will get 10011100010000
now replace all digits with 1
  11111111111111
  now convert this to decimal 
16383

  so we got 16383 , it means this is the largest value we can get if we do xor in range of 0 to 10pow4 
so make dp state 16383+1= 16384
