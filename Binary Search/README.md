# How to identify Binary Search problem? 

 Zaroori nhi hai binary search sirf sorted array me lagega! 
Jab bhi question me bole ki minimum number or maximum number of ways or any thing related too observe kro ki jab tum input value badha rhe ho too kya output bhi badh rha hai yaa ghat rha hai monotonically then we can apply binary search, suppose kisi question me bola hoo find minimum number which divides all the number of given array so take 1 as a low
              maximum element of array as high 
              mid=low+(high-low)/2
              check kro kya mid se sare element divisible hai if hai too decrease the mid by going h=mid-1;
              else, l=mid+1

              chatgpt example-> 

              


<img width="797" height="269" alt="image" src="https://github.com/user-attachments/assets/251929f9-440e-4809-8049-736f0bb96634" />

<img width="985" height="722" alt="image" src="https://github.com/user-attachments/assets/953b9e9d-b6eb-4e4b-9648-15ec4faaf70e" />

<img width="981" height="523" alt="image" src="https://github.com/user-attachments/assets/9d50b7d4-7ca9-40f8-b986-749b8b443d65" />


