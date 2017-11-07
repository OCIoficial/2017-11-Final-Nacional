import numpy as np

def softmax(x,axis=0):
    """Compute softmax values for each sets of scores in x with respect to some axis (default 0)."""
    e_x = np.exp(x - x.max(axis=axis, keepdims=True))
    return e_x / e_x.sum(axis=axis, keepdims=True)

def sigmoid(x):
    """Compute sigmoid function for each element in array x."""
    sig = lambda x: 1.0 / (1 + np.exp(-x))
    return np.vectorize(sig)(x)

def dsigmoid(x):
    """Compute the derivative of sigmoid function for each element in array x."""
    return sigmoid(x) * (1 - sigmoid(x))

def forward_pass(x,W,b,U,c,V,d):
    ### forward pass
    u = W @ x + b
    v = sigmoid(u)
    w = U @ v + c
    r = sigmoid(w)
    s = V @ r + d
    y = softmax(s)
    return u,v,w,r,s,y

import sys

W = np.loadtxt('solutions/partial/W_100')
b = np.loadtxt('solutions/partial/b_100')
U = np.loadtxt('solutions/partial/U_100')
c = np.loadtxt('solutions/partial/c_100')
V = np.loadtxt('solutions/partial/V_100')
d = np.loadtxt('solutions/partial/d_100')

matrix = [[int(v) for v in line.split()] for line in sys.stdin]

x = np.array(matrix)
x.shape = (64*64) 

u,v,w,r,s,y = forward_pass(x,W,b,U,c,V,d)

print(np.argmax(y))