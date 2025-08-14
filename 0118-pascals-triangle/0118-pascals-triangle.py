class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1],[1,1]]
        for i in range(2,numRows):
            l1=[1]
            for j in range(i-1):
                term = triangle[-1][j] + triangle[-1][j+1]
                l1.append(term) 
            l1.append(1) 
            triangle.append(l1)   
        return triangle[:numRows]