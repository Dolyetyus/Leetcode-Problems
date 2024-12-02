class SubrectangleQueries(object):
    def __init__(self, rectangle):
        self.grid = rectangle

    def updateSubrectangle(self, row1, col1, row2, col2, newValue):
        for i in range(row1, row2+1):
            for ii in range(col1, col2+1):
                self.grid[i][ii] = newValue

    def getValue(self, row, col):
        return self.grid[row][col]
