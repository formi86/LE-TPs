'''
    Codigo que hicimos con bauti para crear una conversacion entre el comprador y el vendedor de un departamento en el codigo del 
    edificio en https://github.com/formi86/LE-TPs/tree/main/2022/py/LE-Ejercicio.

    Aprovechamos la api de openAI para usar el generador de texto, que es capaz de crear conversaciones.

'''

import openai

openai.api_key = "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"

response = openai.Completion.create(
    engine="text-davinci-002", prompt='#Una charla normal entre comprador y vendedor de un departamento', max_tokens=12)

while True:
    prompt = 'a:' + str(input()) + '\nb:'

    response = openai.Completion.create(
        engine="text-davinci-002",
        prompt=prompt,
        max_tokens=12,
        temperature=0.7,
        stop='\n',
        best_of=3
    )

    print(response['choices'][0]['text'])
    print('')
