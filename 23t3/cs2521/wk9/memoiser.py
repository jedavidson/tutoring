import time


def expensive_function(x: int) -> int:
    # Simulate some "expensive" work
    time.sleep(x)
    return x + 1


class Memoiser:
    def __init__(self, f):
        self.f = f

    def call(self, x):
        return self.f(x)
