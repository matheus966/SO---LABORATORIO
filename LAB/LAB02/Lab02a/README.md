## Exercicios
1- Quando vários processos são executados concorrentemente, a ordem em que eles terminam não é garantida. Isso significa que, mesmo que os processos sejam criados em uma determinada ordem, não podemos prever a ordem em que suas mensagens serão impressas no stderr. Assim, as mensagens podem aparecer em ordens diferentes em execuções diferentes do programa.


2- A principal diferença é que as mensagens seriam impressas como parte do fluxo de saída padrão do programa, em vez de serem tratadas como mensagens de erro e enviadas para o fluxo de erro padrão (stderr). Isso significa que as mensagens seriam exibidas no terminal ou no local para onde a saída padrão estiver redirecionada, em vez de serem tratadas como saída de erro.
