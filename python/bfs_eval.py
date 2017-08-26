from emap import emap

def evlt(expr, pos):
    e = expr[pos]
    if e not in emap.keys():
        return e
    lchild = evlt(expr, 2 * pos + 1)
    rchild = evlt(expr, 2 * pos + 2)
    return emap[e](lchild, rchild)

expr = ['+', '*', 5, 4, 20]
print "value = %d"%evlt(expr, 0)
