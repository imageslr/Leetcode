class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n=len(s)
        d=collections.defaultdict(int)
        for i in range(n-minSize+1):
            temp=s[i:i+minSize]
            c=set(temp)
            if len(c)<=maxLetters:
                d[temp]+=1
        return max(d.values()) if d else 0
