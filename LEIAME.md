# Note App C

Este é um aplicativo simples de anotações escrito em C. Permite criar, visualizar, atualizar e remover notas, armazenando tudo em memória durante a execução.

## Funcionalidades
- Adicionar uma nova nota
- Listar todas as notas
- Atualizar uma nota existente
- Remover uma nota
- Ordenação automática das notas por título

## Como Usar
1. Compile o programa:
   
   ```sh
   gcc -o main.exe main.c
   ```

2. Execute o programa:
   
   ```sh
   ./main.exe
   ```

3. Siga o menu interativo para gerenciar suas notas.

## Estrutura do Projeto
- `main.c`: Código-fonte principal do aplicativo.
- `build/`, `output/`: Pastas de saída de build.

## Observações
- As notas não são salvas em arquivo, apenas em memória.
- Limite de 100 notas.

---
Desenvolvido para fins educacionais.
