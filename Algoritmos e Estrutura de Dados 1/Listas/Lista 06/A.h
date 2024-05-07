struct String {
    char* data;
    int length;
};

struct String* criarString();
void AssociarString(struct String *str, const char *valor);
void RetornarTamanho(struct String *str);
void ContagemOcorrencia(struct String *str, const char caracter);
void ExibirString(struct String *str);