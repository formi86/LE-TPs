'''
    Codigo que copie de un video de youtube para probar
    
'''

import numpy as np


class NeuralNet():
    def __init__(self):
        self.weights = 2 * np.random.random((3, 1)) - 1

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def sigmoid_prime(self, x):
        return x * (1 - x)

    def process(self, inputs):
        inputs = inputs.astype(float)
        output = self.sigmoid(np.matmul(inputs, self.weights))
        return output

    def train(self, trainingInputs, trainingOutputs, iterations):
        for i in range(iterations):
            output = self.process(trainingInputs)
            error = trainingOutputs - output
            adjustments = np.dot(trainingInputs.T, error *
                                 self.sigmoid_prime(output))
            self.weights += adjustments


if __name__ == "__main__":

    neuralNetwork = NeuralNet()
    print("Random weights: ")
    print(neuralNetwork.weights)

    trainingInputs = np.array([[0, 0, 1], [1, 1, 1], [1, 0, 1], [0, 1, 1]])
    trainingOutputs = np.array([[0, 1, 1, 0]]).T

    neuralNetwork.train(trainingInputs, trainingOutputs, 10000)

    print('Weights after train: ')
    print(neuralNetwork.weights)

    a = str(input("Input 1: "))
    b = str(input("Input 2: "))
    c = str(input("Input 3: "))

    print(f'New input: 1: {a}, 2: {b}, 3: {c}')
    print("Output: ", round(neuralNetwork.process(np.array([a, b, c]))[0], 2))
