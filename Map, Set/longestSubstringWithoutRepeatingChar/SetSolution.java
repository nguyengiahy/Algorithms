class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int res = 0, i = 0, j = 0;
        while (i < n && j < n)
        {
            // Try to extend the range [i, j]
            if (!set.contains(s.charAt(j)))     // If s(j) is not in the range [i,j]
            {
                set.add(s.charAt(j));
                j++;
                res = Math.max(res, j - i);
            }
            else
            {
                // Move i forward
                set.remove(s.charAt(i));
                i++;
            }
        }
        return res;
    }
}