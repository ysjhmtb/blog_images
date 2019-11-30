/*
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

Accepted
time complexity : O(N)
 */

public class MinimumDominoRotationsForEqualRow {

    // 2 1 2 4 2 2
    // 5 2 6 2 3 2
    public int minDominoRotations(int[] A, int[] B) {
        int n = A.length;
        int rotations = this.check(A[0], A, B, n);
        if (rotations != -1) return rotations;
        else return this.check(B[0], A, B, n);

    }

    public int check(int x, int[] A, int[] B, int n) {
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            if (x != A[i] && x != B[i]) return -1;
            else if (x != A[i]) rotations_a++;
            else if (x != B[i]) rotations_b++;
        }
        return Math.min(rotations_a, rotations_b);
    }




    /*
  Return min number of rotations
  if one could make all elements in A or B equal to x.
  Else return -1.
  */
    /*
    public int check(int x, int[] A, int[] B, int n) {
        // how many rotations should be done
        // to have all elements in A equal to x
        // and to have all elements in B equal to x
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            // rotations coudn't be done
            if (A[i] != x && B[i] != x) return -1;
                // A[i] != x and B[i] == x
            else if (A[i] != x) rotations_a++;
                // A[i] == x and B[i] != x
            else if (B[i] != x) rotations_b++;
        }
        // min number of rotations to have all
        // elements equal to x in A or B
        return Math.min(rotations_a, rotations_b);
    }

    public int minDominoRotations(int[] A, int[] B) {
        int n = A.length;
        int rotations = check(A[0], B, A, n);
        // If one could make all elements in A or B equal to A[0]
        if (rotations != -1 || A[0] == B[0]) return rotations;
            // If one could make all elements in A or B equal to B[0]
        else return check(B[0], B, A, n);
    }
    */
}
