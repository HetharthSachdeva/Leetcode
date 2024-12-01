class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        n = len(arr)
        g = {arr[x]:x for x in range(n)}
        for i in range(n):
            if arr[i]/2 in g :
                if g[arr[i]/2]!=i : return True

        return False        