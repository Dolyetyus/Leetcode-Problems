class Solution(object):
    # No way this question was "Medium"
    def diffWaysToCompute(self, expression):
        if ('+' not in expression) and ('-' not in expression) and ('*' not in expression):
            return [int(expression)]
        
        res = []
        
        for i, v in enumerate(expression):
            if v == '+' or v == '-' or v == '*':
                left_res = self.diffWaysToCompute(expression[:i])
                right_res = self.diffWaysToCompute(expression[i + 1:])
                for left_i, left_v in enumerate(left_res):
                    for right_i, right_v in enumerate(right_res):
                        if v == '+':
                            res.append(left_v + right_v)
                        elif v == '-':
                            res.append(left_v - right_v)
                        else:
                            res.append(left_v * right_v)
        return res
