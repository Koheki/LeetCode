class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)

        for s in strs:
            a = [0]*26

            for c in s:
                a[ord(c)-97] += 1

            anagrams[tuple(a)].append(s)

        return [a for a in anagrams.values()]