class Solution(object):
    def intToRoman(self, num):
        hmap = {
            1000: 'M',
            900: 'CM',
            500: 'D',
            400: 'CD',
            100: 'C',
            90: 'XC',
            50: 'L',
            40: 'XL',
            10: 'X',
            9: 'IX',
            5: 'V',
            4: 'IV',
            1: 'I'}
        sorted_hmap = sorted(hmap.keys(), reverse=True)
        
        ret = ""
        while num > 0:
            for key in sorted_hmap:
                if key<=num:
                    num -= key
                    ret += hmap[key]
                    break
        
        return ret
