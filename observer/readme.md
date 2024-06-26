<h1/>Observer</h1>

O padrão Observer é escolhido para resolver o problema de comunicação entre objetos em um cenário onde há uma dependência de um para muitos entre objetos. No caso específico do aplicativo de previsão do tempo, o padrão Observer permite que diversos widgets de exibição sejam automaticamente atualizados sempre que houver uma mudança significativa nas condições climáticas, sem que o sujeito (WeatherStation) tenha conhecimento direto dos observadores (os widgets).

O problema principal que o padrão Observer resolve é o desacoplamento entre o sujeito e os observadores. Isso significa que o sujeito (WeatherStation) não precisa conhecer os detalhes de implementação dos observadores (os widgets), e vice-versa. Isso promove uma maior flexibilidade e extensibilidade no sistema, pois novos observadores podem ser facilmente adicionados sem modificar o sujeito, e vice-versa.

A solução proposta organiza o sistema de forma que o sujeito (WeatherStation) seja responsável por armazenar as condições climáticas e notificar os observadores (os widgets) quando ocorrerem mudanças significativas. Os observadores implementam uma interface comum (Observer) que define o método update(), que é chamado pelo sujeito quando ocorre uma mudança. Isso permite que cada observador reaja de maneira apropriada às mudanças nas condições climáticas, atualizando suas exibições conforme necessário.

Portanto, o padrão Observer resolve o problema de comunicação e dependência entre objetos em um cenário onde há um relacionamento um-para-muitos, promovendo um design mais flexível, extensível e desacoplado.

![observer drawio](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/69d419c9-e5d6-4e2a-9aad-dd67a73613e3)


Subject é uma interface que define os métodos para anexar, desanexar e notificar observadores.

Observer é uma interface que define o método update() que será implementado pelos observadores concretos.

ConcreteSubject é a classe concreta que mantém o estado e notifica os observadores.

ConcreteObserver é a classe concreta que implementa o método update() para reagir às notificações do sujeito.

TemperatureWidget, HumidityWidget e SkyConditionsWidget são os observadores concretos que reagem às mudanças nas condições climáticas.

<h1/>Código explicado:</h1>

São definidas duas interfaces: Observer e Subject. A interface Observer define o método update() que será implementado pelos observadores concretos. A interface Subject define os métodos attach(), detach() e notify() que serão implementados pela classe sujeito concreta (WeatherStation).

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/69ee58a9-8b66-4237-ae43-718307012b76)

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/e3eaef81-bc2b-4897-899a-9e20827ac0d9)


A classe concreta WeatherStation que implementa a interface Subject. Ela mantém o estado das condições climáticas (temperatura, umidade e condições do céu), mantém uma lista de observadores registrados e implementa os métodos attach(), detach() e notify() para gerenciar os observadores.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/2095258c-b604-479f-ae33-db054e308889)


As classes concretas dos observadores: TemperatureWidget, HumidityWidget e SkyConditionsWidget. Cada uma delas implementa a interface Observer e tem um ponteiro para a instância da classe WeatherStation para acessar as condições climáticas.

Os métodos das classes WeatherStation (ConcreteSubject) e dos observadores concretos (TemperatureWidget, HumidityWidget e SkyConditionsWidget): Esses métodos incluem a lógica para anexar/desanexar observadores, notificar os observadores sobre mudanças nas condições climáticas e reagir a essas mudanças.


![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/dc1e168a-b112-444e-b75e-6e1141bdbd66)

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/0524f291-e538-4d60-bd18-9b85d8f43d57)

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/96f88356-6b61-4b14-869d-955e627494ce)


Na função main(), criamos uma instância de WeatherStation e instâncias dos widgets de exibição (TemperatureWidget, HumidityWidget e SkyConditionsWidget). Eles são registrados na WeatherStation para receber notificações sobre mudanças nas condições climáticas. Em seguida, simulamos mudanças nas condições climáticas chamando setWeather() e observamos como os widgets de exibição reagem a essas mudanças. O widget de umidade é removido e a mudança nas condições climáticas é novamente simulada para demonstrar a remoção bem-sucedida de um observador.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/e5ddd37c-b646-4622-85ba-9a5ca68240b9)
