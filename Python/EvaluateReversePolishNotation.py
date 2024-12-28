class Solution(object):
    def evalRPN(self, tokens):
        helper = []

        for i in tokens:
            if i.lstrip("-").isnumeric():
                helper.append(int(i))
            else:
                first = helper.pop()
                second = helper.pop()
                if i=="+":
                    result = second+first
                elif i=="-":
                    result = second-first
                elif i=="*":
                    result = second*first
                elif i=="/":
                    result = second // first if second % first == 0 else (second // first + 1) if second / first < 0 else second // first
                helper.append(result)

        return helper.pop()
        
