class Soynet():
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
    def add(self):
        return self.a + self.b
    
    def multiply(self):
        return self.a * self.b

s = Soynet(3, 4)

print(s.a)

print(s.b)

print(s.add())

print(s.multiply())

## model.fit --> model class --> function