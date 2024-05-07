import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))
import System.Random (randomRIO)
import System.IO

-- Função para exibir o ranking
exibirRanking :: IO () 
exibirRanking = do
    conteudo <- readFile "highscore.txt"
    putStrLn conteudo

clearConsole :: IO () --Função para limpar o console
clearConsole = putStr "\ESC[2J"

adivinhaGame :: Int -> Int -> IO Int
adivinhaGame numAleatorio tentativas = do
    putStr "Digite um número para ser adivinhado: "
    tentativa <- readLn :: IO Int -- Lê diretamente para inteiro
    print numAleatorio

    if tentativa < numAleatorio
        then do
            putStrLn "Número está acima!"
            adivinhaGame numAleatorio (tentativas + 1)
        else if tentativa > numAleatorio
            then do
                putStrLn "Número está abaixo!"
                adivinhaGame numAleatorio (tentativas + 1)
            else
                return tentativas

jogo :: IO ()  -- Função para chamada recursiva até que o jogador não deseje mais jogar.
jogo = do
    recordeString <- readFile "highscore.txt"
    let recorde = read recordeString :: Int
    hSetBuffering stdout NoBuffering
    numAleatorio <- randomRIO (1, 100) :: IO Int
    tentativas <- adivinhaGame numAleatorio 1
    putStrLn "Parabéns, você acertou!"
    putStrLn ("Número de tentativas: " ++ show tentativas)
    if tentativas < recorde
        then do
            putStrLn "Parabéns você bateu o recorde!"
            writeFile "highscore.txt" (show tentativas)
        else putStrLn "Não foi o recorde!"
    
    putStrLn "Deseja jogar novamente? ('s' para sim e qualquer outra coisa para não)"
    resposta <- getLine --Uso do getLine em vez de getChar pois está dando erro
    if resposta == "s"
        then jogo  -- Passa o nome para a chamada recursiva
        else main

main :: IO ()
main = do
    clearConsole
    putStrLn "1 - Jogar"
    putStrLn "2 - Ranking"
    putStrLn "3 - Sair"
    putStr "Insira a operação: "
    op <- readLn

    case op of
        1 -> jogo
        2 -> exibirRanking
        3 -> putStrLn "Saindo..."
        _ -> putStrLn "Opção inválida"