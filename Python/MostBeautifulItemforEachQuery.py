class Solution(object):
    def sortItems(self, items):
        price_to_value = {}
        for price, value in items:
            if price not in price_to_value or value > price_to_value[price]:
                price_to_value[price] = value

        sorted_items = []
        max_val = 0
        for price in sorted(price_to_value):
            max_val = max(max_val, price_to_value[price])
            sorted_items.append([price, max_val])

        return sorted_items
    
    def binarySearch(self, target, array):
        left = 0
        right = len(array)-1

        while left <= right:
            mid = left + (right-left)//2
            if array[mid][0] == target:
                return array[mid][1]
            elif array[mid][0] < target:
                left = mid + 1
            else:
                right = mid - 1

        return array[right][1] if right >= 0 else 0

    def maximumBeauty(self, items, queries):
        sortQ = self.sortItems(items)
        for i in range(len(queries)):
            queries[i] = self.binarySearch(queries[i], sortQ)

        return queries
