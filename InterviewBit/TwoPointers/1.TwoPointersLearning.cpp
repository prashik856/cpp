/*
This topic in itself is not particularly broad. 
However, a lot of interviews tend to be a little biased to questions using this technique which prompted us 
to separate it out as another topic.

So, two pointer ( or N pointer for that matter ) is usually a really clever optimization on some bruteforce approches in certain condition.

Let us start looking at this with the help of a question. Then we will generalize our approach.
Example:
Given a sorted array A ( sorted in ascending order ),
find if there exists 2 integers A[i] and A[j] such that A[i] + A[j] = 0, i != j

Now the naive solution would be,

        for (int i = 0; i < A.size(); i++) 
            for (int j = 0; j < A.size(); j++) {
                if (i != j && A[i] + A[j] == 0) return true; // solution found. 
                if (A[i] + A[j] > 0) break; // Clearly A[i] + A[j] would increase as j increases
            }
This solution is O(n^2).

However, let us now analyze how ‘i’ and ‘j’ move with iterations.
Clearly, ‘i’ moves forward with every iteration.
Now let us analyze the ‘j’ loop.
As i is increasing, A[i] is also increasing.
That means the point where the loop breaks is decreasing.
Let us rewrite the 2 loops slightly differently.

        for (int i = 0; i < A.size(); i++) 
            for (int j = A.size() - 1; j >= 0; j--) {
                if (i != j && A[i] + A[j] == 0) return true; // solution found. 
                if (A[i] + A[j] < 0) break; // Clearly A[i] + A[j] would decrease as j decreases.
            }
Still O(n^2).


Now, with the same analysis, as ‘i’ increases, A[i] also increases.
And the number of iterations after which ‘j’ breaks also increases.
But note what changes when ‘i’ moves to i + 1:

If A[i] + A[J] > 0,
Then A[i + 1] + A[J] is also greater than 0, as A[i + 1] > A[i].
This means if we have tried J for ‘i’, then when moving to i + 1, we should only try values of j < J.
This concludes that our ‘j’ should be monotonically decreasing and we could re-write the above solution as :
        int j = A.size() - 1;    
        for (int i = 0; i < A.size(); i++) 
            for (; j > i; j--) {
                if (i != j && A[i] + A[j] == 0) return true; // solution found. 
                if (A[i] + A[j] < 0) break; // Clearly A[i] + A[j] would decrease as j decreases.
            }

Let us analyze the time complexity of the above solution.
Let us say A.size() = n.

‘i’ moves in total of n steps.
‘j’ also moves in total of n steps
( j– is executed atmost n times. Note that we are never increasing the value of j. Neither are we resetting it ).
That means we take in total of n + n steps = O(n).

In general, all two pointer approach work similarly. You look at the naive solution involving multiple loops and then you start analyzing the pattern on each loop.
Try to look for monotonicity in one of the loops as other loops move forward. If you find that, you have found your optimization.
*/