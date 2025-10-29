 string binary="";
            int num=i;

            while(num>0) {
                int remainder=num%2;
                binary=to_string(remainder)+binary;
                num=num/2;
            }
