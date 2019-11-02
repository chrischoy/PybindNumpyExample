import wrap
import numpy as np

if __name__ == '__main__':
    xs = np.arange(12).reshape(3, 4).astype('float')
    A = np.random.rand(3, 3)

    print(xs)
    print("np :", xs.sum())
    print("cpp:", wrap.sum(xs))

    print()
    wrap.twice(xs)
    print(xs)

    print(wrap.det(A))
