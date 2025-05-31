# Note App C

Este é um aplicativo simples de anotações feito em linguagem C. Ele permite criar, visualizar, atualizar e remover notas, armazenando tudo em memória durante a execução.

## Funcionalidades
- Adicionar uma nova nota
- Listar todas as notas
- Atualizar uma nota existente
- Remover uma nota
- Ordenação automática das notas por título

## Como usar
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
- `build/`, `output/`: Pastas de saída de compilação.

## Observações
- As notas não são salvas em arquivo, apenas em memória.
- Limite de 100 notas.

---
Desenvolvido para fins didáticos.
