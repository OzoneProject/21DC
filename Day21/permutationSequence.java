private int fac(int n){  // Compute 'n!'
int f = 1;
for(int i = 2; i <= n; i++) f *= i;
return f;
}

public String getPermutation(int n, int k) {
List<Integer> list = new ArrayList<>();     // A dynamic array, to store all numbers
for(int i = 1; i <= n; i++)                 // from 1 to n "in order".
    list.add(i);

String s = "";  // To store final result.

k--;    // As permutations here start from 0 to (n! - 1)

while(n-- > 0) {     // Loop, till all numbers from 1 to n are added in 's'

    int f = fac(n);  // If current position is i, get (n-i)!

    s = s + Integer.toString(list.get(k / f));  // Converting the number we got from
                                        //   'v' to string and concatenate it to s.

    list.remove(k / f); // Erase the element we got from v to avoid repetition

    k %= f; // 'k' now equals remainder after dividing k by fac(n-i).
}

return s; // Return the resultant string.
}