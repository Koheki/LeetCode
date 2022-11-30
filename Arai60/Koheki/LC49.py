class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)

        for s in strs:
            a = "".join(sorted(s))
            anagrams[a].append(s)

        return [a for a in anagrams.values()]