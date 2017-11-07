import numpy as np
import os
import sys
import glob


def load_data():

    X_list = []
    categories = []

    for path in glob.glob('../../attic/cases/txt/*/*.txt'):
        category = os.path.basename(os.path.dirname(path))
        abspath = os.path.abspath(path)

        categories.append(int(category))

        x = np.loadtxt(path)
        x.shape = (x.shape[0]*x.shape[1])
        X_list.append(x)

    X = np.stack(X_list)
    Y = np.eye(10)[categories]
        
    return X, Y

def gen_examples(X_tot, Y_tot, examples):

    indexes = np.random.randint(0, X_tot.shape[0], examples)
    
    return X_tot[indexes], Y_tot[indexes]

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

def rand_init(dim_1,dim_2=None,m=1):
    return rand_init_2(dim_1,dim_2,m) if dim_2 != None else rand_init_1(dim_1,m)  

def rand_init_2(dim_1,dim_2,m=1):
    return np.random.uniform(-m,m,size=(dim_1,dim_2))

def rand_init_1(dim_1,m=1):
    return np.random.uniform(-m,m,size=(dim_1,))



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

print('loading data...')
X_tot , Y_tot = load_data()

n_f = 64*64
n_c = 10

hidden = 10

lr = 0.1
epochs = 300

n0 = n_f
n1 = hidden
n2 = hidden
nf = n_c

# generate random examples
#X, Y = gen_random_examples(n0, nf, examples)

examples = 100

X, Y = gen_examples(X_tot, Y_tot, examples)
print(X.shape)
print(Y.shape)
print('begining training...')

# generate parameters
number_of_parameters = 0

W = rand_init(n1,n0,0.001)
number_of_parameters += n1*n0

b = np.zeros(n1)
number_of_parameters += n1

U = rand_init(n2,n1,0.001)
number_of_parameters += n2*n1

c = np.zeros(n2)
number_of_parameters += n2

V = rand_init(nf,n2,0.001)
number_of_parameters += nf*n2

d = np.zeros(nf)
number_of_parameters += nf


print('number of parameters:', number_of_parameters)

for e in range(epochs):
    for i in range(examples):

        x = X[i]
        t = Y[i]

        ### forward pass
        u,v,w,r,s,y = forward_pass(x,W,b,U,c,V,d)

        ### backward pass
        ### compute gradients
        dL_ds = y - t
        dL_dd = dL_ds
        dL_dV = np.tensordot(dL_ds, r, axes=0)
        dL_dr = dL_ds @ V 
        dL_dw = dL_dr * dsigmoid(w)
        dL_dc = dL_dw
        dL_dU = np.tensordot(dL_dw, v, axes=0)
        dL_dv = dL_dw @ U
        dL_du = dL_dv * dsigmoid(u)
        dL_db = dL_du
        dL_dW = np.tensordot(dL_du, x, axes=0)

        ### update parameters
        d -= lr * dL_dd
        V -= lr * dL_dV
        c -= lr * dL_dc
        U -= lr * dL_dU
        b -= lr * dL_db
        W -= lr * dL_dW
 
    # loss
    L = 0
    acc = 0
    for i in range(examples):  
        x = X[i]
        t = Y[i]

        u,v,w,r,s,y = forward_pass(x,W,b,U,c,V,d)
        L += - np.log(y @ t)

        pred = np.argmax(y)
        real = np.argmax(t)

        if pred == real:
            acc += 1

    sys.stdout.write("Epoch: {0:06d} Loss: {1:.4f} Accuracy: {2:.2f} \r".format(e,L/examples, acc/examples))
    sys.stdout.flush()

    #if acc == examples:
    #    break

print()
# check accuracy over all the data
# loss
L = 0
acc = 0
for i in range(X_tot.shape[0]):  
    x = X_tot[i]
    t = Y_tot[i]

    u,v,w,r,s,y = forward_pass(x,W,b,U,c,V,d)
    L += - np.log(y @ t)

    pred = np.argmax(y)
    real = np.argmax(t)

    if pred == real:
        acc += 1

print("Accuracy: {0:.2f} \r".format(acc/X_tot.shape[0]))
# save parameters
# W,b,U,c,V,d:

# np.savetxt('W',W)
# np.savetxt('b',b)
# np.savetxt('U',U)
# np.savetxt('c',c)
# np.savetxt('V',V)
# np.savetxt('d',d)


