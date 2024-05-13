<h1/>Factory Method</h1>

O padrão Factory Method é um padrão de design criacional que tem como objetivo fornecer uma interface para criar objetos em uma superclasse, mas permite que subclasses alterem o tipo de objetos que serão criados. Ele resolve o problema de criar objetos sem especificar explicitamente suas classes concretas, proporcionando flexibilidade na criação de diferentes tipos de objetos sem modificar o código cliente.

No exemplo fornecido, o problema é a criação de diferentes tipos de edifícios (Residências e Comércios) em um jogo de simulação de cidade. O padrão Factory Method resolve esse problema encapsulando a lógica de criação de objetos em subclasses (ResidenceCreator e CommerceCreator), enquanto mantém uma interface comum (BuildingCreator) para criar esses objetos.

A solução consiste em definir uma interface (BuildingCreator) com um método de fábrica (createBuilding) que retorna um objeto do tipo Building (interface para os tipos concretos de edifícios). As subclasses concretas (ResidenceCreator e CommerceCreator) implementam esse método de fábrica para criar instâncias específicas de edifícios (Residence e Commerce). Isso permite que o cliente (o código que cria os edifícios) use a interface comum para criar diferentes tipos de edifícios, sem precisar conhecer as classes concretas.

Portanto, o padrão Factory Method neste contexto oferece flexibilidade e extensibilidade na criação de diferentes tipos de edifícios em um jogo de simulação de cidade, permitindo adicionar novos tipos de edifícios no futuro sem modificar o código existente.

![metod drawio](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/6a3f1511-f8fc-45fc-ba44-0a3b0fe2bbbe)


Client: O código cliente que interage com o padrão Factory Method.

Building: A interface comum para os produtos criados pelo Factory Method.

Residence e Commerce: As classes concretas que implementam a interface Building.

BuildingCreator: A classe abstrata que define o método de fábrica para criar objetos Building.

ResidenceCreator e CommerceCreator: As subclasses concretas que implementam o método de fábrica para criar instâncias específicas de Residence e Commerce, respectivamente.

<h2/>Código explicado:</h2>

Classe Abstrata Building: Esta classe é uma interface que define métodos virtuais puros (getType e displayInfo) que serão implementados pelas subclasses. Ela representa o tipo comum de todos os edifícios.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/dc172464-bfde-427b-be54-b8bc8b189273)


Classes Concretas Residence e Commerce: Essas classes são implementações concretas da interface Building. Cada uma implementa os métodos virtuais puros da classe base de acordo com suas características específicas. Residence representa um edifício residencial, enquanto Commerce representa um edifício comercial.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/0310687a-8880-4043-9bb7-4ddf558c8c86)

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/f145c827-042c-453e-a9ec-0c9dc8cb6b77)


Classe Abstrata BuildingCreator: Esta é a classe abstrata que define o método de fábrica (createBuilding) para criar instâncias de Building. Ela também contém um método (someOperation) que demonstra como o método de fábrica pode ser usado.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/3f530fb7-4f22-40ff-bec7-bdff21f1a899)


Classes Concretas ResidenceCreator e CommerceCreator: Essas são as subclasses concretas de BuildingCreator. Cada uma implementa o método de fábrica (createBuilding) para criar instâncias específicas de Residence e Commerce, respectivamente.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/a85b40ce-a37f-42c9-b7d6-d8226318d842)


Função main: O ponto de entrada do programa. Aqui, são demonstrados dois cenários: a criação de um edifício residencial e a criação de um edifício comercial. Para cada cenário, é criada uma instância do respectivo criador (ResidenceCreator ou CommerceCreator) e é chamado o método someOperation, que demonstra a criação do edifício específico.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/d793a5f3-ec29-4678-8d0c-ea5190fcf9d3)
