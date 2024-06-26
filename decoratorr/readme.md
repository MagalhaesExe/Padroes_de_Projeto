<h1/>Decorator</h1>

O padrão Decorator é utilizado para adicionar comportamentos adicionais a objetos de forma dinâmica, sem precisar alterar sua estrutura. Ele é útil quando se deseja adicionar responsabilidades a objetos individualmente, de forma flexível e combinável, sem criar subclasses excessivas para cada combinação possível de comportamentos.

No contexto do sistema de gerenciamento de texto apresentado, o padrão Decorator resolve o problema de adicionar filtros de forma flexível e combinada aos textos. Ele permite que novos filtros sejam adicionados sem modificar as classes existentes, seguindo o princípio do Open/Closed do SOLID.

Por exemplo, se você quiser adicionar novos filtros como itálico, sublinhado, ou qualquer outra formatação, basta criar novas classes decoradoras para esses filtros, sem precisar modificar as classes existentes. Além disso, você pode combinar múltiplos filtros de forma dinâmica, aplicando diferentes transformações ao texto conforme necessário, sem que o cliente precise se preocupar com a complexidade da implementação.

Em resumo, o padrão Decorator oferece uma solução flexível e extensível para adicionar responsabilidades adicionais aos objetos, permitindo a composição de comportamentos de forma dinâmica e sem a necessidade de modificar as classes existentes.

![decorator drawio](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/ee9e43df-a4ce-4668-bf0d-4c8bc286ddd0)


TextFilter: Define a interface base para todos os filtros de texto. Ele contém um método apply que deve ser implementado por todas as classes concretas que representam filtros de texto.

PlainText: Implementa a interface TextFilter. É uma classe concreta que representa o texto original sem alterações.

TextDecorator: É a classe base para todos os decoradores. Mantém uma referência para um objeto do tipo TextFilter (componente) e implementa a interface TextFilter.

UppercaseDecorator: É um decorador concreto que adiciona a funcionalidade de transformar o texto para maiúsculas.

BoldDecorator: É um decorador concreto que adiciona a funcionalidade de envolver o texto em tags HTML de negrito.

<h2/>Código explicado:</h2>

Interface Componente (TextFilter): Define a interface base para todos os filtros de texto. Ela contém um método virtual puro apply, que é responsável por aplicar o filtro ao texto.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/2f657e1a-e344-40fc-90b2-c4dac2804298)


Componente Concreto (PlainText): Implementa a interface TextFilter e representa a implementação concreta básica do filtro de texto. No caso, o método apply retorna o texto sem nenhuma alteração.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/18bb97be-bb20-4bad-8986-37fd676403b1)


Classe Decorator (TextDecorator): Esta classe abstrata implementa a interface TextFilter e mantém uma referência para um objeto do tipo TextFilter, que é o componente que será decorado. O método apply é implementado de forma a chamar o método apply do componente interno.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/81fbad55-cad3-4413-b9c1-83d154687d64)


Decorador Concreto (UppercaseDecorator e BoldDecorator): São implementações concretas de decoradores que aplicam transformações específicas ao texto. Eles herdam da classe TextDecorator e sobrescrevem o método apply para adicionar o comportamento desejado ao texto.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/2836e542-c025-4d81-9962-7c52d3da220b)

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/8506784b-1329-4059-9fac-757ee6015430)


Função main: No main, são criados objetos dos diferentes filtros. Primeiro, um objeto PlainText é criado para representar o texto original. Em seguida, é criado um decorador UppercaseDecorator, que recebe o objeto PlainText como parâmetro. Isso resulta em um texto em maiúsculas. Por fim, é criado um decorador BoldDecorator, que recebe o decorador UppercaseDecorator como parâmetro, resultando em um texto em maiúsculas e em negrito.

![image](https://github.com/MagalhaesExe/Padroes_de_Projeto/assets/125324885/4909972a-1e74-4a51-b5d5-999d3ef3a505)
