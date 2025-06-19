package Ferramentas;

import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.DocumentFilter;
import javax.swing.text.PlainDocument;

// Classe para limitar o número de caracteres nos campos de texto
public class LimitadorDeCaracteres extends PlainDocument {
    private int limite;

    public LimitadorDeCaracteres(int limite) {
        super();
        this.limite = limite;
    }

    @Override
    public void insertString(int offset, String str, AttributeSet attr) throws BadLocationException {
        if (str == null) return;

        if ((getLength() + str.length()) <= limite) {
            super.insertString(offset, str, attr);
        }
    }
}