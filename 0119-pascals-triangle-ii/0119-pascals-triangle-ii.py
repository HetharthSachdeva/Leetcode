class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        triangle = [[1],[1,1]]
        for i in range(2,rowIndex+1):
            l1=[1]
            for j in range(i-1):
                term = triangle[-1][j] + triangle[-1][j+1]
                l1.append(term) 
            l1.append(1) 
            triangle.append(l1)   
        if rowIndex ==0:
            return[1]
        else:    
            return triangle[-1]