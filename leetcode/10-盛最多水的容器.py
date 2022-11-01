height = list(map(lambda x:int(x),input().split()))
length = len(height)
re = [0,0,0]
for i1 in range(length):
    if(height[i1]<=min(re[0],re[1])):
        continue
    for i2 in range(i1+1,length):
        area = min(height[i1],height[i2])*(i2-i1)
        if(area>re[2]):
            re[0] = height[i1]
            re[1] = height[i2]
            re[2] = area

print(re[2])#输出最大面积


class Solution:
    def maxArea(self, height: List[int]) -> int:
        if not height or len(height) == 0:
            return 0
        
        res = 0
        n = len(height)
        l, r = 0, n - 1

        while l < r:
            if height[l] > height[r]:
                tmp = (r - l) * height[r]
                r = r - 1
            else:
                tmp = (r - l) * height[l]
                l = l + 1
            res = max(res, tmp)
        
        return res


# 我的解答
class Solution:
    def maxArea(self, height: List[int]) -> int:
        if not height or len(height) == 0:
            return 0
        length = len(height)
        re = [0,0,0]
        for i1 in range(length):
            if(height[i1]<=min(re[0],re[1])):
                continue
            for i2 in range(i1+1,length):
                area = min(height[i1],height[i2])*(i2-i1)
                if(area>re[2]):
                    re[0] = height[i1]
                    re[1] = height[i2]
                    re[2] = area
        return re[2]