class Solution:

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        res = []
        dic = collections.defaultdict(int)
        length, n, m = len(words[0]), len(s), len(words)
        for word in words:
            dic[word] += 1
        for i in range(length):
            count = 0
            copy = dic.copy()  #不能没有.copy(),否则copy会为dic的指针，改变copy后dic也会改变
            #n-length+1的+1是因为range左开右闭
            for j in range(i, n - length + 1, length):
                sub = s[j:j + length]
                copy[sub] -= 1
                if copy[sub] >= 0:
                    count += 1
                pop_start = j - m * length
                if (pop_start >= 0):
                    pop = s[pop_start:pop_start + length]
                    copy[pop] += 1
                    if (copy[pop] > 0):
                        count -= 1
                if count == m:
                    res.append(pop_start + length)

        return res
