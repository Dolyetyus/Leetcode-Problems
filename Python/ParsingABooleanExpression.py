class Solution(object):
    def solve(self, operations, operands):
        curr_operands = []
        while operands[-1] != '(':
            curr_operands.append(operands.pop())

        operands.pop()
        operation = operations.pop()

        if operation == '&':
            result = all(curr_operands)
        elif operation == '|':
            result = any(curr_operands)
        elif operation == '!':
            result = not curr_operands[0]

        return result

    def parseBoolExpr(self, expression):
        operations = []
        operands = []

        for char in expression:
            if char == '(':
                operands.append('(')
            elif char == ')':
                result = self.solve(operations, operands)
                operands.append(result)
            elif char == ',':
                continue
            elif char in ('&', '|', '!'):
                operations.append(char)
            else:
                operands.append(char == 't')

        return operands[0]
