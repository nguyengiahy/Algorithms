class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> set = new HashSet<>();
        List result = new ArrayList();
        Arrays.sort(nums);
        
        for (int i=0; i<nums.length-2; i++){
            int start = i+1;
            int end = nums.length-1;
            while (start < end){
                if (nums[i] + nums[start] + nums[end] == 0){
                    // Hash set will remove duplicates
                    set.add(Arrays.asList(nums[i],nums[start],nums[end]));
                    end--;
                    start++;
                }
                else if (nums[i] + nums[start] + nums[end] > 0){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        
        result.addAll(set);
        return result;
    }
}