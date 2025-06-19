package Telas;

import javax.swing.*;
import java.awt.*;

public class SwingUtils {
    public static JButton criarBotaoEstilizado(String texto) {
        return criarBotaoEstilizado(texto, new Color(0, 120, 215), Color.WHITE);
    }

    public static JButton criarBotaoEstilizado(String texto, Color corFundo, Color corTexto) {
        JButton botao = new JButton(texto);
        botao.setFocusPainted(false);
        botao.setBackground(corFundo);
        botao.setForeground(corTexto);
        botao.setFont(new Font("Arial", Font.BOLD, 14));
        botao.setPreferredSize(new Dimension(200, 40));
        botao.setMaximumSize(new Dimension(200, 40));
        botao.setBorder(BorderFactory.createEmptyBorder(5, 15, 5, 15));
        return botao;
    }

    public static JLabel criarLabelTitulo(String texto) {
        JLabel label = new JLabel(texto);
        label.setFont(new Font("Arial", Font.BOLD, 18));
        label.setAlignmentX(Component.CENTER_ALIGNMENT);
        return label;
    }

    public static JPanel criarPainelPrincipal() {
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        return panel;
    }
}