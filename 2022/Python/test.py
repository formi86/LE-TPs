import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_prime(x):
    return x * (1 - x)

trainingInputs = np.array([[1, 0, 1], [0, 1, 1], [0, 0, 1], [1, 1, 1]])
trainingOutputs = np.array([[0, 1, 1, 0]]).T

weights = 2 * np.random.random((3, 1)) -1

print("Random weights: ")
print(weights)

for i in range(10000):
    inputLayer = trainingInputs
    outputs = sigmoid(np.dot(inputLayer, weights))
    error = trainingOutputs - outputs
    adjustments = error * sigmoid_prime(outputs)
    weights += np.dot(inputLayer.T, adjustments)

print('Weights after')
print(weights)

print('Outputs')
print(outputs)
