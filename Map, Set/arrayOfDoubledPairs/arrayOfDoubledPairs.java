class Solution {
    public boolean canReorderDoubled(int[] A) {
        HashMap<Integer, Integer> frequency = new HashMap<Integer, Integer>();
        Arrays.sort(A); // sort array
        
        for (int i=0;i<A.length;i++)
            frequency.put(A[i], frequency.getOrDefault(A[i],0) + 1);       // Increase frequency for value A[i]
        
        for (int i=0;i<A.length;i++)
        {
            if (frequency.get(A[i]) > 0) 
            {
                int temp = (A[i] >= 0 ? 2*A[i] : A[i]/2);
                if (frequency.getOrDefault(temp, 0) <= 0)     // If A[i] cannot be matched
                    return false;
                else
                {
                    // Decrease frequency of A[i] and 2*A[i]
                    frequency.put(A[i], frequency.get(A[i]) - 1);
                    frequency.put(temp, frequency.get(temp) - 1);
                }
            }
        }
        return true;
    }
}