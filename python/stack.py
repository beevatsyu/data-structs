class Stack:
    def __init__(self):
        self._container = []
        self._top = -1

    def __str__(self):
        buf = None
        if self._top < 0:
            buf = "stack is empty"
        else:
            buf = str(self._container[self._top]) + "\t<-- top of the stack"
            if self._top > 0:
                for item in self._container[self._top - 1::-1]:
                    buf += '\n' + str(item)
        return buf

    def empty(self):
        return True if self._top < 0 else False
        

    def top(self):
        if self._top >= 0:
            return self._container[self._top]
        else:
            raise Exception('stack is empty')

    def push(self, item):
        self._top += 1
        self._container.insert(self._top, item)

    def pop(self):
        if self._top >= 0:
            self._top -= 1
        else:
            raise Exception('stack is empty')
        

#stk = Stack();
#stk.push(1)
#stk.push(2)
#stk.push(3)
#stk.pop()
#stk.pop()
#stk.push(4)
#print stk
