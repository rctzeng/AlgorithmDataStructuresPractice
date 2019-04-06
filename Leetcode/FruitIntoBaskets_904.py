class Solution(object):
    """
    Brute Force: O(N^2) => TLE
    """
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        max_diff = 0
        for i in range(len(tree)):
            for j in range(i+1, len(tree)+1):
                if len(set(tree[i:j]))>2: break
                max_diff = max(max_diff, j-i)
        return max_diff

class Solution1(object):
    """
    Linear scan to find maximum subarray
     - move left cursor when #type>2
    """
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        min_idx, max_diff, types = 0, 0, {}
        i = 0
        for i in range(len(tree)):
            types[tree[i]] = types[tree[i]]+1 if tree[i] in types.keys() else 1
            while len(types)>2:
                types[tree[min_idx]] -= 1
                if types[tree[min_idx]]==0: del types[tree[min_idx]]
                min_idx += 1
            max_diff = max(max_diff, i-min_idx+1)
        return max_diff
