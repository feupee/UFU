-- Definição do tipo de dados Student
type Student = (Int, String, String, Int)

-- Banco de dados inicial de estudantes
initialDatabase :: [Student]
initialDatabase = []

-- Adicionar estudante à base de dados
addStudent :: [Student] -> Student -> [Student]
addStudent db student = student : db

-- Filtrar estudantes por ID
findStudentById :: [Student] -> Int -> Maybe Student
findStudentById db id = case filter (\(studentId, _, _, _) -> studentId == id) db of
                          [] -> Nothing
                          (x:_) -> Just x

-- Atualizar informações do estudante por ID
updateStudentById :: [Student] -> Int -> Student -> [Student]
updateStudentById db id updatedStudent = map (\(studentId, firstName, lastName, age) ->
                                            if studentId == id
                                            then updatedStudent
                                            else (studentId, firstName, lastName, age)) db

-- Função para imprimir detalhes do estudante
printStudentDetails :: Maybe Student -> IO ()
printStudentDetails Nothing = putStrLn "Estudante não encontrado."
printStudentDetails (Just (id, firstName, lastName, age)) =
  putStrLn $ "ID: " ++ show id ++ "\nNome: " ++ firstName ++ "\nSobrenome: " ++ lastName ++ "\nIdade: " ++ show age

-- Função do menu
menu :: [Student] -> IO ()
menu db = do
  putStrLn "Selecione uma opção:"
  putStrLn "1. Adicionar estudante"
  putStrLn "2. Recuperar estudante por ID"
  putStrLn "3. Atualizar informações do estudante"
  putStrLn "4. Sair"
  option <- getLine
  case option of
    "1" -> do
      putStrLn "Digite o ID do estudante:"
      idStr <- getLine
      putStrLn "Digite o primeiro nome do estudante:"
      firstName <- getLine
      putStrLn "Digite o sobrenome do estudante:"
      lastName <- getLine
      putStrLn "Digite a idade do estudante:"
      ageStr <- getLine
      let id = read idStr :: Int
          age = read ageStr :: Int
          newStudent = (id, firstName, lastName, age)
          updatedDb = addStudent db newStudent
      putStrLn "Estudante adicionado com sucesso!"
      menu updatedDb
    "2" -> do
      putStrLn "Digite o ID do estudante que deseja recuperar:"
      idStr <- getLine
      let id = read idStr :: Int
          student = findStudentById db id
      printStudentDetails student
      menu db
    "3" -> do
      putStrLn "Digite o ID do estudante que deseja atualizar:"
      idStr <- getLine
      let id = read idStr :: Int
      case findStudentById db id of
        Nothing -> do
          putStrLn "Estudante não encontrado."
          menu db
        Just (_, firstName, lastName, age) -> do
          putStrLn "Digite o novo primeiro nome do estudante:"
          newFirstName <- getLine
          putStrLn "Digite o novo sobrenome do estudante:"
          newLastName <- getLine
          putStrLn "Digite a nova idade do estudante:"
          newAgeStr <- getLine
          let newAge = read newAgeStr :: Int
              updatedStudent = (id, newFirstName, newLastName, newAge)
              updatedDb = updateStudentById db id updatedStudent
          putStrLn "Informações do estudante atualizadas com sucesso!"
          menu updatedDb
    "4" -> putStrLn "Saindo do programa..."
    _ -> do
      putStrLn "Opção inválida! Tente novamente."
      menu db

-- Função principal
main :: IO ()
main = do
  putStrLn "Bem-vindo ao sistema de gerenciamento de estudantes!"
  menu initialDatabase