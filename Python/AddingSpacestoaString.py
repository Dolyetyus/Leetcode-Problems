def addSpaces(self, s, spaces):
        spaces_index = 0
        ret_arr = []

        for i in range(len(s)):
            if spaces_index<len(spaces) and spaces[spaces_index] == i:
                ret_arr.append(" ")
                spaces_index += 1
            
            ret_arr.append(s[i])

        return "".join(ret_arr)
