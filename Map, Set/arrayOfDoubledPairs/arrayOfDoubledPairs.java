class Solution {
    public boolean canReorderDoubled(int[] A) {
        Arrays.sort(A);
        HashMap<Integer, Integer> frequency = new HashMap<>();  // frequency of occurrences
        
        for (int i=0; i<A.length; i++){
            frequency.put(A[i], frequency.getOrDefault(A[i],0) + 1);    // count occurrences
        }
        
        for (int i=0; i<A.length; i++){
            if (frequency.get(A[i]) > 0){
                int temp = (A[i] > 0 ? 2*A[i] : A[i]/2);    // calculate the paired value
                if (frequency.getOrDefault(temp,0) == 0){   // if A[i] can't be paired
                    return false;   
                }
                else{
                    frequency.put(A[i], frequency.get(A[i]) - 1);
                    frequency.put(temp, frequency.get(temp) - 1);
                }
            }
        }
        
        return true;
    }
}