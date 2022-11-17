import numpy as np

class neuralNetwork():
    def __init__(self):
        self.weights = 2 * np.random.random((3, 1)) - 1

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))
    
    def sigmoid_prime(self, x):
        return x * (1 - x)

    def think(self, inputs):
        inputs = inputs.astype(float)
        output = self.sigmoid(np.dot(inputs, self.weights))
        return output

    def train(self, trainingInputs, trainingOutputs, iterations):
        for i in range(iterations):
            output = self.think(trainingInputs)
            error = trainingOutputs - output
            adjust = np.dot(trainingInputs.T, error * self.sigmoid_prime(output))
            self.weights += adjust
        print("\n ====TRAINED==== \n")
        print("New weights:\n", self.weights)

if __name__ == "__main__":
    neuralNet = neuralNetwork()

    print("Random weights: ")
    print(neuralNet.weights)

    trainingInputs = np.array([[0, 0, 1], [1, 1, 1], [1, 0, 1], [0, 1, 1]])
    trainingOutputs = np.array([[0, 1, 1, 0]]).T

    a = str(input("input 1: "))
    b = str(input("input 2: "))
    c = str(input("input 3: "))
    output = neuralNet.think(np.array([a, b, c]))
    print("Inputs: ", a, b, c)
    print("Outputs (not trained): ", output)

    neuralNet.train(trainingInputs, trainingOutputs, 80000)

    r = "y"
    while r == "y":
        a = str(input("\ninput 1: "))
        b = str(input("input 2: "))
        c = str(input("input 3: "))
        output = neuralNet.think(np.array([a, b, c]))
        print("Inputs: ", a, b, c)
        print("Outputs (trained): ", round(output[0]))
        r = input("Retry? y/n ")
