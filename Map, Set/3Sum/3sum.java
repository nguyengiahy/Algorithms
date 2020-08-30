class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) return new ArrayList<>(); // if nums less than 3 element
        
        Arrays.sort(nums); // sort array
        Set<List<Integer>> set = new HashSet<>();
        List resultList=new ArrayList();
        
        for(int i=0;i<nums.length-1;i++){
            int start=i+1;
            int end=nums.length-1;
            while(start<end){
                if(nums[i]+ nums[start]+nums[end]==0){
                    // Hash set will remove duplicates if any
                    set.add(Arrays.asList(nums[i],nums[start],nums[end]));
                    end--;
                    start ++;
                }else if(nums[i]+ nums[start]+nums[end]>0){
                    end--;
                }else{
                    start++;
                }
            }
        }

        //Return by adding into List
        resultList.addAll(set);
        return resultList;
    }
}