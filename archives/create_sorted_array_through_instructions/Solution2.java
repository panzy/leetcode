package create_sorted_array_through_instructions;

import java.util.Arrays;

/**
 * Compared with the previous solution, the insertion here is costless, but the counting becomes expensive.
 *
 * What this version of solution has accomplished was modeling the problem in a new way. It's still too slow
 * to accept for now, but the following versions will be built on this.
 *
 * Basically, I used an array A as a map: A[i] represents the occurrence times of number i. So executing an
 * instruction is as simple as ++A[x].
 *
 * Then, the original problem becomes: how can we quickly find out sum of A[0:x]? We don't have to sum(A[x:n])
 * directly because that value can be obtained by subtracting the count of executed instructions by A[0:x].
 *
 * Created by Zhiyong Pan on 2021-01-10.
 */
public class Solution2 {
    public int createSortedArray(int[] instructions) {
        final int MIN_NUMBER = 1;
        final int MAX_NUMBER = 100_000;
        // a map. key = number, value = repeated times.
        int[] cnts = new int[MAX_NUMBER - MIN_NUMBER + 1];
        int begin = MAX_NUMBER, end = MIN_NUMBER;
        long cost = 0;

        Arrays.fill(cnts, 0);

        int insCnt = 0;
        for (int num : instructions) {

            // the costs of each of the two approach:
            // 1. shift less numbers left, or
            // 2. shift greater numbers right.
            int cost1 = 0, cost2 = 0;

            if (num < (end - begin) / 2) {
                for (int i = begin; i < num; ++i) {
                    cost1 += cnts[i - MIN_NUMBER];
                }
                cost2 = insCnt - cost1 - cnts[num - MIN_NUMBER];
            } else {
                for (int i = num + 1; i < end; ++i) {
                    cost2 += cnts[i - MIN_NUMBER];
                }
                cost1 = insCnt - cost2 - cnts[num - MIN_NUMBER];
            }

            cost += Math.min(cost1, cost2);
            ++cnts[num - MIN_NUMBER];
            begin = Math.min(begin, num);
            end = Math.max(end, num + 1);
            ++insCnt;
        }

        // "Since the answer may be large, return it modulo 109 + 7"
        return (int) (cost % (1_000_000_000 + 7));
    }

}