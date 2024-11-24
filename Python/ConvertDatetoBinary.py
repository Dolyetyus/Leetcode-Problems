class Solution(object):
    def convertDateToBinary(self, date):
        arr = date.split('-')
        for i in range(len(arr)):
            arr[i] = "{0:b}".format(int(arr[i]))

        return "-".join(arr)
