from stack import Stack
from emap import emap

expr = ['+', '*', 5, 4, '-', 100, 20]
stk = Stack()
for e in expr[::-1]:
    if e not in emap.keys():
        stk.push(e)
    else:
        x = int(stk.top())
        stk.pop()
        y = int(stk.top())
        stk.pop()
        z = emap[e](x, y)
        print "z = %d" % z
        stk.push(z)
#    print "============"
#    print stk
print "value = %d" % stk.top()
