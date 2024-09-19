# Exercício 1. Crie os seguintes vetores:
# (a) (10, 11, 12,…, 30)
vetorA <- 10:30

# (b) (30, 29, 28,…, 10)
vetorB <- 30:10

# (c) (10, 11, 12,…, 30, 29, 28,…, 10)
vetorC <- c(vetorA, vetorB)

# Exercício 2. Use a função help do R para descobrir o funcionamento das funções rep e seq. Em seguida, utilize estas funções para resolver os seguintes itens:

# (a) Crie o vetor (2, 4, 6, 8, 2, 4, 6, 8,…, 2, 4, 6, 8), em que há dez ocorrências do número 2.
vetorOcorrencia2 <- rep(seq(2, 8, length.out = 4), 10)

# (b) Crie o vetor (2, 4, 6, 8, 2, 4, 6, 8,…, 2, 4, 6, 8, 2), em que há onze ocorrências do número 2 e dez ocorrências dos números 4, 6 e 8.
vetorOcorrencia3 <- c(rep(seq(2, 8, by = 2), 10), 2)

#Exercício 4. Numa urna há bolas idênticas numeradas de 1 até 100. Serão extraídas 40 bolas com reposição desta urna. Simule este experimento e guarde o resultado dos sorteios em um vetor.

resultadoSorteio <- sample(1:100, size = 40, replace = TRUE)

# (a) Quantas bolas pares foram sorteadas?
QuantidadePares <- sum(resultadoSorteio%%2==0)

# (b) Quantas bolas maiores do que 70 foram sorteadas?
QuantidadeMaior70 <- sum(resultadoSorteio>70)

# (c) Em quais retiradas (posições) foram sorteadas as bolas ímpares?
posicoesimpares <- which(resultadoSorteio%%2!=0)

#Exercício 5. Crie um função no R que irá simular sucessivos lançamentos de um dado até que o número 4 seja obtido pela segunda vez. A função deverá retornar o número de lançamentos que foram necessários até o 4 ser obtido pela segunda vez. Assim, se os sorteios foram 3, 6, 6, 5, 4, 2, 4 a função deverá retornar 7.

quatroPelaSegundaVez <- function(){
  lancamentos <- c()
  repeat{
    dado <- c(sample(x = 1:6, size = 1, replace = TRUE))
    lancamentos <- c(lancamentos, dado)
    
    if(sum(c(lancamentos == 4 )) > 1)
      break
  }
  return(length(lancamentos))
}

quatroPelaSegundaVez()

#Exercício 6. Utilize a função do exercício anterior para replicar o experimento dez mil vezes. Para cada replicação, guarde o número de lançamentos num vetor chamado quantidades. Por fim, calcule a média de quantidades. Interprete o resultado obtido.

mediaPelaSegundaVez <- replicate(10000, quatroPelaSegundaVez())
mean(mediaPelaSegundaVez)

#Exercício 8. Michael Scott é gerente regional da empresa Dunder Mufflin. Para as festividades de fim de ano, Michael propôs aos funcionários Dwight Schrute, Jim Halpert, Kevin Malone e Creed Bratton a realização de um amigo oculto entre eles. Consideraremos que o sorteio do amigo oculto deu errado quando uma pessoa sortear ela mesma (Michael tira Michael, por exemplo). Simule o sorteio do amigo oculto. Se ele deu certo, atribua o valor 1; caso contrário, atribua o valor 0 (zero). Em seguida, replique este experimento cem mil vezes e calcule a proporção de vezes que o amigo oculto deu errado.

AmigoOculto <- function(nomes) {
  repeat {
    # Embaralha os nomes aleatoriamente
    sorteio <- sample(nomes)
    
    # Verifica se alguém se sorteou a si mesmo ou seja compara cada elemento do vetor sorteio com o vetor nomes
    if (!any(sorteio == nomes)) {
      return(TRUE)  # Sorteio válido
    }
  }
}

# Nomes
nomes <- c("Dwight Schrute", "Jim Halpert", "Kevin Malone", "Creed Bratton")

# Executa a função 100.000 vezes
resultados <- replicate(100000, AmigoOculto(nomes))

# Verifica a proporção de sorteios válidos
proporcao <- mean(resultados)
print(proporcao)

#Exercício 10. Luke Skywalker realizará o seguinte passeio aleatório na reta: a reta do passeio é formada pelos números inteiros de zero até 𝑁; Luke está em um ponto 𝐿 que é maior do que zero e menor do que 𝑁;Luke lança uma moeda honesta; se sair coroa, ele dá um passo para a esquerda (e termina na posição 𝐿 − 1 da reta); se sair cara, ele dá um passo para a direita (e termina na posição 𝐿 + 1 da reta). Luke continuará a lançar a moeda e se deslocará até que ele chegue em sua casa (e lá ele vai dormir e o passeio acaba) ou até que ele chegue (caia) no precipício (e, óbvio, o passeio também acaba nesse caso).


#(a) Para 𝑁 = 20, crie uma função cuja entrada seja 𝐿 (um número maior do que zero e menor do que 20) e que retorne 1 se Luke terminou um passeio em sua casa ou retorne zero se Luke caiu no precipício.

Passeio <- function(Ponto_L){
    
    while (TRUE) {  # Continua enquanto Ponto_L for maior que 0
      if(Ponto_L == 20){
        return(1) #Luke concluio o passeio
      }
      if(Ponto_L == 0){
        return(0) #Luke caio no precipício
      }
      resultado_caracoroa <- sample(c(0, 1), 1)  # 0 para cara, 1 para coroa
      if (resultado_caracoroa == 0) {
        Ponto_L <- Ponto_L + 1
      } else {
        Ponto_L <- Ponto_L - 1
      }
    }
    
    return(Ponto_L)
  }
  
  # Executa a função 10 vez
  resultado <- replicate(10, Passeio(10)) #Pode ser substituido por qualquer valor
  print(resultado)

#(b) Crie uma função cuja entrada seja 𝐿; esta função deverá replicar o passeio da letra (a) 10 mil vezes e retornar a proporção de vezes que Luke chegou em sua casa. Sugestão: crie um vetor que, para cada replicação, guardará o resultado de um passeio; cada entrada deste vetor será zero ou 1; zero se Luke caiu no precipício e 1 se Luke chegou em casa.
  
  # Executa a função 10000 vez
  resultado <- replicate(10000, Passeio(10))
  mean(resultado) # Já considera 1 como os valores verdadeiro e faz a proporção em cima deles

#(c) Use a função criada em (b) para 𝐿 = 1, 2, … , 19 e, em seguida, use esses valores para plotar um gráfico de 𝑥 = 1 ∶ 19 por 𝑦, em que 𝑦 são as proporções retornadas pela função criada em (b) para cada 𝑥.
  
  # Vetor para armazenar os resultados das proporções
  resultados_proporcao <- numeric(19)
  
  # Loop para calcular as proporções para cada valor de L de 1 a 19
  for (i in 1:19) {
    resultados <- replicate(10000, Passeio(i))
    proporcao <- mean(resultados)
    resultados_proporcao[i] <- proporcao
  }
  
  # Criar um data frame para usar no ggplot
  df_resultados <- data.frame(L = 1:19, Proporcao = resultados_proporcao)
  
  # Carregar a biblioteca ggplot2 se ainda não estiver carregada
  library(ggplot2)
  
  # Plotar o gráfico de barras das proporções
  ggplot(data = df_resultados, aes(x = as.factor(L), y = Proporcao)) +
    geom_bar(stat = "identity", fill = "#5B99C2") +
    labs(x = "L", y = "Proporção Média") +
    theme_minimal()
  
  
  
# Exercício 12. Considere o seguinte jogo: Steven e Garnit escolherão, cada um, uma sequência de tamanho 3 em que cada entrada da sequência é cara ou coroa; logo em seguida, uma moeda será lançada três vezes; se aparecer a sequência de um dos jogadores, este jogador vence e o jogo acaba; caso não apareça a sequência de nenhum deles, a moeda é lançada pela quarta vez e os três últimos lançamentos são analisados; se nestes três últimos lançamentos aparecer a sequência de um dos jogadores, este jogador vence e o jogo acaba. Se isto não acontecer, a moeda é lançada pela quinta vez e os três últimos resultados são analisados; se aparecer a sequência de um dos jogadores, este jogador vence e o jogo acaba. Este processo é realizado até que apareça a sequência que um dos dois escolheu; se aparecer primeiro a sequência de Steven, ele ganha; se aparecer primeiro a sequência de Garnit, ela vence. Convencione que cara seja 1 e que coroa seja zero. Supondo que Steven escolheu a sequência (0, 1, 0) e que Garnit escolheu a sequência (0, 0, 1), simule uma partida deste jogo. A simulação deve retornar steven caso Steven tenha vencido ou deve retornar garnit caso contrário. Replique o experimento 10 mil vezes e calcule a média de vitórias de Garnit. Comente o resultado obtido. (6 pontos)

# Observação: Suponha que os três primeiros lançamentos foram (1,0,0). Logo, ninguém ganhou e a moeda é lançada pela quarta vez. Suponha que o quarto lançamento foi 0; logo os três últimos lançamentos foram (0,0,0) e ninguém ganhou. Na quinta vez saiu 1 e, portanto, os três últimos lançamentos foram (0,0,1) e o jogo acaba com vitória de Garnit. As sequências (0, 1, 0), (1, 0, 1, 0) e (1, 1, 0, 1, 0) fazem Steven vitorioso; as sequências (0, 0, 1), (0, 0, 0, 1) e (1, 0, 0, 0, 1) fazem Garnit vitoriosa.

JogoCaraCoroa <- function(){
    
  sequenciaSteven <- c(0,1,0)
  sequenciaGarnit <- c(0,0,1)
  sequenciaCaraCoroa <- sample(c(1,0), size = 3, replace = TRUE)
  i <- 1
  
  while(TRUE){
      if(all(sequenciaSteven == sequenciaCaraCoroa)){
        return("steven")
      }
      if(all(sequenciaGarnit == sequenciaCaraCoroa)){
      return("garnit")
      }
    sequenciaCaraCoroa <- sequenciaCaraCoroa[-i] # Tirando valor mais desatualizado
    sequenciaCaraCoroa <- c(sequenciaCaraCoroa, sample(c(1,0), size = 1))
  }
  
}

resultadoCaraCoroa <- JogoCaraCoroa()
JOGOSCaraCoroa <- replicate(10000, JogoCaraCoroa())
mediavitoriaGarnit <- mean(JOGOSCaraCoroa == "garnit")

#Exercício 14. Os bonobos, também conhecidos como chimpanzés-pigmeus, são encontrados apenas em uma área limitada da República Democrática do Congo, na África Central. Eles são conhecidos por sua sociedade matriarcal, onde as fêmeas têm um papel dominante na tomada de decisões e na resolução de conflitos. Os bonobos são geralmente mais pacíficos do que os chimpanzés, e os conflitos dentro do grupo são frequentemente resolvidos através de interações sociais, como a partilha de alimentos e o sexo. Eles são altamente sociais e valorizam as relações e o contato físico com outros membros do grupo. Por outro lado, os chimpanzés têm uma distribuição mais ampla, encontrados em várias regiões da África Central e Ocidental. Eles têm uma sociedade mais hierárquica e dominada por machos, onde o poder é frequentemente obtido por meio de competição e agressão. Os chimpanzés também exibem comportamentos violentos e podem entrar em confrontos territoriais com outros grupos. Eles são conhecidos por usar ferramentas, como galhos para pescar cupins e pedras para quebrar nozes. O conjunto primatas.txt apresenta informações sobre tamanho (centímetros), peso (libras) e gênero de bonobos e de chimpanzés. Abra o arquivo e veja como ele está organizado.


# (a) Importe o arquivo para o ambiente do R. Conheça sua estrutura e peça um resumo dos dados com alguma função. (1 ponto) 

Primatas <- read.table(file = "C:\\Users\\felip\\OneDrive\\Desktop\\Facul\\UFU\\4º Período\\Estatística Computacional\\Lista 1\\primatas.txt", sep = ":", header = TRUE)

str(Primatas)
summary(Primatas)

# (b) Construa um gráfico de barras contando quantas espécies de bonobos e chimpanzés há no conjunto. Construa também um gráfico de barras mostrando a frequência de machos e fêmeas de cada espécie. (4 pontos)

ggplot(data = Primatas, aes(x = especie, fill = genero))+
  geom_bar()+
  theme_minimal()

# (c) Construa um gráfico para comparar as fêmeas e os machos dos bonobos. Em seguida, construa, também, um gráfico para comparar as fêmeas e os machos dos chimpanzés. (4 pontos).

ggplot(Primatas, aes(x = altura, y = peso, color = genero)) +
  geom_point(size = 3) +  # Pontos para cada observação
  facet_wrap(~especie) +  # Facetas para separar Bonobos e Chimpanzés
  labs(title = "Comparação entre Gênero, Altura e Peso dos Bonobos e Chimpanzés",
       x = "Altura (cm)", y = "Peso (kg)", color = "Gênero") +
  theme_minimal()

# (d) Construa um gráfico para comparar as fêmeas dos bonobos e dos chimpanzés. Em seguida, construa também um gráfico para comparar os machos dos bonobos e dos chimpanzés. (4 pontos)

femeas <- Primatas[Primatas$genero == "femea",]

ggplot(femeas, aes(x = altura, y = peso, color = especie)) +
  geom_point(size = 3) +
  geom_point() +  
  labs(title = "Fêmeas")+
  theme_minimal()  

machos <- Primatas[Primatas$genero == "macho",]

ggplot(machos, aes(x = altura, y = peso, color = especie)) +
  geom_point(size = 3) +
  geom_point() +  
  labs(title = "Machos")+
  theme_minimal() 

# (e) A partir das análises dos itens anteriores, escreva um pequeno texto contendo informações sobre os bonobos e os chimpanzés, como exemplo: diferenças entre os gêneros de cada espécie e diferenças entre as espécies. (5 pontos)

  #R: Foi apresentado dados aproximados de 1000 macacos, tendo em média 500 bonobos e 500 chimpazes, sendo eles em média 250 fêmeas e 250 machos cada. É pssível perceber que os Bonobos em relação aos chipamzés são menores, porém os bonobos machos em comparação com as fêmeas dos chipamzés tem dados de peso/altura parecidos. É possível perceber também que dentre os bonobos e chipamzés os machos são predominantemente maiores que as fêmeas em relação a peso/altura.

# (f) A partir das variáveis tamanho, peso e genero, construa um modelo de árvore de decisão utilizando estruturas condicionais que seja capaz de prever a espécie de uma observação. Calcule a acurácia do modelo.(10 pontos)

Primatas <- Primatas[sample(nrow(Primatas)), ]

n <- round(0.8*nrow(Primatas))

treinamento <- Primatas[1:n,]

teste <- Primatas[-(1:n),]

resultados <- c() #vetor para armazenar as previsões do modelo

for (i in 1:nrow(teste)) {
     if (teste$peso[i] > 52) {
         resultados[i] <- "chimpanze"
       } else if (teste$peso[i] >= 39 & teste$altura[i] >= 128) {
           resultados[i] <- "bonobo"
         } else if (teste$peso[i] >= 39 & teste$altura[i] < 128) {
             resultados[i] <- "chimpanze"
           } else if (teste$peso[i] < 39) {
               resultados[i] <- "bonobo"
             }
   }

  
mean(teste$especie == resultados) #acurácia do modelo
  

ggplot(Primatas, aes(x = altura, y = peso, color = especie)) +
  geom_point(size = 2) +
  scale_y_continuous(name = "Peso", breaks = seq(10, 200, by = 10)) +  # Define os rótulos do eixo y
  theme_dark()
  
  
