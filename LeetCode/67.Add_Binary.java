public class 67.Add_Binary {
    class Solution {
    public String addBinary(String a, String b) {

        StringBuilder sb = new StringBuilder();
        int i = a.length()-1, j = b.length()-1, carry = 0;

        while(i >= 0 || j >= 0)
        {
            int sum = carry;

            if(i >= 0)
            {
                sum = sum + (a.charAt(i) - '0'); //convert the character to number
                i-- ;    
            }

            if( j >= 0 )
            {
                sum = sum + (b.charAt(j) - '0'); //convert the character to number
                j-- ;    
            }

            sb.append(sum%2) ;
            carry = sum/2 ;
        }

        if(carry!=0)
            sb.append(carry);

        return sb.reverse().toString();

    }
}
}
